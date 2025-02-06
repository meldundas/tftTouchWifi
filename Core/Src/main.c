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
 Display temperature from a thermistor on an ILI9341 TFT using TouchGFX.
 Send the Temperature every 60 Seconds to Thingspeak with a send count.
 Send to MQTT broker. Subscribe to MQTT esp32c3/led
 Mel Dundas
 Feb 03, 2025
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "crc.h"
#include "dma.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "app_touchgfx.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdbool.h>
#include <stdio.h>
#include "thermistor.h"

#include "atc.h"
#include "espat.h"
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
ATC_HandleTypeDef espat;

bool buttonPressed = false; //blue button
uint16_t thermValue[16] = {0};
uint32_t thermAvg;
float thermTemp = 0.0;
uint32_t loopCount=0;
uint8_t localIP[20] = {"127.0.0.1"};
bool connected = false;
uint32_t count = 0;
bool sendNextTX=false; //send next tx
bool validAvgTemp=false;
//event callback structure
void mqttRX();

const ATC_EventTypeDef events[] = { { "+MQTTSUBRECV:0", mqttRX } };
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void leds(char opt);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void mqttRX()
{

	printf("sub event: %s\r\n",espat.pRxBuff);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
 uint16_t thermIndex = 0;
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
  MX_DMA_Init();
  MX_USART2_UART_Init();
  MX_CRC_Init();
  MX_SPI1_Init();
  MX_ADC1_Init();
  MX_USART1_UART_Init();
  MX_TIM5_Init();
  MX_TouchGFX_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim5);

  ATC_Init(&espat, &huart1, 512, "ESPAT"); //init espAT WiFi
  ATC_SetEvents(&espat, events); 	//set esp callbacks

  Displ_Init(Displ_Orientat_90);	// (mandatory) initialize display controller - set orientation parameter as per TouchGFX setup
  touchgfxSignalVSync();			// ask display syncronization
  Displ_BackLight('I');  			// (mandatory) initialize backlight

  Displ_BackLight('1');

  subscribeToMQTT();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1) {
		ATC_Loop(&espat);


		buttonPressed = !HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);

		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1, 10);
		thermValue[thermIndex] = HAL_ADC_GetValue(&hadc1);

		thermIndex++;

		if(thermIndex==16)
			validAvgTemp=true;

		thermIndex%=16;

		thermAvg=0;
		for(int i=0; i<16; i++)
		{
			thermAvg += thermValue[i];
		}
		thermAvg/=16;


		thermTemp = convertAnalogToTemperature(thermAvg);



		touchgfxSignalVSync();					// ask display synchronization


		if(sendNextTX && validAvgTemp)//time to send next tx update and thermistorAvgdtat valid
		{

			if (sendToThingspeak()) { //retry until successful

				sendToMQTT();

				sendNextTX=false; //don't tx again until next tx time
			}

			count++;
			count%=60;	//ramp graph on thingspeak

		}

    /* USER CODE END WHILE */

  MX_TouchGFX_Process();
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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void leds(char opt) {
	switch (opt) {
	case 'R':
		HAL_GPIO_TogglePin(RED_GPIO_Port, RED_Pin);
		break;

	case 'G':
		HAL_GPIO_TogglePin(GREEN_GPIO_Port, GREEN_Pin);
		break;

	case 'B':
		HAL_GPIO_TogglePin(BLUE_GPIO_Port, BLUE_Pin);
		break;

	}
}

void joinAP(char selection)
{


	switch (selection) {
	case 'P':
//		newAP = &piper;
		break;

	case 'B':
//		newAP = &bakery217;
		break;

	case 'I':
//		newAP = &iotsecurity;
		break;

	}


}

int __io_putchar(int ch)
{
	ITM_SendChar(ch);
	return 0;
}

//timer 5 callback for 1 minute intervals
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	sendNextTX=true;
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
	while (1) {
	}
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
