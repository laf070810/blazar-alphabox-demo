#ifndef _BUZZER_H_
#define _BUZZER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdint.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define TPM_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_PllFllSelClk)

/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
* API
******************************************************************************/
/*!
 * @brief Init the Buzzer
 */
void BUZZER_Init(void);

/*!
 * @brief Deinit the Buzzer
 */
void BUZZER_Deinit(void);

/*!
 * @brief Set the Buzzer
 *
 * @param Freq              Sound frequency. 
 * @param DutyCycle         Duty cycle of PWM(0-100). 
 */
void BUZZER_Set(uint16_t Freq, uint8_t DutyCycle);

/*!
 * @brief Play a song with infinite loop. 
 *
 * @param Song          Song number(i.e. the index of SONG_DATA). Setting it to 0 leads to no music. 
 */
void BUZZER_Play(uint8_t Song);

#endif /* _BUZZER_H_ */
