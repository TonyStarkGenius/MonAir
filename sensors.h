#ifndef __SENSORS_H
#define __SENSORS_H

#include "main.h"
#include "stdint.h"

char PM_2_5[3];
char PM_10[3];
char PM_2_5_C[6];
char PM_10_C[6];

void PM_Get(char* str , char* PM2_5 , char* PM10);
void Convert_PM(char* PM1, char* PM2);


#endif /* __SENSORS_H */
