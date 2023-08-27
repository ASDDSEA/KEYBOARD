/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

  typedef enum 
    {
        /*------------------------- HID report data -------------------------*/
        LEFT_CTRL = -8,LEFT_SHIFT = -7,LEFT_ALT = -6,LEFT_GUI = -5,
        RIGHT_CTRL = -4,RIGHT_SHIFT = -3,RIGHT_ALT = -2,RIGHT_GUI = -1,

        RESERVED = 0,ERROR_ROLL_OVER,POST_FAIL,ERROR_UNDEFINED,//1
        A,B,C,D,  E,F,G,H,I,J,K,L,  M,//4
        N,O,P,Q,R,S,T,  U,V,W,X,Y,Z,
        NUM_1/*1!*/,NUM_2/*2@*/,NUM_3/*3#*/,NUM_4/*4$*/,NUM_5/*5%*/,//4
        NUM_6/*6^*/,NUM_7/*7&*/,NUM_8/*8**/,NUM_9/*9(*/,NUM_0/*0)*/,//5
        ENTER,ESC,BACKSPACE,TAB,SPACE,//6
        MINUS/*-_*/,EQUAL/*=+*/,LEFT_U_BRACE/*[{*/,RIGHT_U_BRACE/*]}*/,//7
        BACKSLASH/*\|*/,NONE_US/**/,SEMI_COLON/*;:*/,QUOTE/*'"*/,//8
        GRAVE_ACCENT/*`~*/,COMMA/*,<*/,PERIOD/*.>*/,SLASH/*/?*/,//9
        CAP_LOCK,F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,F11,F12,//10
        PRINT,SCROLL_LOCK,PAUSE,INSERT,HOME,PAGE_UP,DELETE,END,PAGE_DOWN,//11
        RIGHT_ARROW,LEFT_ARROW,DOWN_ARROW,UP_ARROW,PAD_NUM_LOCK,//12
        PAD_SLASH,PAD_ASTERISK,PAD_MINUS,PAD_PLUS,  PAD_ENTER,//13
        PAD_NUM_1,PAD_NUM_2,PAD_NUM_3,PAD_NUM_4,PAD_NUM_5,//14
        PAD_NUM_6,PAD_NUM_7,PAD_NUM_8,PAD_NUM_9,PAD_NUM_0,//15
        PAD_PERIOD , NONUS_BACKSLASH,APPLICATION,POWER,PAD_EQUAL,
        F13,F14,F15,F16,F17,F18,F19,F20,F21,F22,F23,F24, EXECUTE,
        HELP,MENU,SELECT,STOP,AGAIN,UNDO,CUT,COPY,PASTE,FIND,MUTE,VOLUME_UP,VOLUME_DOWN,
        FN = 1000
        /*------------------------- HID report data -------------------------*/
    }KeyCode_t;


/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SPI1_CS_Pin GPIO_PIN_4
#define SPI1_CS_GPIO_Port GPIOA
#define SPI1_CLK_Pin GPIO_PIN_5
#define SPI1_CLK_GPIO_Port GPIOA
#define CE_Pin GPIO_PIN_6
#define CE_GPIO_Port GPIOA
#define SPI1_DAT_Pin GPIO_PIN_7
#define SPI1_DAT_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
