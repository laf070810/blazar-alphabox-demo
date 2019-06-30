/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdlib.h>
#include "fsl_rtc.h"
#include "blazar_shell.h"
#include "blazar_7seg.h"
#include "blazar_led.h"
#include "blazar_adc.h"
#include "blazar_buzzer.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
enum cmd_homework_task_t 
{
	kHomework_Ex3Task3, 
	kHomework_Ex4Task2, 
	kHomework_Ex4Task3, 
	kHomework_Ex5Task1, 
	kHomework_Ex5Task2, 
	kHomework_Ex5Task3, 
	kHomework_Ex5Task4
};

/*******************************************************************************
 * Variables
 ******************************************************************************/
static TaskHandle_t xHandleTaskHomework;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void vTaskHomework(void *pvParameters);

/*******************************************************************************
 * Code
 ******************************************************************************/
int32_t do_homework(p_shell_context_t context, int32_t argc, char **argv)
{
	if (argc >= 3)
	{
		if (strcmp(argv[1], "2") == 0)
		{
			if (strcmp(argv[2], "1") == 0)
			{
				/* Ex 2 Task 1 */
				for (int i = 0; i < 256; i++)
				{
					PUTCHAR(i);
					
					if ((i + 1) % 16 == 0)
					{
						PRINTF("\r\n");
					}
				}
				
				return 0;
			}
			else if (strcmp(argv[2], "2") == 0)
			{
				/* Ex 2 Task 2 */
				char c;
				c = GETCHAR();
				PRINTF("%c-%#x\r\n", c, c);
				
				return 0;
			}
			else if (strcmp(argv[2], "3") == 0)
			{
				/* Ex 2 Task 3 */
				int times = 0, secret, guess;
				secret = rand() % 10;
				
				do
				{
					times++;
					PRINTF("Guess my number (0 to 9): ");
					guess = GETCHAR() - '0';
					PRINTF("%d\r\n", guess);
					if (secret<guess) PRINTF("The secret number is lower\r\n\r\n");
					else if (secret>guess) PRINTF("The secret number is higher\r\n\r\n");
				} while (secret != guess);
				
				PRINTF("Congratulations!\r\nYou took %d times to guess it!\r\n\r\n", times);
				
				return 0;
			}
			else
			{
				PRINTF("Error: Unknown option. \r\n\r\n");
				return 1;
			}
		}
		else if (strcmp(argv[1], "3") == 0)
		{
			if (strcmp(argv[2], "3") == 0)
			{
				/* Ex 3 Task 3 */
				if (xHandleTaskHomework != NULL)
				{
					vTaskDelete(xHandleTaskHomework);
					xHandleTaskHomework = NULL;
					
					return 0;
				}
				else
				{
					uint8_t task = kHomework_Ex3Task3;
					xTaskCreate(vTaskHomework, "TaskHomework", configMINIMAL_STACK_SIZE + 64, (void *)&task, 2, &xHandleTaskHomework);
					PRINTF("Running Ex3 Task 3. \r\n\r\n");
					
					return 0;
				}
			}
			else
			{
				PRINTF("Error: Unknown option. \r\n\r\n");
				return 1;
			}
		}
		else if (strcmp(argv[1], "4") == 0)
		{
			if (strcmp(argv[2], "1") == 0)
			{
				/* Ex 4 Task 1 */
				if (argc == 4)
				{
					if (xHandleTaskHomework != NULL)
					{
						vTaskDelete(xHandleTaskHomework);
						xHandleTaskHomework = NULL;
					}
					SEG_DisplayInt(atoi(argv[3]));
					
					return 0;
				}
				else
				{
					PRINTF("Error: Unknown option. \r\n\r\n");
					return 1;
				}
			}
			else if (strcmp(argv[2], "2") == 0)
			{
				/* Ex 4 Task 2 */
				if (xHandleTaskHomework != NULL)
				{
					vTaskDelete(xHandleTaskHomework);
					xHandleTaskHomework = NULL;
				}
				uint8_t task = kHomework_Ex4Task2;
				xTaskCreate(vTaskHomework, "TaskHomework", configMINIMAL_STACK_SIZE + 64, (void *)&task, 2, &xHandleTaskHomework);
				PRINTF("Running Ex4 Task 2. \r\n\r\n");
				
				return 0;
			}
			else if (strcmp(argv[2], "3") == 0)
			{
				/* Ex 4 Task 3 */
				if (xHandleTaskHomework != NULL)
				{
					vTaskDelete(xHandleTaskHomework);
					xHandleTaskHomework = NULL;
				}
				uint8_t task = kHomework_Ex4Task3;
				xTaskCreate(vTaskHomework, "TaskHomework", configMINIMAL_STACK_SIZE + 64, (void *)&task, 2, &xHandleTaskHomework);
				PRINTF("Running Ex4 Task 3. \r\n\r\n");
				
				return 0;
			}
			else
			{
				PRINTF("Error: Unknown option. \r\n\r\n");
				return 1;
			}
		}
		else if (strcmp(argv[1], "5") == 0)
		{
			if (strcmp(argv[2], "1") == 0)
			{
				/* Ex 5 Task 1 */
				if (xHandleTaskHomework != NULL)
				{
					vTaskDelete(xHandleTaskHomework);
					xHandleTaskHomework = NULL;
				}
				uint8_t task = kHomework_Ex5Task1;
				xTaskCreate(vTaskHomework, "TaskHomework", configMINIMAL_STACK_SIZE + 64, (void *)&task, 2, &xHandleTaskHomework);
				PRINTF("Running Ex5 Task 1. \r\n\r\n");
				
				return 0;
			}
			else if (strcmp(argv[2], "2") == 0)
			{
				/* Ex 5 Task 2 */
				if (xHandleTaskHomework != NULL)
				{
					vTaskDelete(xHandleTaskHomework);
					xHandleTaskHomework = NULL;
				}
				uint8_t task = kHomework_Ex5Task2;
				xTaskCreate(vTaskHomework, "TaskHomework", configMINIMAL_STACK_SIZE + 64, (void *)&task, 2, &xHandleTaskHomework);
				PRINTF("Running Ex5 Task 2. \r\n\r\n");
				
				return 0;
			}
			else if (strcmp(argv[2], "3") == 0)
			{
				/* Ex 5 Task 3 */
				if (xHandleTaskHomework != NULL)
				{
					vTaskDelete(xHandleTaskHomework);
					xHandleTaskHomework = NULL;
				}
				uint8_t task = kHomework_Ex5Task3;
				xTaskCreate(vTaskHomework, "TaskHomework", configMINIMAL_STACK_SIZE + 64, (void *)&task, 2, &xHandleTaskHomework);
				PRINTF("Running Ex5 Task 3. \r\n\r\n");
				
				return 0;
			}
			else if (strcmp(argv[2], "4") == 0)
			{
				/* Ex 5 Task 4 */
				if (xHandleTaskHomework != NULL)
				{
					vTaskDelete(xHandleTaskHomework);
					xHandleTaskHomework = NULL;
				}
				uint8_t task = kHomework_Ex5Task4;
				xTaskCreate(vTaskHomework, "TaskHomework", configMINIMAL_STACK_SIZE + 64, (void *)&task, 2, &xHandleTaskHomework);
				PRINTF("Running Ex5 Task 4. \r\n\r\n");
				
				return 0;
			}
			else
			{
				PRINTF("Error: Unknown option. \r\n\r\n");
				return 1;
			}
		}
		else
		{
			PRINTF("Error: Unknown option. \r\n\r\n");
			return 1;
		}
	}
	
	PRINTF("Error: Unknown option. \r\n\r\n");
	return 1;
}

