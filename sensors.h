#ifndef __SENSORS_H
#define __SENSORS_H

#include "stm32f4xx.h"
#include "usart.h"
#include "stdint.h"

char PM_2_5[3];
char PM_10[3];
char PM_2_5_C[6];
char PM_10_C[6];

void PM_Get(char* str , char* PM2_5 , char* PM10);/* str- PM-Sensor Data, PM2_5- Array to save data of PM2.5 in INT, PM10- Array to save data of PM10 in INT*/ 
void Convert_PM(char* PM1, char* PM2);/* PM1- Array containing INT data, PM2- Array to copy numbers from PM1 in CHAR */
void Transmit_PM_USART2(void);//Transmit data about PM Concentration to USART2

#endif /* __SENSORS_H */
