#ifndef __MYGSM_H
#define __MYGSM_H

#include "main.h"

void SetUP_GSM_GPRS(char* apn,char* uname,char* pwd);
void Send_to_TCP(char* ip,char* port,char* data);

#endif /* __MYGSM_H */