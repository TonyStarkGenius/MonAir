#include "main.h"

int main(void)
{
	My_USART1_Init(1);//Enable USART1 with interrupts
	My_USART2_Init(1);//Enable USART2 with interrupts
	My_USART3_Init(0);//Enable USART3 without interrupts
	SetUP_GSM_GPRS("internet","\0","\0");
	while(1)
	{
		Send_MonAir_Data_Thingspeak();//send data of PM to Thingspeak
		Delay(6000);//Delay 60 seconds
	}
}
