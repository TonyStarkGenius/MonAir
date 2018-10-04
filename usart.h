#ifndef __USART_H
#define __USART_H
	 
#include "main.h"
#include "stdint.h"

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


#endif /* __USART_H */
