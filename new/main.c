#include "main.h"

int main(void)
{
	My_USART1_Init(1);//Enable USART1 with interrupts
	My_USART2_Init(1);//Enable USART2 without interrupts
	SetUP_GSM_GPRS("www.ab.kyivstar.net","\0","\0");
	while(1)
	{
		Send_MonAir_Data();
		Delay(60000);//Delay 60 seconds
	}
}
