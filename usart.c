#include "usart.h"

void My_USART1_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART1, ENABLE);
	
	__enable_irq();
	NVIC_InitTypeDef NVIC_InitStructure;
 
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	USART1->CR1 |= USART_CR1_RXNEIE;
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
	
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
	
	
	USART_InitTypeDef USART_InitStructure;
	
	
	USART_StructInit(&USART_InitStructure);
	USART_Init(USART1, &USART_InitStructure);
  USART_Cmd(USART1, ENABLE);
	
}

void My_USART2_Init(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	__enable_irq();
	NVIC_InitTypeDef NVIC_InitStructure;
 
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	USART2->CR1 |= USART_CR1_RXNEIE;
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART1);
	
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
	
	
	USART_InitTypeDef USART_InitStructure;
	
	
	USART_StructInit(&USART_InitStructure);
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

void My_USART1_Send_Str(char * string) 
{
 uint8_t i=0;
 while(string[i]) 
 {
  My_USART1_Send(string[i]);
  i++;
 }
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

void My_USART1_Send_StrRN(char * string) 
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

void My_USART2_Send_StrRN(char * string) 
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