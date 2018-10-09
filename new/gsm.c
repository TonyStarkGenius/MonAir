#include "gsm.h"

void Parse_GSM_Data(char* RX_BUF)
{
	
}

void USART_Connection(void)
{
	char GSM_USART_Error=1;
	My_USART_Send_StrRN("AT",USART_GSM);
	Error_Trap(RXGSM_OK_FLAG,GSM_USART_Error);
}

void PIN_Status(void)
{
	char GSM_PIN_Error=1;
	My_USART_Send_StrRN("AT+CPIN?",USART_GSM);
	Error_Trap(RXGSM_OK_FLAG,GSM_PIN_Error);
}

void Signal_Status(void)
{
	char GSM_Signal_Error=1;
	My_USART_Send_StrRN("AT+CSQ",USART_GSM);
	Error_Trap(RXGSM_OK_FLAG,GSM_Signal_Error);
}

void Regisration_Status(void)
{
	char GSM_Registration_Error=1;
	My_USART_Send_StrRN("AT+CREG?",USART_GSM);
	Error_Trap(RXGSM_OK_FLAG,GSM_Registration_Error);
}

void GPRS_Status(void)
{
	char GSM_GPRS_Error=1;
	My_USART_Send_StrRN("AT+CGATT?",USART_GSM);
	Error_Trap(RXGSM_OK_FLAG,GSM_GPRS_Error);
}

void APN_Connection(char* apn,char* uname,char* pwd)
{
	char GSM_APN_Error=1;
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
	}
	Error_Trap(RXGSM_OK_FLAG,GSM_APN_Error);
}

void GPRS_UP(void)
{
	char GSM_GPRSUP_Error=1;
	My_USART_Send_StrRN("AT+CIICR",USART_GSM);
	Error_Trap(RXGSM_OK_FLAG,GSM_GPRSUP_Error);
}

void TCP_Start(char* ip,char* port)
{
	char GSM_TCP_Start_Error=1;
	My_USART_Send_Str("AT+CIPSTART=\"TCP\",\"",USART_GSM);
	My_USART_Send_Str(ip,USART_GSM);
	My_USART_Send_Str("\",\"",USART_GSM);
	My_USART_Send_Str(port,USART_GSM);
	My_USART_Send_StrRN("\"",USART_GSM);
	Error_Trap(RXGSM_OK_FLAG,GSM_TCP_Start_Error);
}

void TCP_Send_Data(char* data)
{
	char GSM_TCP_Send_Error=1;
	My_USART_Send_StrRN("AT+CIPSEND",USART_GSM);
	//if(Send_Data_FLAG==1){
	My_USART_Send_StrRN(data,USART_GSM);
	My_USART_Send(0x1A,USART_GSM);
	Error_Trap(RXGSM_OK_FLAG,GSM_TCP_Send_Error);
	//}
}
