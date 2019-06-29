/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "blazar_led.h"
#include "blazar_led_data.h"
#include "fsl_tpm.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void LED_On(uint8_t LED_Mask);
static void LED_Off(uint8_t LED_Mask);
static void vTaskLED(void *pvParameters);

/*******************************************************************************
 * Variables
 ******************************************************************************/
static TaskHandle_t xHandleTaskLED;
static uint8_t LEDs[4][3] = {{255, 255, 0}, {100, 255, 100}, {255, 0, 0}, {0, 0, 255}};
static uint8_t CurrentMode = 0;
static uint8_t CurrentLED = 0;
static uint16_t RefreshCounter = 0;
static uint16_t RefreshMod = LED_TPM_FREQ / LED_REFRESH_FREQ;

/*******************************************************************************
 * Code
 ******************************************************************************/
void LED_Init(void)
{
	tpm_config_t tpmInfo;
    tpm_chnl_pwm_signal_param_t tpmParam[3];

    tpmParam[0].chnlNumber = (tpm_chnl_t)LED_RED_TPM_CHANNEL;
    tpmParam[0].level = kTPM_HighTrue;
    tpmParam[0].dutyCyclePercent = 0U;

    tpmParam[1].chnlNumber = (tpm_chnl_t)LED_GREEN_TPM_CHANNEL;
    tpmParam[1].level = kTPM_HighTrue;
    tpmParam[1].dutyCyclePercent = 0U;
	
	tpmParam[2].chnlNumber = (tpm_chnl_t)LED_BLUE_TPM_CHANNEL;
    tpmParam[2].level = kTPM_HighTrue;
    tpmParam[2].dutyCyclePercent = 0U;
	
	/*
     * tpmInfo.prescale = kTPM_Prescale_Divide_1;
     * tpmInfo.useGlobalTimeBase = false;
     * tpmInfo.enableDoze = false;
     * tpmInfo.enableDebugMode = false;
     * tpmInfo.enableReloadOnTrigger = false;
     * tpmInfo.enableStopOnOverflow = false;
     * tpmInfo.enableStartOnTrigger = false;
     * tpmInfo.enablePauseOnTrigger = false;
     * tpmInfo.triggerSelect = kTPM_Trigger_Select_0;
     * tpmInfo.triggerSource = kTPM_TriggerSource_External;
     */
    TPM_GetDefaultConfig(&tpmInfo);
	
    /* Initialize TPM module */
    TPM_Init(LED_RED_TPM_BASEADDR, &tpmInfo);
	TPM_Init(LED_GREEN_TPM_BASEADDR, &tpmInfo);
	TPM_Init(LED_BLUE_TPM_BASEADDR, &tpmInfo);
	TPM_Init(LED_REFRESH_TPM_BASEADDR, &tpmInfo);
	
	TPM_EnableInterrupts(LED_REFRESH_TPM_BASEADDR, kTPM_TimeOverflowInterruptEnable);
    EnableIRQ(LED_REFRESH_TPM_IRQ_NUM);

    TPM_SetupPwm(LED_RED_TPM_BASEADDR, tpmParam, 1U, kTPM_EdgeAlignedPwm, LED_TPM_FREQ, TPM_SOURCE_CLOCK);
	TPM_SetupPwm(LED_GREEN_TPM_BASEADDR, tpmParam + 1, 1U, kTPM_EdgeAlignedPwm, LED_TPM_FREQ, TPM_SOURCE_CLOCK);
	TPM_SetupPwm(LED_BLUE_TPM_BASEADDR, tpmParam + 2, 1U, kTPM_EdgeAlignedPwm, LED_TPM_FREQ, TPM_SOURCE_CLOCK);
	
    TPM_StartTimer(LED_RED_TPM_BASEADDR, kTPM_SystemClock);
	TPM_StartTimer(LED_GREEN_TPM_BASEADDR, kTPM_SystemClock);
	TPM_StartTimer(LED_BLUE_TPM_BASEADDR, kTPM_SystemClock);
	TPM_StartTimer(LED_REFRESH_TPM_BASEADDR, kTPM_SystemClock);
}

void LED_Deinit(void)
{
	if (xHandleTaskLED != NULL)
	{
		vTaskDelete(xHandleTaskLED);
		xHandleTaskLED = NULL;
	}
	
	TPM_StopTimer(LED_RED_TPM_BASEADDR);
	TPM_StopTimer(LED_GREEN_TPM_BASEADDR);
	TPM_StopTimer(LED_BLUE_TPM_BASEADDR);
	TPM_StopTimer(LED_REFRESH_TPM_BASEADDR);
	
	TPM_Deinit(LED_RED_TPM_BASEADDR);
	TPM_Deinit(LED_GREEN_TPM_BASEADDR);
//	TPM_Deinit(LED_BLUE_TPM_BASEADDR);
//	TPM_Deinit(LED_REFRESH_TPM_BASEADDR);
	
	DisableIRQ(LED_REFRESH_TPM_IRQ_NUM);
}

