#include "main.h"

int main(void)
{
	My_USART1_Init(1);//Enable USART1 with interrupts
	My_USART2_Init(0);//Enable USART2 with interrupts
	My_USART3_Init(0);//Enable USART3 without interrupts
	My_USART_Send_Str("AT",3);
	SetUP_GSM_GPRS("www.ab.kyivstar.net","\0","\0");
	while(1)
	{
		Send_MonAir_Data_Thingspeak();//send data of PM to Thingspeak
		Delay(60000);//Delay 60 seconds
	}
}
