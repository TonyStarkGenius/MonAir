#ifndef __GSM_H
#define __GSM_H

#include "main.h"

void Parse_GSM_Data(char* RX_BUF);
void USART_Connection(void);
void PIN_Status(void);
void Signal_Status(void);
void Regisration_Status(void);
void GPRS_Status(void);
void APN_Connection(char* apn,char* uname,char* pwd);
void GPRS_UP(void);
void TCP_Start(char* ip,char* port);
void TCP_Send_Data(char* data);

#endif /* __GSM_H */