static void vTaskHomework(void *pvParameters)
{
	uint8_t task = *(uint8_t *)pvParameters;
	
	if (task == kHomework_Ex3Task3)
	{
		while (true)
		{
			rtc_datetime_t date;
			RTC_GetDatetime(RTC, &date);
			PRINTF("Current datetime: %04hd-%02hd-%02hd %02hd:%02hd:%02hd\r\n", date.year, date.month, date.day, date.hour, date.minute, date.second);
			vTaskDelay(1000 / (1000 / configTICK_RATE_HZ));
		}
	}
	else if (task == kHomework_Ex4Task2)
	{
		uint8_t i = 0;
		
		SEG_SetDP(7);
		while (true)
		{
			SEG_SetDigit(0xFF, 10);
			SEG_SetDigit(1 << i, i + 1);
			i = (i + 1) % 6;
			vTaskDelay(500 / (1000 / configTICK_RATE_HZ));
		}
	}
	else if (task == kHomework_Ex4Task3)
	{
		uint8_t i = 0, j = 0;
		
		SEG_SetDP(7);
		while (true)
		{
			SEG_SetDigit(0xFF, 10);
			SEG_SetDigit(1 << i, i + 1);
			i = (i + 1) % 6;
			if (j < 10)
			{
				vTaskDelay((1000 - j * 100) / (1000 / configTICK_RATE_HZ));
			}
			else if (j < 20)
			{
				vTaskDelay(100 / (1000 / configTICK_RATE_HZ));
			}
			else
			{
				vTaskDelay((100 + (j - 20) * 100) / (1000 / configTICK_RATE_HZ));
			}
			j = (j + 1) % 30;
		}
	}
	else if (task == kHomework_Ex5Task1)
	{
		uint32_t result;
		uint8_t red[] = {255, 0, 0};
		uint8_t black[] = {0, 0, 0};
		bool flag = true;
		
		LED_Init();
		LED_Set(0xFF, black);
		while (true)
		{
			result = ADC_Read(ADC_POTENTIOMETER_CHANNEL);
			result = (result / 5 > 100) ? result / 5 : 100;
			
			if (flag)
			{
				LED_Set(1, red);
				flag = false;
				vTaskDelay(result / (1000 / configTICK_RATE_HZ));
			}
			else
			{
				LED_Set(1, black);
				flag = true;
				vTaskDelay(result / (1000 / configTICK_RATE_HZ));
			}
		}
	}
	else if (task == kHomework_Ex5Task2)
	{
		uint32_t result;
		
		BUZZER_Init();
		while (true)
		{
			result = ADC_Read(ADC_POTENTIOMETER_CHANNEL);
			result = (result / 2 > 500) ? result / 2 : 500;
			BUZZER_Set(result, 50);
			vTaskDelay(50 / (1000 / configTICK_RATE_HZ));
		}
	}
	else if (task == kHomework_Ex5Task3)
	{
		uint32_t result;
		uint8_t color[] = {0, 0, 0};
		uint8_t black[] = {0, 0, 0};
		
		LED_Init();
		LED_Set(0xFF, black);
		while (true)
		{
			result = (1.0 - ADC_Read(ADC_LIGHT_CHANNEL) / 4095.0) * 255;
			color[0] = result; color[1] = result; color[2] = result;
			LED_Set(1, color);
			vTaskDelay(200 / (1000 / configTICK_RATE_HZ));
		}
	}
	else if (task == kHomework_Ex5Task4)
	{
		double result;
		
		SEG_Init();
		while (true)
		{
			result = (ADC_Read(ADC_TEMPERATURE_CHANNEL) - 900) * 0.02;
			SEG_DisplayFloat(result, 2);
			vTaskDelay(200 / (1000 / configTICK_RATE_HZ));
		}
	}
}