void LED_Set(uint8_t LED_Mask, uint8_t * Color)
{
	if (LED_Mask & (1 << 0))
	{
		LEDs[0][0] = Color[0];
		LEDs[0][1] = Color[1];
		LEDs[0][2] = Color[2];
	}
	if (LED_Mask & (1 << 1))
	{
		LEDs[1][0] = Color[0];
		LEDs[1][1] = Color[1];
		LEDs[1][2] = Color[2];
	}
	if (LED_Mask & (1 << 2))
	{
		LEDs[2][0] = Color[0];
		LEDs[2][1] = Color[1];
		LEDs[2][2] = Color[2];
	}
	if (LED_Mask & (1 << 3))
	{
		LEDs[3][0] = Color[0];
		LEDs[3][1] = Color[1];
		LEDs[3][2] = Color[2];
	}
}

void LED_SetMode(uint8_t Mode)
{
	if (xHandleTaskLED != NULL)
	{
		vTaskDelete(xHandleTaskLED);
		xHandleTaskLED = NULL;
	}
	
	if (Mode != 0)
	{
		CurrentMode = Mode;
		xTaskCreate(vTaskLED, "TaskLED", configMINIMAL_STACK_SIZE + 64, NULL, 2, &xHandleTaskLED);
	}
	else
	{
		CurrentMode = 0;
		uint8_t BLACK[3] = {0, 0, 0};
		LED_Set(0x0F, BLACK);
	}
}

void LED_SwitchMode(void)
{
	CurrentMode = (CurrentMode + 1) % (sizeof(LED_DATA) / sizeof(LED_DATA[0]));
	LED_SetMode(CurrentMode);
}

void LED_REFRESH_TPM_HANDLER(void)
{
    /* Clear interrupt flag.*/
    TPM_ClearStatusFlags(LED_REFRESH_TPM_BASEADDR, kTPM_TimeOverflowFlag);
    
	RefreshCounter++;
	if (RefreshCounter == RefreshMod)
	{
		LED_Off(1 << CurrentLED);
		CurrentLED = (CurrentLED + 1) % 4;
		TPM_UpdatePwmDutycycle(LED_RED_TPM_BASEADDR, (tpm_chnl_t)LED_RED_TPM_CHANNEL, kTPM_EdgeAlignedPwm,
									   (LEDs[CurrentLED][0] * 100) / 255);
		TPM_UpdatePwmDutycycle(LED_GREEN_TPM_BASEADDR, (tpm_chnl_t)LED_GREEN_TPM_CHANNEL, kTPM_EdgeAlignedPwm,
									   (LEDs[CurrentLED][1] * 100) / 255);
		TPM_UpdatePwmDutycycle(LED_BLUE_TPM_BASEADDR, (tpm_chnl_t)LED_BLUE_TPM_CHANNEL, kTPM_EdgeAlignedPwm,
									   (LEDs[CurrentLED][2] * 100) / 255);
		LED_On(1 << CurrentLED);
		
		RefreshCounter = 0;
	}
}

static void LED_On(uint8_t LED_Mask)
{
	if (LED_Mask & (1 << 0))
	{
		GPIO_ClearPinsOutput(BOARD_INITPINS_LED_1_GPIO, 1 << BOARD_INITPINS_LED_1_PIN);
	}
	if (LED_Mask & (1 << 1))
	{
		GPIO_ClearPinsOutput(BOARD_INITPINS_LED_2_GPIO, 1 << BOARD_INITPINS_LED_2_PIN);
	}
	if (LED_Mask & (1 << 2))
	{
		GPIO_ClearPinsOutput(BOARD_INITPINS_LED_3_GPIO, 1 << BOARD_INITPINS_LED_3_PIN);
	}
	if (LED_Mask & (1 << 3))
	{
		GPIO_ClearPinsOutput(BOARD_INITPINS_LED_4_GPIO, 1 << BOARD_INITPINS_LED_4_PIN);
	}
}

static void LED_Off(uint8_t LED_Mask)
{
	if (LED_Mask & (1 << 0))
	{
		GPIO_SetPinsOutput(BOARD_INITPINS_LED_1_GPIO, 1 << BOARD_INITPINS_LED_1_PIN);
	}
	if (LED_Mask & (1 << 1))
	{
		GPIO_SetPinsOutput(BOARD_INITPINS_LED_2_GPIO, 1 << BOARD_INITPINS_LED_2_PIN);
	}
	if (LED_Mask & (1 << 2))
	{
		GPIO_SetPinsOutput(BOARD_INITPINS_LED_3_GPIO, 1 << BOARD_INITPINS_LED_3_PIN);
	}
	if (LED_Mask & (1 << 3))
	{
		GPIO_SetPinsOutput(BOARD_INITPINS_LED_4_GPIO, 1 << BOARD_INITPINS_LED_4_PIN);
	}
}

static void vTaskLED(void *pvParameters)
{
	uint8_t Mode = CurrentMode;
	uint8_t Length = LED_DATA[Mode][0][0];
	uint8_t Color[3];
	
    while(1)
    {
		for (int i = 1; i <= Length; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				Color[0] = LED_DATA[Mode][i][1 + j * 3 + 0];
				Color[1] = LED_DATA[Mode][i][1 + j * 3 + 1];
				Color[2] = LED_DATA[Mode][i][1 + j * 3 + 2];
				LED_Set(1 << j, Color);
			}
			vTaskDelay(LED_DATA[Mode][i][0] / (1000 / configTICK_RATE_HZ));
		}
    }    
}
