#ifndef __AFUNCTIONS_H
#define __AFUNCTIONS_H

#include "main.h"

#define CURRENT_TIMER               ((TIM_TypeDef *) TIM1)
#define CURRENT_FREQ    SystemCoreClock

void Delay(volatile uint32_t delay);//Delay in milliseconds
void Error_Trap(char myflag);/*if catch some error send it name to usart in cycle FLAG-name of flag which needed to be enabled, myflag- flag which show name of error*/

#endif /* __AFUNCTIONS_H */
