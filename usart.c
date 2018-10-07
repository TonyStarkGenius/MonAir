#include "usart.h"

void My_USART1_Init(void)
{
	//Enable periph interfaces
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	//interrupts configuration
	__enable_irq();
	NVIC_InitTypeDef NVIC_InitStructure;
 
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	USART1->CR1 |= USART_CR1_RXNEIE;
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	//enable USART function on pins
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	//pins config
	GPIO_InitTypeDef GPIO_InitStructure;
	
	
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//usart config
	USART_InitTypeDef USART_InitStructure;
	
	
	USART_StructInit(&USART_InitStructure);//9600 bod, 8 bits, 1 stop bit, no parity
	USART_Init(USART1, &USART_InitStructure);
  USART_Cmd(USART1, ENABLE);
	
}

void My_USART2_Init(void)
{
	//enable periph interfaces
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	//interrupts config
	__enable_irq();
	NVIC_InitTypeDef NVIC_InitStructure;
 
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	USART2->CR1 |= USART_CR1_RXNEIE;
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	//enable USART function on pins
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART1);
	//pin config
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
	
	//usart config
	USART_InitTypeDef USART_InitStructure;
	
	
	USART_StructInit(&USART_InitStructure);//9600 bod, 8 bits, 1 stop bit, no parity
	USART_Init(USART2, &USART_InitStructure);
  USART_Cmd(USART2, ENABLE);
	
}

void My_USART1_Send(uint8_t data)
{
	while(!(USART1->SR & USART_SR_TC));
USART1->DR=data; 
}


void My_USART2_Send(uint8_t data)
{
while(!(USART2->SR & USART_SR_TC));
USART2->DR=data; 
}

void My_USART1_Send_Str(char* string) 
{
 uint8_t i=0;
 while(string[i]) 
 {
  My_USART1_Send(string[i]);
  i++;
 }
}

void My_USART2_Send_Str(char* string) 
{
 uint8_t i=0;
 while(string[i]) 
 {
  My_USART2_Send(string[i]);
  i++;
 }
}

void My_USART1_Send_StrRN(char* string) 
{
 uint8_t i=0;
 while(string[i]) 
 {
  My_USART1_Send(string[i]);
  i++;
 }
  My_USART1_Send('\r');
  My_USART1_Send('\n');
}

void My_USART2_Send_StrRN(char* string) 
{
 uint8_t i=0;
 while(string[i]) 
 {
  My_USART2_Send(string[i]);
  i++;
 }
  My_USART2_Send('\r');
  My_USART2_Send('\n');
}

void USART1_IRQHandler(void)
{
    if (USART1->SR & USART_SR_RXNE)//if recieve data from RX1
    {
            RX1c = USART_ReceiveData(USART1);//storage recieved byte in RX1c
            RX1_BUF[RX1i] = RX1c;//insert recieved dara to buffer
            RX1i++;
            if (RX1i > RX1_BUF_SIZE-1) //if RX1_BUF is full
						{
							PM_Get(RX1_BUF,PM_2_5,PM_10);//Get PM parameters
              clear_RXBuffer();
            }
            RX1_FLAG_END_LINE = 1;
     }
}

void clear_RXBuffer(void) 
{
  for (RX1i=0; RX1i<RX1_BUF_SIZE; RX1i++)
    RX1_BUF[RX1i] = '\0';
  RX1i = 0;
}
