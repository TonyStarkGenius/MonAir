#include "usart.h"

volatile char RXPMi=0;
volatile char RXPMc;
volatile char RXPM_BUF[RXPM_BUF_SIZE];
volatile char RXGSMi=0;
volatile char RXGSMc;
volatile char RXGSM_BUF[RXGSM_BUF_SIZE];
volatile char RXGSM_OK_FLAG=0;

void My_USART1_Init(uint8_t config)
{
	//Enable periph interfaces
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	//interrupts configuration
	if(config)
	{
	__enable_irq();
	NVIC_InitTypeDef NVIC_InitStructure;
 
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	//enable interrupts for receiving
	USART1->CR1 |= USART_CR1_RXNEIE;
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	}
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

void My_USART2_Init(uint8_t config)
{
	//enable periph interfaces
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	//interrupts config
	if(config)
	{
	__enable_irq();
	NVIC_InitTypeDef NVIC_InitStructure;
 
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	//enable interrupts for receiving
	USART2->CR1 |= USART_CR1_RXNEIE;
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	}
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
void My_USART3_Init(uint8_t config)
{
	//Enable periph interfaces
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB2Periph_USART3, ENABLE);
	//interrupts configuration
	if(config)
	{
	__enable_irq();
	NVIC_InitTypeDef NVIC_InitStructure;
 
  NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	//enable interrupts for receiving
	USART3->CR1 |= USART_CR1_RXNEIE;
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	}
	//enable USART function on pins
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_USART3);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_USART3);
	//pins config
	GPIO_InitTypeDef GPIO_InitStructure;
	
	
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	//usart config
	USART_InitTypeDef USART_InitStructure;
	
	
	USART_StructInit(&USART_InitStructure);//9600 bod, 8 bits, 1 stop bit, no parity
	USART_Init(USART3, &USART_InitStructure);
  USART_Cmd(USART3, ENABLE);
	
}


void My_USART_Send(uint8_t data,char usart)
{
	if(usart==1)
	{
		while(!(USART1->SR & USART_SR_TC));
		USART1->DR=data;
	}		
	if(usart==2)
	{
		while(!(USART2->SR & USART_SR_TC));
		USART2->DR=data;
	}		
	if(usart==3)
	{
		while(!(USART3->SR & USART_SR_TC));
		USART3->DR=data;
	}		
}


void My_USART_Send_Str(char* string,char usart) 
{
	if (usart==1)
	{
 uint8_t i=0;
 while(string[i]) 
 {
  My_USART_Send(string[i],1);
  i++;
 }
 }
	if (usart==2)
	{
 uint8_t i=0;
 while(string[i]) 
 {
  My_USART_Send(string[i],2);
  i++;
 }
 }
	if (usart==3)
	{
 uint8_t i=0;
 while(string[i]) 
 {
  My_USART_Send(string[i],3);
  i++;
 }
 }
}

void My_USART_Send_StrRN(char* string,char usart) 
{
  if (usart==1)
	{
 uint8_t i=0;
 while(string[i]) 
 {
  My_USART_Send(string[i],1);
  i++;
 }
  My_USART_Send('\r',1);
  My_USART_Send('\n',1);
 }
	if (usart==2)
	{
 uint8_t i=0;
 while(string[i]) 
 {
  My_USART_Send(string[i],2);
  i++;
 }
  My_USART_Send('\r',2);
  My_USART_Send('\n',2);
 }
	if (usart==3)
	{
 uint8_t i=0;
 while(string[i]) 
 {
  My_USART_Send(string[i],3);
  i++;
 }
  My_USART_Send('\r',3);
  My_USART_Send('\n',3);
 }
}

void USARTPM_IRQHandler(void)
{
    if (USART_PM->SR & USART_SR_RXNE)//if receive data from RXPM
    {
      RXPMc = USART_ReceiveData(USART_PM);//storage received byte in RXPMc
      RXPM_BUF[RXPMi] = RXPMc;//insert received dara to buffer
      RXPMi++;
      if (RXPMi > RXPM_BUF_SIZE-1) //if RXPM_BUF is full
			{
				PM_Get(RXPM_BUF,PM_2_5,PM_10);//Get PM parameters
		    //convert PM parametres to char
		    Convert_PM(PM_2_5,PM_2_5_C);
		    Convert_PM(PM_10,PM_10_C);
        clear_RXBuffer(RXPM_BUF,RXPMi,RXPM_BUF_SIZE);
      }
    }
}

void USARTGSM_IRQHandler(void)
{
    if (USART_GSM_RX->SR & USART_SR_RXNE)//if receive data from RXGSM
    {
      RXGSMc = USART_ReceiveData(USART_GSM_RX);//storage received byte in RXGSMc
      RXGSM_BUF[RXGSMi] = RXGSMc;//insert received dara to buffer
      RXGSMi++;
      if (strstr(RXGSM_BUF,"OK")) //if received from gsm OK
			{
				RXGSM_OK_FLAG=1;
				Parse_GSM_Data(RXGSM_BUF);//Parse for some usable data received
        clear_RXBuffer(RXGSM_BUF,RXGSMi,RXGSM_BUF_SIZE);
      }
    }
}

void clear_RXBuffer(char* RX_BUF, char RXi,char RX_BUF_SIZE) 
{
  for (RXi=0; RXi<RX_BUF_SIZE; RXi++)
    RX_BUF[RXi] = '\0';
  RXi = 0;
}
