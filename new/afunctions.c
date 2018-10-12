#include "afunctions.h"

void Delay(volatile uint32_t delay)
{
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	 CURRENT_TIMER->PSC = CURRENT_FREQ/100-1; //Встановлюємо подрібнювач
	 CURRENT_TIMER->ARR = delay; //встановлюємо значення переповнювання таймеру, а також і значення при якому генеруеться подія оновлення
	 CURRENT_TIMER->EGR |= TIM_EGR_UG; //Генерируемо Подію оновлення для запису даних в регістри PSC і ARR
	 CURRENT_TIMER->CR1 |= TIM_CR1_CEN|TIM_CR1_OPM; //Запускаемо таймер записом биту CEN і встановлюємо режим Одного проходу встановленням біту OPM
	 while ((CURRENT_TIMER->CR1) & (TIM_CR1_CEN!=0)); //Виконуємо цикл поки рахує таймер до нуля
}

void Error_Trap(char myflag)
{
	while(!RXGSM_OK_FLAG)
	{
		My_USART_Send(myflag+48,ERROR_USART);
		Delay(1000);
	}
	RXGSM_OK_FLAG=0;
	myflag=0;
}
