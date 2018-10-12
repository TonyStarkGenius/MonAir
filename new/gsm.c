#include "gsm.h"

volatile char TCP_CONNECT_FLAG=1;

void Parse_GSM_Data(char* RX_BUF)
{
	if(RX_BUF[RXGSMe-4]=='O'&&RX_BUF[RXGSMe-3]=='K')
	{
		RXGSM_OK_FLAG=1;
		if(RX_BUF[RXGSMe-7]=='C'&&RX_BUF[RXGSMe-6]=='T')
			TCP_CONNECT_FLAG=1;
	}
}

void USART_Connection(void)
{
	char GSM_USART_Error=1;
	My_USART_Send_StrRN("AT",USART_GSM);
	Error_Trap(GSM_USART_Error);
}

void PIN_Status(void)
{
	char GSM_PIN_Error=2;
	My_USART_Send_StrRN("AT+CPIN?",USART_GSM);
	Error_Trap(GSM_PIN_Error);
}

void Signal_Status(void)
{
	char GSM_Signal_Error=3;
	My_USART_Send_StrRN("AT+CSQ",USART_GSM);
	Error_Trap(GSM_Signal_Error);
}

void Regisration_Status(void)
{
	char GSM_Registration_Error=4;
	My_USART_Send_StrRN("AT+CREG?",USART_GSM);
	Error_Trap(GSM_Registration_Error);
}

void GPRS_Status(void)
{
	char GSM_GPRS_Error=5;
	My_USART_Send_StrRN("AT+CGATT?",USART_GSM);
	Error_Trap(GSM_GPRS_Error);
}

void Shut_Connections(void)
{
	char GSM_SHUT_Error=6;
	My_USART_Send_StrRN("AT+CIPSHUT",USART_GSM);
	Error_Trap(GSM_SHUT_Error);
}

void Set_One_Server(void)
{
	char GSM_Server_Error=7;
	My_USART_Send_StrRN("AT+CIPMUX=0",USART_GSM);
	Error_Trap(GSM_Server_Error);
}

void APN_Connection(char* apn,char* uname,char* pwd)
{
	char GSM_APN_Error=8;
	My_USART_Send_Str("AT+CSTT=\"",USART_GSM);
	My_USART_Send_Str(apn,USART_GSM);
	My_USART_Send_Str("\"",USART_GSM);
	if(strncmp(uname,"\0",1))
	{
		My_USART_Send_Str(",\"",USART_GSM);
		My_USART_Send_Str(uname,USART_GSM);
		My_USART_Send_Str("\",\"",USART_GSM);
		My_USART_Send_Str(pwd,USART_GSM);
		My_USART_Send_StrRN("\"",USART_GSM);
	}else
		My_USART_Send_StrRN("",USART_GSM);
	Error_Trap(GSM_APN_Error);
}

void GPRS_UP(void)
{
	char GSM_GPRSUP_Error=9;
	My_USART_Send_StrRN("AT+CIICR",USART_GSM);
	Error_Trap(GSM_GPRSUP_Error);
}

void TCP_Start(char* ip,char* port)
{
	TCP_CONNECT_FLAG=0;
	char GSM_TCP_Start_Error=17;
	My_USART_Send_Str("AT+CIPSTART=\"TCP\",\"",USART_GSM);
	My_USART_Send_Str(ip,USART_GSM);
	My_USART_Send_Str("\",\"",USART_GSM);
	My_USART_Send_Str(port,USART_GSM);
	My_USART_Send_StrRN("\"",USART_GSM);
	Error_Trap(GSM_TCP_Start_Error);
}

void TCP_Send_Data(char* data)
{
	char GSM_TCP_Send_Error=18;
	My_USART_Send_StrRN("AT+CIPSEND",USART_GSM);
	//if(Send_Data_FLAG==1){
	My_USART_Send_StrRN(data,USART_GSM);
	My_USART_Send(0x1A,USART_GSM);
	Error_Trap(GSM_TCP_Send_Error);
	//}
}
