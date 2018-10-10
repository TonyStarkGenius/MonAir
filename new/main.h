#ifndef __MAIN_H
#define __MAIN_H

#define USART_GSM 2//defined number of TX USART for GSM
#define USART_GSM_RX USART2//defined RX USART for GSM
#define USART_PM USART1//defined RX USART for PM sensor
#define ERROR_USART 3//defined number of TX USART for Errors
#define NAME_OF_VAR(VAR) #VAR//returns name of variable

#include "stm32f10x.h"
#include "afunctions.h"
#include "sensors.h"
#include "usart.h"
#include "gsm.h"
#include "mygsm.h"
#include "MonAir.h"
#include <string.h>
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"
#include "misc.h"
#include "stdint.h"

#endif /* __MAIN_H */
