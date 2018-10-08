#ifndef __USART_H
#define __USART_H
	 
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"
#include "misc.h"
#include "sensors.h"
#include "stdint.h"/*To enable use uint_t*/

#define RX1_BUF_SIZE 32
volatile char RX1_FLAG_END_LINE = 0;
volatile char RX1i=0;
volatile char RX1c;
volatile char RX1_BUF[RX1_BUF_SIZE];

/*if config=0 then interrupts disabled*/
void My_USART1_Init(uint8_t config);
void My_USART2_Init(uint8_t config);

/*Send byte to USART*/
void My_USART1_Send(uint8_t data);
void My_USART2_Send(uint8_t data);

/*Send array to USART !!Sending will be finish when array have '\0' component!! */ 
void My_USART1_Send_Str(char* string); 
void My_USART2_Send_Str(char* string); 

/*Send array with \r\n in the end*/
void My_USART1_Send_StrRN(char* string);
void My_USART2_Send_StrRN(char* string);

void clear_RXBuffer(void);/*Clears RX1_BUF*/
void USART1_IRQHandler(void);/*USART1 Interrupt function*/

#endif /* __USART_H */
