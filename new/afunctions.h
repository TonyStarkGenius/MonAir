#ifndef __AFUNCTIONS_H
#define __AFUNCTIONS_H

#include "main.h"

void Delay(uint32_t ms);//Delay in milliseconds
void Error_Trap(char FLAG,char myflag);/*if catch some error send it name to usart in cycle FLAG-name of flag which needed to be enabled, myflag- flag which show name of error*/

#endif /* __AFUNCTIONS_H */
