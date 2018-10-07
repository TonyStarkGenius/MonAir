#include "main.h"

int main(void)
{
My_USART1_Init(1);//Enable USART1 with interrupts
My_USART2_Init(0);//Enable USART2 without interrupts
while(1)
{
Transmit_PM_USART2();//Transmit data about PM Concentration to USART2
Delay(3000);//Delay 3 seconds
RX1_FLAG_END_LINE=0;
}
}
