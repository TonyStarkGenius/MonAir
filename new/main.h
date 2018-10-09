#ifndef __MAIN_H
#define __MAIN_H

#define USART_GSM 2//defined number of TX USART for GSM
#define USART_GSM_RX USART2//defined RX USART for GSM
#define USART_PM USART1//defined RX USART for PM sensor
#define ERROR_USART 3
#define NAME_OF_VAR(VAR) #VAR

#include "stm32f4xx.h"
#include "afunctions.h"
#include "sensors.h"
#include "usart.h"
#include "gsm.h"
#include "mygsm.h"
#include "MonAir.h"
#include <string.h>
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_usart.h"
#include "misc.h"
#include "stdint.h"

#endif /* __MAIN_H */
