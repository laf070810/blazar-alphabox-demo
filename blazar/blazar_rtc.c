/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "blazar_rtc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/
void RTC_Seconds_IRQHandler(void)
{
	RTC_StopTimer(RTC);
	RTC->TPR = 0x7C18;
	RTC_StartTimer(RTC);	
}

void REALTIME_Init(void)
{
	rtc_config_t rtcConfig;
	rtc_datetime_t date;
	
	RTC_GetDefaultConfig(&rtcConfig);
	RTC_Init(RTC, &rtcConfig);
	
	/* Set a start date time and start RT */
	date.year = 2019U;
	date.month = 5U;
	date.day = 16U;
	date.hour = 14U;
	date.minute = 42;
	date.second = 0;
	
	/* RTC time counter has to be stopped before setting the date & time in the TSR register */
	RTC_StopTimer(RTC);
	
	/* Set RTC time to default */
	RTC_SetDatetime(RTC, &date);
	
	/* Set the prescaler for the 1kHz LPO */
	RTC->TPR = 0x7C18;
	
	/* Enable RTC second interrupt */
	RTC_EnableInterrupts(RTC, kRTC_SecondsInterruptEnable);
	
	/* Enable at the NVIC */
	EnableIRQ(RTC_Seconds_IRQn);
	
	/* Start the RTC time counter */
	RTC_StartTimer(RTC);
}

void REALTIME_SetTime(rtc_datetime_t date)
{
	/* RTC time counter has to be stopped before setting the date & time in the TSR register */
	RTC_StopTimer(RTC);
	
	/* Set RTC time to default */
	RTC_SetDatetime(RTC, &date);
	
	/* Set the prescaler for the 1kHz LPO */
	RTC->TPR = 0x7C18;
	
	/* Start the RTC time counter */
	RTC_StartTimer(RTC);
}
