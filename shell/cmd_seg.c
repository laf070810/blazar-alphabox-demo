/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Blazar_shell.h"
#include "Blazar_ADC.h"
#include "Blazar_7SEG.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/
static TaskHandle_t xHandleTaskSeg;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void vTaskSeg(void *pvParameters);

/*******************************************************************************
 * Code
 ******************************************************************************/
int32_t do_seg(p_shell_context_t context, int32_t argc, char **argv)
{
	if (argc == 2)
	{
		if (strcmp(argv[1], "temp") == 0)
		{
			PRINTF("Temperature: %f\r\n\r\n", ADC_Read(ADC_TEMPERATURE_CHANNEL) / 1.0);
			
			return 0;
		}
		else if (strcmp(argv[1], "potential") == 0)
		{	
			if (xHandleTaskSeg != NULL)
			{
				vTaskDelete(xHandleTaskSeg);
				xHandleTaskSeg = NULL;
			}
			uint8_t channel = ADC_POTENTIOMETER_CHANNEL;
			xTaskCreate(vTaskSeg, "TaskSeg", configMINIMAL_STACK_SIZE + 64, (void *)&channel, 2, &xHandleTaskSeg);
			PRINTF("Displaying real time voltage on 7-seg. \r\n\r\n");
			
			return 0;
		}
		else if (strcmp(argv[1], "light") == 0)
		{
			if (xHandleTaskSeg != NULL)
			{
				vTaskDelete(xHandleTaskSeg);
				xHandleTaskSeg = NULL;
			}
			uint8_t channel = ADC_LIGHT_CHANNEL;
			xTaskCreate(vTaskSeg, "TaskSeg", configMINIMAL_STACK_SIZE + 64, (void *)&channel, 2, &xHandleTaskSeg);
			PRINTF("Displaying real time lightness on 7-seg. \r\n\r\n");
			
			return 0;
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

static void vTaskSeg(void *pvParameters)
{
	uint8_t channel = *(uint8_t *)pvParameters;
	
	while (true)
	{
		SEG_DisplayFloat(ADC_Read(channel) / 4095.0 * 3.3, 3);
		vTaskDelay(100 / (1000 / configTICK_RATE_HZ));
	}
}
