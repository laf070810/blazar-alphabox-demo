#ifndef _7SEG_H_
#define _7SEG_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdint.h>
#include "FreeRTOS.h"
#include "event_groups.h"
#include "fsl_gpio.h"
#include "fsl_pit.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Digits from left to right are 1 to 6 here. */
#define SEG_COM_1_GPIO GPIOB
#define SEG_COM_1_PIN 8U
#define SEG_COM_2_GPIO GPIOB
#define SEG_COM_2_PIN 9U
#define SEG_COM_3_GPIO GPIOB
#define SEG_COM_3_PIN 10U
#define SEG_COM_4_GPIO GPIOB
#define SEG_COM_4_PIN 2U
#define SEG_COM_5_GPIO GPIOB
#define SEG_COM_5_PIN 1U
#define SEG_COM_6_GPIO GPIOB
#define SEG_COM_6_PIN 0U
#define SEG_DATA_GPIO GPIOD

/* Special characters for display */
#define SEG_CHAR_EMPTY 10
#define SEG_CHAR_MINUS 11
#define SEG_CHAR_H 12

#define PIT_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_BusClk)

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* Event group for PIT defined in main.c */
extern EventGroupHandle_t xEventGroupPIT;

/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief Initialize the 7-seg display.
 */
void SEG_Init(void);

/*!
 * @brief Deinitialize the 7-seg display.
 */
void SEG_Deinit(void);

/*!
 * @brief Set the digits. It WON'T automatically clear other digits. 
 *
 * @param DigitMask        Mask for selecting digits. Bits of DigitMask, 000000B, correspond to six digits. 
 * @param c                The character to be displayed(i.e. the index of DIGIT_MAP). 
 */
void SEG_SetDigit(uint8_t DigitMask, uint8_t c);

/*!
 * @brief Set the decimal point. It WILL automatically clear previous point. 
 *
 * @param Position           The potision of the point. From right to left is 0 to 5. Setting the positions out of this range leads to no DP display. 
 */
void SEG_SetDP(uint8_t Position);

/*!
 * @brief Display an integer. 
 *
 * @param Number           The number to be displayed. 
 */
void SEG_DisplayInt(long Number);

/*!
 * @brief Display a float. 
 *
 * @param Number                 The number to be displayed. 
 * @param DecimalPlaces          The number of decimal places. 
 */
void SEG_DisplayFloat(double Number, uint8_t DecimalPlaces);

#endif /* _7SEG_H_ */
