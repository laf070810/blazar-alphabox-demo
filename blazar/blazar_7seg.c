/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "blazar_7seg.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief The mapping from characters to data pins to be set. */
const uint8_t DIGIT_MAP[] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 111, //0-9
								0, 64};  //Special characters marked by the macros in the head file. 

/*! @brief The character to be displayed(i.e. the index of DIGIT_MAP) when scanning the six digits. 255 is used for empty display. */
static uint8_t Digits[6] = {255, 255, 255, 255, 255, 255};  //From right to left. 

/*!
 * @brief To mark current decimal point when scanning. 
 * 
 * From right to left is 0 to 5. 
 * Setting the positions out of this range leads to no DP display. 
 */
static uint8_t DP_Position = 6;

/*! @brief To mark current digit when scanning. From right to left is 0 to 5. */
static uint8_t CurrentDigit = 0;

static TaskHandle_t xHandleTaskSeg;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Turn on digits(i.e. the com ports) according to DigitMask. 
 *
 * @param DigitMask        Mask for selecting digits. Bits of DigitMask, 000000B, correspond to six digits. 
 */
static void DigitOn(uint8_t DigitMask);

/*!
 * @brief Turn off digits(i.e. the com ports) according to DigitMask. 
 *
 * @param DigitMask        Mask for selecting digits. Bits of DigitMask, 000000B, correspond to six digits. 
 */
static void DigitOff(uint8_t DigitMask);

/*!
 * @brief Task to handle interrupt for scanning digits. 
 */
static void vTaskSeg(void *pvParameters);

/*******************************************************************************
 * Code
 ******************************************************************************/
static void vTaskSeg(void *pvParameters)
{
	EventBits_t uxBits;
	const TickType_t xTicksToWait = portMAX_DELAY;
	
    while(1)
    {
		uxBits = xEventGroupWaitBits(xEventGroupPIT, 
                                     1, 
                                     pdTRUE, 
                                     pdFALSE, 
                                     xTicksToWait); 
		
		DigitOff(1 << CurrentDigit);
		CurrentDigit = (CurrentDigit + 1) % 6;
		GPIO_ClearPinsOutput(SEG_DATA_GPIO, 127);
		if (Digits[CurrentDigit] != 255)
		{
			GPIO_SetPinsOutput(SEG_DATA_GPIO, DIGIT_MAP[Digits[CurrentDigit]]);
		}
		if (CurrentDigit == DP_Position)
		{
			GPIO_SetPinsOutput(SEG_DATA_GPIO, 1 << 7);
		}
		else
		{
			GPIO_ClearPinsOutput(SEG_DATA_GPIO, 1 << 7);
		}
		DigitOn(1 << CurrentDigit);
		
		xEventGroupClearBits(xEventGroupPIT, 1);
    }    
}

void SEG_Init(void)
{
	PIT_SetTimerPeriod(PIT, kPIT_Chnl_0, MSEC_TO_COUNT(2U, PIT_SOURCE_CLOCK));
	PIT_EnableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
	PIT_StartTimer(PIT, kPIT_Chnl_0);
	
	xTaskCreate(vTaskSeg, "TaskSeg", configMINIMAL_STACK_SIZE + 64, NULL, 3, &xHandleTaskSeg);
	
	DigitOff(255);
}

void SEG_Deinit(void)
{
	vTaskDelete(xHandleTaskSeg);
	PIT_StopTimer(PIT, kPIT_Chnl_0);
	PIT_DisableInterrupts(PIT, kPIT_Chnl_0, kPIT_TimerInterruptEnable);
	
	DigitOff(255);
}

void SEG_SetDigit(uint8_t DigitMask, uint8_t c)
{
	for (int i = 0; i < 6; i++)
	{
		if (DigitMask & (1 << i))
		{
			Digits[i] = c; 
		}
	}
}

void SEG_SetDP(uint8_t Position)
{
	DP_Position = Position;
}

