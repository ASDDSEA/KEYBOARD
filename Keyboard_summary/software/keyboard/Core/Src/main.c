/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usb_device.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_customhid.h"
#include "HC165.h"
extern USBD_HandleTypeDef hUsbDeviceFS;
uint8_t value[13]={0};

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USB_DEVICE_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
	uint8_t report[8]={0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00};	
	HAL_TIM_Base_Start_IT(&htim1);

  //uint8_t key[2]={0X00,0X00};
	//uint16_t value=0x0000;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
		
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
uint8_t hidbuffer[17];
uint8_t hid_num[13][8]={{5,3,7,5,2,2,4,5},
												{17,18,3,4,3,3,3,5},
//												{11,14,14,13,12,12,12,12},
//												{14,13,13,13,13,13,13,13},
//												{11,11,11,12,12,12,11,14},
//												{7,8,7,1,1,11,11,11},
//												{8,1,1,18,9,8,8,7},
//												{3,4,8,3,4,7,7,3},
//												{2,7,4,3,3,6,6,4},
//												{2,5,3,5,6,6,5,3},
//												{5,5,2,4,6,6,4,3},
//												{5,4,2,5,6,6,3,4},
//												{1,1,1,1,9,7,8,5}
												};
uint8_t hid_report[13][8]={
{0X10,0X08,0x10,0X04,0X80,0X10,0X40,0X04},//1
{0X00,0X00,0x80,0x04,0x40,0X10,0X20,0X01},//2
//{0X20,0X02,0X01,0X80,0X40,��0X20,0X10,0X08},//3
//{0X20,0X02,0X01,0X80,0X40,0X20,0X10,0X08},//4
//{0X08,0X01,0X02,0X04,0X08,0X40,0X20,0X10},//5
//{0X04,0X02,0X01,0X20,0X10,0X02,0X04,0X08},//6
//{0X80,0X40,0X80,0X08,0X01,0X10,0X01,0X40},//7
//{0X40,0X01,0X40,0X80,0X08,0X20,0X80,0X08},//8
//{0X20,0X10,0X02,0X20,0X10,0X40,0X80,0X04},//9
//{0X40,0X02,0X04,0X10,0X10,0X20,0X01,0X08},//10
//{0X20,0X08,0X80,0X20,0X04,0X08,0X80,0X02},//11
//{0X80,0X10,0X10,0X04,0X01,0X02,0X01,0X40},//12
//{0X04,0X08,0X01,0X02,0X02,0X08,0X20,0X40},//13
};
void DelayUs(uint32_t _us)
{
    for (int i = 0; i < _us; i++)
        for (int j = 0; j < 8; j++)  // ToDo: tune this for different chips
            __NOP();
}

uint8_t report[8]={0};

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(htim->Instance == TIM1)
  {		
    memset(hidbuffer,0,17);
    hidbuffer[0] = 1;
		read_couple();

		for(int i=0;i<=1;i++)
		
		{
			for(int j=0;j<8;j++)
			{
				if((value[i]&(0x80>>j))==0)
				{
					hidbuffer[hid_num[i][j]]=hidbuffer[hid_num[i][j]]|hid_report[i][j];

				}
			}	

		}
		
				USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS,hidbuffer,17);

//		else
//		{
//			USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS,hidbuffer,17);
//	
//		}

	}
}
	/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
//  while (1)
//  {
//  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
