#include "afunctions.h"

void Delay(uint32_t ms)
{
	ms=ms*8000;
	for(int i=0;i!=ms;i++);
}

void Error_Trap(char FLAG,char myflag)
{
	while(!FLAG)
	{
		My_USART_Send_StrRN(NAME_OF_VAR(myflag),ERROR_USART);
		Delay(1000);
	}
	FLAG=0;
	myflag=0;
}
