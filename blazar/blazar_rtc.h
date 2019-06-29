#ifndef _BLAZAR_RTC_H_
#define _BLAZAR_RTC_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fsl_rtc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief Init the RTC.
 */
void REALTIME_Init(void);

/*!
 * @brief Set the time of the real time clock.
 *
 * @param time    Current date and time to be set.
 */
void REALTIME_SetTime(rtc_datetime_t date);

/* There is no API for reading time here, because the RTC_GetDatetime(...) API in fsl drivers is convenient enough. */

#endif /* _BLAZAR_RTC_H_ */
