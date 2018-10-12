#include "afunctions.h"

void Delay(volatile uint32_t delay)
{
     RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	 CURRENT_TIMER->PSC = CURRENT_FREQ/100-1;
	 CURRENT_TIMER->ARR = delay;
	 CURRENT_TIMER->EGR |= TIM_EGR_UG;
	 CURRENT_TIMER->CR1 |= TIM_CR1_CEN|TIM_CR1_OPM;
	 while ((CURRENT_TIMER->CR1) & (TIM_CR1_CEN!=0));
}

void Error_Trap(char myflag)
{
	while(!RXGSM_OK_FLAG||!TCP_CONNECT_FLAG)
	{
		My_USART_Send(myflag+48,ERROR_USART);
		Delay(1000);
	}
	RXGSM_OK_FLAG=0;
	myflag=0;
}
