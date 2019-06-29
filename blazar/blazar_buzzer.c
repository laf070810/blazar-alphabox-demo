/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "blazar_buzzer.h"
#include "blazar_buzzer_data.h"
#include "fsl_tpm.h"

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void vTaskBuzzer(void *pvParameters);

/*******************************************************************************
 * Variables
 ******************************************************************************/
static TaskHandle_t xHandleTaskBuzzer;
static uint8_t CurrentSong = 0;

/*******************************************************************************
 * Code
 ******************************************************************************/
void BUZZER_Init(void)
{
	tpm_config_t tpmInfo;
	uint8_t updatedDutycycle = 0U;
	tpm_chnl_pwm_signal_param_t tpmParam;

	tpmParam.chnlNumber = (tpm_chnl_t)kTPM_Chnl_4;
	tpmParam.level = kTPM_HighTrue;
	tpmParam.dutyCyclePercent = 0U;

	TPM_GetDefaultConfig(&tpmInfo);
	tpmInfo.prescale = kTPM_Prescale_Divide_32;
	
	/* Initializes the TPM module. */
	TPM_Init(TPM0, &tpmInfo);
	TPM_SetupPwm(TPM0, &tpmParam, 1U, kTPM_EdgeAlignedPwm, 221U, TPM_SOURCE_CLOCK);
	TPM_StartTimer(TPM0, kTPM_SystemClock);
}

void BUZZER_Deinit(void)
{
	if (xHandleTaskBuzzer != NULL)
	{
		vTaskDelete(xHandleTaskBuzzer);
		xHandleTaskBuzzer = NULL;
	}
	
	TPM_StopTimer(TPM0);
	TPM_Deinit(TPM0);
}

void BUZZER_Set(uint16_t Freq, uint8_t DutyCycle)
{
	tpm_chnl_pwm_signal_param_t tpmParam;
	
	tpmParam.chnlNumber = (tpm_chnl_t)kTPM_Chnl_4;
	tpmParam.level = kTPM_HighTrue;
	tpmParam.dutyCyclePercent = DutyCycle;
	
	TPM_SetupPwm(TPM0, &tpmParam, 1U, kTPM_EdgeAlignedPwm, Freq, TPM_SOURCE_CLOCK);
}

void BUZZER_Play(uint8_t Song)
{
	if (xHandleTaskBuzzer != NULL)
	{
		vTaskDelete(xHandleTaskBuzzer);
		xHandleTaskBuzzer = NULL;
	}
	
	if (Song != 0)
	{
		CurrentSong = Song;
		xTaskCreate(vTaskBuzzer, "TaskBuzzer", configMINIMAL_STACK_SIZE + 64, NULL, 2, &xHandleTaskBuzzer);
	}
}

static void vTaskBuzzer(void *pvParameters)
{
	uint8_t Song = CurrentSong;
	uint8_t Length = SONG_DATA[Song][0][0];
	
    while(1)
    {
		for (int i = 1; i <= Length; i++)
		{
			BUZZER_Set(SONG_DATA[Song][i][0], 50);
			vTaskDelay(SONG_DATA[Song][i][1] / (1000 / configTICK_RATE_HZ));
			
			BUZZER_Set(SONG_DATA[Song][i][0], 0);
			vTaskDelay(10 / (1000 / configTICK_RATE_HZ));
		}
    }    
}
