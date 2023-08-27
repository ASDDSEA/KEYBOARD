#ifndef __HC165_H
#define __HC165_H
//#include "stm32f0xx.h"
//#include "systick_delay.h"
#include "main.h"
#include "gpio.h"

#define CLK_L	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5, GPIO_PIN_RESET)
#define CLK_H	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5, GPIO_PIN_SET)
#define SL_L	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6, GPIO_PIN_RESET)
#define SL_H	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6, GPIO_PIN_SET)
#define CLK_EN   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4, GPIO_PIN_RESET);
#define CLK_UEN   HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4, GPIO_PIN_SET);

#define DAT	HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_7)

void read_couple(void );
#endif
