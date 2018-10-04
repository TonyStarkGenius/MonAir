#include "main.h"

#define RX1_BUF_SIZE 32
volatile char RX1_FLAG_END_LINE = 0;
volatile char RXi1;
volatile char RXc1;
volatile char RX1_BUF[RX1_BUF_SIZE] = {'\0'};
char PM_2_5[3];
char PM_10[3];

void clear_RXBuffer(void) 
{
  for (RXi1=0; RXi1<RX1_BUF_SIZE; RXi1++)
    RX1_BUF[RXi1] = '\0';
  RXi1 = 0;
}

void PM_Get(const char* str,char*PM2_5,char*PM10)
{
	char* pos1;
	if(strstr(str,"2"))
	{
		pos1=strstr(str,"2");
		if(pos1+1=="=")
		{
			strncpy(PM2_5,pos1+6,2);
			strncpy(PM10,pos1+8,2);
		}
		PM2_5[2]='\0';
		PM10[2]='\0';
	}
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
	
	USART_StructInit(&USART_InitStructure);
	USART_Init(USART2, &USART_InitStructure);
  USART_Cmd(USART2, ENABLE);
	
	USART_StructInit(&USART_InitStructure);
	USART_Init(USART1, &USART_InitStructure);
  USART_Cmd(USART1, ENABLE);
	
	
}

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

void USART1_IRQHandler(void)
{
    if ((USART1->SR & USART_FLAG_RXNE) != (u16)RESET)
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
            USART_SendData(USART2, RXc1);
     }
}

int main(void)
{
	My_USART_Init();
	
	while(1)
	{
		My_USART2_Send_Str("PM2.5= ");
		My_USART2_Send_Str(PM_2_5);
		RX1_FLAG_END_LINE = 0;
		Delay();
		GPIO_SetBits(GPIOD,GPIO_Pin_14);
	}
}
