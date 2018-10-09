#ifndef __USART_H
#define __USART_H
	 

#include "main.h"

#define RXPM_BUF_SIZE 32
#define RXGSM_BUF_SIZE 100
extern volatile char RXPMi;
extern volatile char RXPMc;
extern volatile char RXPM_BUF[RXPM_BUF_SIZE];
extern volatile char RXGSMi;
extern volatile char RXGSMc;
extern volatile char RXGSM_BUF[RXGSM_BUF_SIZE];
extern volatile char RXGSM_OK_FLAG;

/*if config=0 then interrupts disabled*/
void My_USART1_Init(uint8_t config);
void My_USART2_Init(uint8_t config);
void My_USART3_Init(uint8_t config);

/*Send byte to USART*/
void My_USART_Send(uint8_t data,char usart);

/*Send array to USART !!Sending will be finish when array have '\0' component!!, usart-number of USART to send*/ 
void My_USART_Send_Str(char* string,char usart); 

/*Send array with \r\n in the end, usart- number of USART to send*/
void My_USART_Send_StrRN(char* string,char usart);

void clear_RXBuffer(char* RX_BUF, char RXi,char RX_BUF_SIZE);/*RX_BUF- buffer to clear, RXi- element counter of this buffer, RX_BUF_SIZE- size of this buffer*/
void USARTPM_IRQHandler(void);/*USARTPM Interrupt function*/
void USARTGSM_IRQHandler(void);/*USARTGSM Interrupt function*/

#endif /* __USART_H */
