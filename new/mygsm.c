#include "mygsm.h"

void SetUP_GSM_GPRS(char* apn,char* uname,char* pwd)
{
	USART_Connection();
	PIN_Status();
	Signal_Status();
	Regisration_Status();
	GPRS_Status();
	APN_Connection(apn,uname,pwd);
	GPRS_UP();
}

void Send_to_TCP(char* ip,char* port,char* data)
{
	TCP_Start(ip,port);
	//IP fuction
	TCP_Send_Data(PM_2_5_C);
}