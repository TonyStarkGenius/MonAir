#include "gsm.h"

void Parse_GSM_Data(char* RX_BUF)
{
	
}

void USART_Status(void)
{
	My_USART_Send_StrRN("AT",USART_GSM);
	if(RXGSM_OK_FLAG==1)
	{
		//GSM_USART_Error=0;
		RXGSM_OK_FLAG=0;
	}
}

void PIN_Status(void)
{
	My_USART_Send_StrRN("AT+CPIN?",USART_GSM);
	if(RXGSM_OK_FLAG==1)
	{
		//GSM_PIN_Error=0;
		RXGSM_OK_FLAG=0;
	}
}

void Signal_Status(void)
{
	My_USART_Send_StrRN("AT+CSQ",USART_GSM);
	if(RXGSM_OK_FLAG==1)
	{
		//GSM_Signal_Error=0;
		RXGSM_OK_FLAG=0;
	}
}

void Regisration_Status(void)
{
	My_USART_Send_StrRN("AT+CREG?",USART_GSM);
	if(RXGSM_OK_FLAG==1)
	{
		//GSM_Registration_Error=0;
		RXGSM_OK_FLAG=0;
	}
}

void GPRS_Status(void)
{
	My_USART_Send_StrRN("AT+CGATT?",USART_GSM);
	if(RXGSM_OK_FLAG==1)
	{
		//GSM_GPRS_Error=0;
		RXGSM_OK_FLAG=0;
	}
}

void APN_Connection(char* apn,char* uname,char* pwd)
{
	My_USART_Send_Str("AT+CSTT=\"",USART_GSM);
	My_USART_Send_Str(apn,USART_GSM);
	My_USART_Send_Str("\",\"",USART_GSM);
	My_USART_Send_Str(uname,USART_GSM);
	My_USART_Send_Str("\",\"",USART_GSM);
	My_USART_Send_Str(pwd,USART_GSM);
	My_USART_Send_StrRN("\"",USART_GSM);
	if(RXGSM_OK_FLAG==1)
	{
		//GSM_APN_Error=0;
		RXGSM_OK_FLAG=0;
	}
}

void GPRS_UP(void)
{
	My_USART_Send_StrRN("AT+CIICR",USART_GSM);
	if(RXGSM_OK_FLAG==1)
	{
		//GSM_GPRS_UP_Error=0;
		RXGSM_OK_FLAG=0;
	}
}

void TCP_Start(char* ip,char* port)
{
	My_USART_Send_Str("AT+CIPSTART=\"TCP\",\"",USART_GSM);
	My_USART_Send_Str(ip,USART_GSM);
	My_USART_Send_Str("\",\"",USART_GSM);
	My_USART_Send_Str(port,USART_GSM);
	My_USART_Send_StrRN("\"",USART_GSM);
	if(RXGSM_OK_FLAG==1)
	{
		//GSM_TCP_Start_Error=0;
		RXGSM_OK_FLAG=0;
	}
}

void TCP_Send_Data(char* data)
{
	My_USART_Send_StrRN("AT+CIPSEND",USART_GSM);
	//if(Send_Data_FLAG==1){
	My_USART_Send_Str(data,USART_GSM);
	My_USART_Send_Str(0x1A,USART_GSM);
	if(RXGSM_OK_FLAG==1)
	{
		//GSM_TCP_Send_Error=0;
		RXGSM_OK_FLAG=0;
	}
	//}
}
