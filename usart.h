#ifndef __USART_H
#define __USART_H
	 
#include "main.h"
#include "stdint.h"

#define RX1_BUF_SIZE 32
volatile char RX1_FLAG_END_LINE = 0;
volatile char RXi1=0;
volatile char RXc1;
volatile char RX1_BUF[RX1_BUF_SIZE];

void My_USART1_Init(void);
void My_USART2_Init(void);
void My_USART3_Init(void);

void My_USART1_Send(uint8_t data);
void My_USART2_Send(uint8_t data);
void My_USART3_Send(uint8_t data);

void My_USART1_Send_Str(char * string); 
void My_USART2_Send_Str(char * string); 
void My_USART3_Send_Str(char * string); 
	 
void My_USART1_Send_StrRN(char * string);
void My_USART2_Send_StrRN(char * string);
void My_USART3_Send_StrRN(char * string);

void clear_RXBuffer(void);
void USART1_IRQHandler(void);

#endif /* __USART_H */