void SEG_DisplayInt(long Number)
{
	SEG_SetDigit(63, SEG_CHAR_EMPTY);
	SEG_SetDP(7);
	
	if (Number > 999999 | Number < -99999)
	{
		SEG_SetDigit(63, SEG_CHAR_H);
	}
	else if (Number < 0)
	{
		Number = -Number;
		uint8_t i = 0, temp;
		
		do
		{
			temp = Number % 10;
			SEG_SetDigit(1 << i, temp);
			Number /= 10;
			i++;
		} while (Number > 0);
		
		SEG_SetDigit(1 << i, SEG_CHAR_MINUS);
	}
	else if (Number > 0)
	{
		uint8_t i = 0, temp;
		
		do
		{
			temp = Number % 10;
			SEG_SetDigit(1 << i, temp);
			Number /= 10;
			i++;
		} while (Number > 0);
	}
	else
	{
		SEG_SetDigit(1, 0);
	}
}

void SEG_DisplayFloat(double Number, uint8_t DecimalPlaces)
{
	SEG_SetDigit(63, SEG_CHAR_EMPTY);
	SEG_SetDP(7);
	
	int temp = (int)Number;
	
	/* Display */
	for (int i = 0; i < DecimalPlaces; i++)
	{
		Number *= 10;
	}
	temp = (int)Number;
	SEG_DisplayInt(temp);
	SEG_SetDP(DecimalPlaces);
	
	/* Add 0 */
	uint8_t count = 0;
	
	while (temp != 0)
	{
		count++;
		temp /= 10;
	}
	
	if (count <= DecimalPlaces)
	{
		for (int i = count; i <= DecimalPlaces; i++)
		{
			SEG_SetDigit(1 << i, 0);
		}
	}
}

static void DigitOff(uint8_t DigitMask)
{
	if (DigitMask & (1 << 0))
	{
		GPIO_ClearPinsOutput(SEG_COM_6_GPIO, 1 << SEG_COM_6_PIN);
	}
	if (DigitMask & (1 << 1))
	{
		GPIO_ClearPinsOutput(SEG_COM_5_GPIO, 1 << SEG_COM_5_PIN);
	}
	if (DigitMask & (1 << 2))
	{
		GPIO_ClearPinsOutput(SEG_COM_4_GPIO, 1 << SEG_COM_4_PIN);
	}
	if (DigitMask & (1 << 3))
	{
		GPIO_ClearPinsOutput(SEG_COM_3_GPIO, 1 << SEG_COM_3_PIN);
	}
	if (DigitMask & (1 << 4))
	{
		GPIO_ClearPinsOutput(SEG_COM_2_GPIO, 1 << SEG_COM_2_PIN);
	}
	if (DigitMask & (1 << 5))
	{
		GPIO_ClearPinsOutput(SEG_COM_1_GPIO, 1 << SEG_COM_1_PIN);
	}
}

static void DigitOn(uint8_t DigitMask)
{
	if (DigitMask & (1 << 0))
	{
		GPIO_SetPinsOutput(SEG_COM_6_GPIO, 1 << SEG_COM_6_PIN);
	}
	if (DigitMask & (1 << 1))
	{
		GPIO_SetPinsOutput(SEG_COM_5_GPIO, 1 << SEG_COM_5_PIN);
	}
	if (DigitMask & (1 << 2))
	{
		GPIO_SetPinsOutput(SEG_COM_4_GPIO, 1 << SEG_COM_4_PIN);
	}
	if (DigitMask & (1 << 3))
	{
		GPIO_SetPinsOutput(SEG_COM_3_GPIO, 1 << SEG_COM_3_PIN);
	}
	if (DigitMask & (1 << 4))
	{
		GPIO_SetPinsOutput(SEG_COM_2_GPIO, 1 << SEG_COM_2_PIN);
	}
	if (DigitMask & (1 << 5))
	{
		GPIO_SetPinsOutput(SEG_COM_1_GPIO, 1 << SEG_COM_1_PIN);
	}
}
