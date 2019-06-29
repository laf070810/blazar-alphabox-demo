/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "blazar_switch.h"

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void vTaskSW(void *pvParameters);

/*******************************************************************************
 * Variables
 ******************************************************************************/
static TaskHandle_t xHandleTaskSW;
static EventGroupHandle_t xEventGroupSW;

/*! @brief Stores the configuration of the switches. */
static switch_config_t switch_config_table[] = {{kSWITCH_L_UP, NULL}, 
											{kSWITCH_L_DOWN, NULL}, 
											{kSWITCH_L_LEFT, NULL}, 
											{kSWITCH_L_RIGHT, NULL}, 
											{kSWITCH_R_UP, NULL}, 
											{kSWITCH_R_DOWN, NULL}, 
											{kSWITCH_R_LEFT, NULL}, 
											{kSWITCH_R_RIGHT, NULL}};

/*******************************************************************************
 * Code
 ******************************************************************************/
void SW_Init(void)
{
	xEventGroupSW = xEventGroupCreate();
	xTaskCreate(vTaskSW, "TaskSW", configMINIMAL_STACK_SIZE + 256, NULL, 3, &xHandleTaskSW);
	EnableIRQ(SW_IRQ);
}

void SW_Deinit(void)
{
	DisableIRQ(SW_IRQ);
	vTaskDelete(xHandleTaskSW);
	vEventGroupDelete(xEventGroupSW);
}

void SW_SetupSwitch(switch_config_t switch_config)
{
	for (int i = 0; i < sizeof(switch_config_table) / sizeof(switch_config_table[0]); i++)
	{
		if (switch_config_table[i].sw == switch_config.sw)
		{
			switch_config_table[i].callback = switch_config.callback;
			break;
		}
	}
}

static void vTaskSW(void *pvParameters)
{
	EventBits_t uxBits;
	const TickType_t xTicksToWait = portMAX_DELAY;
	
    while(1)
    {
		uxBits = xEventGroupWaitBits(xEventGroupSW, 
                                     SW_MASK_ALL, 
                                     pdTRUE, 
                                     pdFALSE, 
                                     xTicksToWait); 
		
		for (int i = 0; i < sizeof(switch_config_table) / sizeof(switch_config_table[0]); i++)
		{
			if((uxBits & (1 << switch_config_table[i].sw)) != 0)
			{
				vTaskDelay(50 / (1000 / configTICK_RATE_HZ)); 
				if (GPIO_ReadPinInput(SW_GPIO, switch_config_table[i].sw) == 0)
				{
					if (switch_config_table[i].callback != NULL)
					{
						switch_config_table[i].callback();
					}
				}
				xEventGroupClearBits(xEventGroupSW, (1 << switch_config_table[i].sw));
			}
		}
    }    
}

void SW_IRQ_HANDLER(void)
{
	BaseType_t xResult;
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	
    xResult = xEventGroupSetBitsFromISR(xEventGroupSW, GPIO_GetPinsInterruptFlags(SW_GPIO), &xHigherPriorityTaskWoken);
	
    if( xResult != pdFAIL )
    {
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
	
	GPIO_ClearPinsInterruptFlags(SW_GPIO, GPIO_GetPinsInterruptFlags(SW_GPIO));
}
