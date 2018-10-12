#ifndef __GSM_H
#define __GSM_H

#include "main.h"

extern volatile char TCP_CONNECT_FLAG;

void Parse_GSM_Data(char* RX_BUF);/*parser for usable data received from gsm*/
void USART_Connection(void);/*set usart connection up*/
void PIN_Status(void);/*receive whether PIN is required*/
void Signal_Status(void);/*receive signal strength*/
void Regisration_Status(void);/*registration in network status*/
void GPRS_Status(void);/*service gprs status*/
void Shut_Connections(void);
void Set_One_Server(void);
void APN_Connection(char* apn,char* uname,char* pwd);/*set up APN*/
void GPRS_UP(void);/*enable gprs*/
void TCP_Start(char* ip,char* port);/*connect to server ip- ip-adress of server*/
void TCP_Send_Data(char* data);/*send data to server*/

#endif /* __GSM_H */
