#ifndef _SWITCH_H_
#define _SWITCH_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "blazar_switch.h"
#include "blazar_led.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define SW_GPIO GPIOA
#define SW_IRQ PORTA_IRQn
#define SW_IRQ_HANDLER PORTA_IRQHandler

/*!
 * @brief Switches on the board. 
 *
 * The numbers in the enum are the indices of the pins connected to the switches. 
 * For example, 1 corresponds to PTA1. 
 */
typedef enum
{
	kSWITCH_L_UP = 1, 
	kSWITCH_L_DOWN = 5, 
	kSWITCH_L_LEFT = 12, 
	kSWITCH_L_RIGHT = 13, 
	kSWITCH_R_UP = 17, 
	kSWITCH_R_DOWN = 15, 
	kSWITCH_R_LEFT = 14, 
	kSWITCH_R_RIGHT = 16
} switch_pin_t;

#define SW_MASK_ALL ((1 << kSWITCH_L_UP) | \
					(1 << kSWITCH_L_DOWN) | \
					(1 << kSWITCH_L_LEFT) | \
					(1 << kSWITCH_L_RIGHT) | \
					(1 << kSWITCH_R_UP) | \
					(1 << kSWITCH_R_DOWN) | \
					(1 << kSWITCH_R_LEFT) | \
					(1 << kSWITCH_R_RIGHT))

/*!
 * @brief Switch configuration struct. 
 *
 * "sw" indicates the switch to be configured while "callback" is the function to be called
 * when the switch is pressed. 
 */
typedef struct
{
	switch_pin_t sw;
	void (*callback)(void);
} switch_config_t; 

/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
* API
******************************************************************************/
/*!
 * @brief Init the Switches
 */
void SW_Init(void);

/*!
 * @brief Setup a switch(Register a callback for a switch). 
 *
 * @param switch_config    Configuration for the switch. See the definition of switch_config_t for details. 
 * @return 
 */
void SW_SetupSwitch(switch_config_t switch_config);

/*!
 * @brief Deinit the Switches
 */
void SW_Deinit(void);

#endif /* _SWITCH_H_ */
