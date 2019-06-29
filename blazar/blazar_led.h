#ifndef _LED_H_
#define _LED_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdint.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define LED_TASK_PRIORITY (tskIDLE_PRIORITY + 1)

#define TPM_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_PllFllSelClk)

#define LED_RED_TPM_BASEADDR TPM0
#define LED_GREEN_TPM_BASEADDR TPM2
#define LED_BLUE_TPM_BASEADDR TPM2
#define LED_RED_TPM_CHANNEL 5
#define LED_GREEN_TPM_CHANNEL 1
#define LED_BLUE_TPM_CHANNEL 0

#define LED_REFRESH_TPM_BASEADDR TPM0
#define LED_REFRESH_TPM_IRQ_NUM TPM0_IRQn
#define LED_REFRESH_TPM_HANDLER TPM0_IRQHandler

#define LED_TPM_FREQ 20000U
#define LED_REFRESH_FREQ 400U
 
/*******************************************************************************
 * Variables
 ******************************************************************************/

 
/*******************************************************************************
* API
******************************************************************************/
/*!
 * @brief Init the LEDs
 */
void LED_Init(void);

/*!
 * @brief Deinit the LEDs
 */
void LED_Deinit(void);

/*!
 * @brief Set the LEDs
 *
 * @param LED_Mask          Mask for selecting LEDs. The ith bit is for the ith LED. 
 * @param Color             An array of 3 elements, representing R, G, B values(0-255). 
 */
void LED_Set(uint8_t LED_Mask, uint8_t * Color);

/*!
 * @brief Set the mode for the LEDs
 *
 * @param Mode          LED mode(i.e. the index of LED_DATA). 
 */
void LED_SetMode(uint8_t Mode);

/*!
 * @brief Switch to the next mode. 
 */
void LED_SwitchMode(void);

#endif /* _LED_H_ */
