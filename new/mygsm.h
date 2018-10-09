#ifndef __MYGSM_H
#define __MYGSM_H

#include "main.h"

void SetUP_GSM_GPRS(char* apn,char* uname,char* pwd);/* apn- APN Server, uname- login for server, pwd- password for server */
void Send_to_TCP(char* ip,char* port,char* data);/* ip- ip-adress of server to connect, data- data to transmit for server */

#endif /* __MYGSM_H */
