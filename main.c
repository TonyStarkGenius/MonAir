#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"
#include "misc.h"
#include <string.h>

#define RX1_BUF_SIZE 32
volatile char RX1_FLAG_END_LINE = 0;
volatile char RXi1=0;
volatile char RXc1;
volatile char RX1_BUF[RX1_BUF_SIZE];
char PM_2_5[4];
char PM_10[4];
char PM25[4];

void My_USART2_Send(uint8_t data) {
while(!(USART2->SR & USART_SR_TC));
USART2->DR=data; 
}

void My_USART2_Send_Str(char * string) 
{
 uint8_t i=0;
 while(string[i]) 
 {
  My_USART2_Send(string[i]);
  i++;
 }
}

void clear_RXBuffer(void) 
{
  for (RXi1=0; RXi1<RX1_BUF_SIZE; RXi1++)
    RX1_BUF[RXi1] = '\0';
  RXi1 = 0;
}

void PM_Get(char* str,char*PM2_5,char*PM10)
{
	const char* pos1;
		pos1=strstr(str,"2");
		if(!strncmp(pos1+1,"=",1))
		{
			strncpy(PM2_5,pos1+7,3);
			strncpy(PM10,pos1+9,1);
			
		}
		My_USART2_Send(PM_2_5[2]);
		PM2_5[3]='\0';
		PM10[2]='\0';
}

void Delay(void) 
{
  volatile uint32_t i;
  for (i=0; i != 0x310000; i++);
}

void My_USART_Init()
{ 
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOD, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	__enable_irq();
	NVIC_InitTypeDef NVIC_InitStructure;

  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	USART1->CR1 |= USART_CR1_RXNEIE;
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	USART_InitTypeDef USART_InitStructure;
	
	//USART_StructInit(&USART_InitStructure);
	USART_InitStructure.USART_BaudRate = 115200; //???????? ?????? 9600 ???
USART_InitStructure.USART_WordLength = USART_WordLength_8b; //????? ????? 8 ???
USART_InitStructure.USART_StopBits = USART_StopBits_1; //1 ????-???
USART_InitStructure.USART_Parity = USART_Parity_No ; //??? ???????? ????????
USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None; //??? ??????????? ????????
USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; //??????? ?????????? ? ???????? USART2
	USART_Init(USART2, &USART_InitStructure);
  USART_Cmd(USART2, ENABLE);
	USART_Init(USART1, &USART_InitStructure);
  USART_Cmd(USART1, ENABLE);	
}

void Convert_PM(char* PM)
{
	uint16_t INTPM=(int)PM[0];
	uint8_t INTPML=(int)PM[1];
	INTPM=(INTPM<<8)+INTPML;
	int del = 1;
	int del1 = 10;
	for (int i = 1;(INTPM / del) >= 1;i--)
	{
		PM25[i] = ((INTPM / del) % del1) + 48;
		del *= 10;
	}
}

void USART1_IRQHandler(void)
{
    if ((USART1->SR & USART_SR_RXNE))
    {
            RXc1 = USART_ReceiveData(USART1);
            RX1_BUF[RXi1] = RXc1;
            RXi1++;
            if (RXi1 > RX1_BUF_SIZE-1) 
						{
							PM_Get(RX1_BUF,PM_2_5,PM_10);
              clear_RXBuffer();
            }
            RX1_FLAG_END_LINE = 1;
            //USART_SendData(USART2, RXc1);
     }
}

int main(void)
{
	My_USART_Init();
	
	while(1)
	{
		Convert_PM(PM_2_5);
		//My_USART2_Send_Str("PM2.5: ");
		//My_USART2_Send_Str(PM25);
		Delay();
		RX1_FLAG_END_LINE = 0;
		GPIO_SetBits(GPIOD,GPIO_Pin_14);
	}
}
