#ifndef _BLAZAR_ADC_H_
#define _BLAZAR_ADC_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_debug_console.h"
#include "fsl_adc16.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_ADC16_BASE ADC0
#define DEMO_ADC16_CHANNEL_GROUP 0U

#define ADC_TEMPERATURE_CHANNEL 15U
#define ADC_POTENTIOMETER_CHANNEL 14U
#define ADC_LIGHT_CHANNEL 11U

#define DEMO_ADC16_IRQn ADC0_IRQn
#define DEMO_ADC16_IRQ_HANDLER_FUNC ADC0_IRQHandler

/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief Initialize the ADC.
 */
void ADC_Init(void);

/*!
 * @brief Read the conversion value of a channel. 
 *
 * @param Channel    The channel to read.
 * @return The conversion value of the channel. 
 */
uint32_t ADC_Read(uint8_t Channel);

#endif /* _BLAZAR_ADC_H_ */
