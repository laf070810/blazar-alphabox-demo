/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

#define SOPT4_TPM2CH0SRC_TPM2_CH0 0x00u /*!<@brief TPM2 channel 0 input capture source select: TPM2_CH0 signal */
#define SOPT5_UART1RXSRC_UART_RX 0x00u  /*!<@brief UART1 receive data source select: UART1_RX pin */
#define SOPT5_UART1TXSRC_UART_TX 0x00u  /*!<@brief UART1 transmit data source select: UART1_TX pin */

/*! @name PORTC6 (number 63), J1[11]
  @{ */
#define BOARD_INITPINS_LED_4_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_LED_4_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_LED_4_PIN 6U     /*!<@brief PORTC pin index: 6 */
                                        /* @} */

/*! @name PORTC7 (number 64), J1[1]
  @{ */
#define BOARD_INITPINS_LED_3_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_LED_3_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_LED_3_PIN 7U     /*!<@brief PORTC pin index: 7 */
                                        /* @} */

/*! @name PORTC9 (number 66), J1[16]
  @{ */
#define BOARD_INITPINS_LED_RGB_RED_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_LED_RGB_RED_PIN 9U     /*!<@brief PORTC pin index: 9 */
                                              /* @} */

/*! @name PORTC12 (number 69), J2[1]
  @{ */
#define BOARD_INITPINS_LED_1_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_LED_1_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_LED_1_PIN 12U    /*!<@brief PORTC pin index: 12 */
                                        /* @} */

/*! @name PORTC13 (number 70), J2[3]
  @{ */
#define BOARD_INITPINS_LED_2_GPIO GPIOC /*!<@brief GPIO device name: GPIOC */
#define BOARD_INITPINS_LED_2_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_LED_2_PIN 13U    /*!<@brief PORTC pin index: 13 */
                                        /* @} */

/*! @name PORTB18 (number 53), D3[1]/LED_RGB_BLUE
  @{ */
#define BOARD_INITPINS_LED_RGB_BLUE_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LED_RGB_BLUE_PIN 18U    /*!<@brief PORTB pin index: 18 */
                                               /* @} */

/*! @name PORTB19 (number 54), D3[4]/LED_RGB_GREEN
  @{ */
#define BOARD_INITPINS_LED_RGB_GREEN_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LED_RGB_GREEN_PIN 19U    /*!<@brief PORTB pin index: 19 */
                                                /* @} */

/*! @name PORTA1 (number 27), J1[2]/D0/UART0_RX
  @{ */
#define BOARD_INITPINS_SW1_GPIO GPIOA /*!<@brief GPIO device name: GPIOA */
#define BOARD_INITPINS_SW1_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_SW1_PIN 1U     /*!<@brief PORTA pin index: 1 */
                                      /* @} */

/*! @name PORTA12 (number 32), J1[8]/D3
  @{ */
#define BOARD_INITPINS_SW2_GPIO GPIOA /*!<@brief GPIO device name: GPIOA */
#define BOARD_INITPINS_SW2_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_SW2_PIN 12U    /*!<@brief PORTA pin index: 12 */
                                      /* @} */

/*! @name PORTA13 (number 33), J2[2]/D8
  @{ */
#define BOARD_INITPINS_SW4_GPIO GPIOA /*!<@brief GPIO device name: GPIOA */
#define BOARD_INITPINS_SW4_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_SW4_PIN 13U    /*!<@brief PORTA pin index: 13 */
                                      /* @} */

/*! @name PORTA14 (number 34), U7[11]/INT1_ACCEL
  @{ */
#define BOARD_INITPINS_SW5_GPIO GPIOA /*!<@brief GPIO device name: GPIOA */
#define BOARD_INITPINS_SW5_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_SW5_PIN 14U    /*!<@brief PORTA pin index: 14 */
                                      /* @} */

/*! @name PORTA16 (number 36), J2[9]
  @{ */
#define BOARD_INITPINS_SW6_GPIO GPIOA /*!<@brief GPIO device name: GPIOA */
#define BOARD_INITPINS_SW6_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_SW6_PIN 16U    /*!<@brief PORTA pin index: 16 */
                                      /* @} */

/*! @name PORTA17 (number 37), J2[11]
  @{ */
#define BOARD_INITPINS_SW7_GPIO GPIOA /*!<@brief GPIO device name: GPIOA */
#define BOARD_INITPINS_SW7_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_SW7_PIN 17U    /*!<@brief PORTA pin index: 17 */
                                      /* @} */

/*! @name PORTA15 (number 35), U7[9]/INT2_ACCEL
  @{ */
#define BOARD_INITPINS_SW8_GPIO GPIOA /*!<@brief GPIO device name: GPIOA */
#define BOARD_INITPINS_SW8_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_SW8_PIN 15U    /*!<@brief PORTA pin index: 15 */
                                      /* @} */

/*! @name PORTE31 (number 23), J2[13]
  @{ */
#define BOARD_INITPINS_LCD_RST_GPIO GPIOE /*!<@brief GPIO device name: GPIOE */
#define BOARD_INITPINS_LCD_RST_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_LCD_RST_PIN 31U    /*!<@brief PORTE pin index: 31 */
                                          /* @} */

/*! @name PORTB8 (number 47), J9[1]
  @{ */
#define BOARD_INITPINS_LCD_RS_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LCD_RS_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LCD_RS_PIN 8U     /*!<@brief PORTB pin index: 8 */
                                         /* @} */

/*! @name PORTB9 (number 48), J9[3]
  @{ */
#define BOARD_INITPINS_LCD_CS_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LCD_CS_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LCD_CS_PIN 9U     /*!<@brief PORTB pin index: 9 */
                                         /* @} */

/*! @name PORTB10 (number 49), J9[5]
  @{ */
#define BOARD_INITPINS_LCD_RD_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LCD_RD_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LCD_RD_PIN 10U    /*!<@brief PORTB pin index: 10 */
                                         /* @} */

/*! @name PORTB11 (number 50), J9[7]
  @{ */
#define BOARD_INITPINS_LCD_WR_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LCD_WR_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LCD_WR_PIN 11U    /*!<@brief PORTB pin index: 11 */
                                         /* @} */

/*! @name PORTA19 (number 41), Y1[1]/XTAL
  @{ */
#define BOARD_INITPINS_LCD_LED_GPIO GPIOA /*!<@brief GPIO device name: GPIOA */
#define BOARD_INITPINS_LCD_LED_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_LCD_LED_PIN 19U    /*!<@brief PORTA pin index: 19 */
                                          /* @} */

/*! @name PORTD0 (number 73), J2[6]/D10
  @{ */
#define BOARD_INITPINS_LCD_DATA0_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_LCD_DATA0_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_LCD_DATA0_PIN 0U     /*!<@brief PORTD pin index: 0 */
                                            /* @} */

/*! @name PORTD1 (number 74), J2[12]/D3[3]/D13/LEDRGB_BLUE
  @{ */
#define BOARD_INITPINS_LCD_DATA1_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_LCD_DATA1_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_LCD_DATA1_PIN 1U     /*!<@brief PORTD pin index: 1 */
                                            /* @} */

/*! @name PORTD2 (number 75), J2[8]/D11
  @{ */
#define BOARD_INITPINS_LCD_DATA2_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_LCD_DATA2_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_LCD_DATA2_PIN 2U     /*!<@brief PORTD pin index: 2 */
                                            /* @} */

/*! @name PORTD3 (number 76), J2[10]/D12
  @{ */
#define BOARD_INITPINS_LCD_DATA3_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_LCD_DATA3_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_LCD_DATA3_PIN 3U     /*!<@brief PORTD pin index: 3 */
                                            /* @} */

/*! @name PORTD4 (number 77), J1[6]/D2
  @{ */
#define BOARD_INITPINS_LCD_DATA4_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_LCD_DATA4_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_LCD_DATA4_PIN 4U     /*!<@brief PORTD pin index: 4 */
                                            /* @} */

/*! @name PORTD5 (number 78), J2[4]/D9
  @{ */
#define BOARD_INITPINS_LCD_DATA5_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_LCD_DATA5_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_LCD_DATA5_PIN 5U     /*!<@brief PORTD pin index: 5 */
                                            /* @} */

/*! @name PORTD6 (number 79), J2[17]
  @{ */
#define BOARD_INITPINS_LCD_DATA6_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_LCD_DATA6_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_LCD_DATA6_PIN 6U     /*!<@brief PORTD pin index: 6 */
                                            /* @} */

/*! @name PORTD7 (number 80), J2[19]
  @{ */
#define BOARD_INITPINS_LCD_DATA7_GPIO GPIOD /*!<@brief GPIO device name: GPIOD */
#define BOARD_INITPINS_LCD_DATA7_PORT PORTD /*!<@brief PORT device name: PORTD */
#define BOARD_INITPINS_LCD_DATA7_PIN 7U     /*!<@brief PORTD pin index: 7 */
                                            /* @} */

/*! @name PORTC8 (number 65), J1[14]
  @{ */
#define BOARD_INITPINS_BUZZER_EN_PORT PORTC /*!<@brief PORT device name: PORTC */
#define BOARD_INITPINS_BUZZER_EN_PIN 8U     /*!<@brief PORTC pin index: 8 */
                                            /* @} */

/*! @name PORTA5 (number 31), J1[12]/D5
  @{ */
#define BOARD_INITPINS_SW3_GPIO GPIOA /*!<@brief GPIO device name: GPIOA */
#define BOARD_INITPINS_SW3_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_SW3_PIN 5U     /*!<@brief PORTA pin index: 5 */
                                      /* @} */

/*! @name PORTA2 (number 28), J1[4]/D1/UART0_TX
  @{ */
#define BOARD_INITPINS_A_INT1_GPIO GPIOA /*!<@brief GPIO device name: GPIOA */
#define BOARD_INITPINS_A_INT1_PORT PORTA /*!<@brief PORT device name: PORTA */
#define BOARD_INITPINS_A_INT1_PIN 2U     /*!<@brief PORTA pin index: 2 */
                                         /* @} */

/*! @name PORTE25 (number 25), U7[6]/I2C0_SDA
  @{ */
#define BOARD_INITPINS_A_SDA_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_A_SDA_PIN 25U    /*!<@brief PORTE pin index: 25 */
                                        /* @} */

/*! @name PORTE24 (number 24), U7[4]/I2C0_SCL
  @{ */
#define BOARD_INITPINS_A_SCL_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_A_SCL_PIN 24U    /*!<@brief PORTE pin index: 24 */
                                        /* @} */

/*! @name PORTB0 (number 43), J10[2]/A0
  @{ */
#define BOARD_INITPINS_LCD_XR_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LCD_XR_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LCD_XR_PIN 0U     /*!<@brief PORTB pin index: 0 */
                                         /* @} */

/*! @name PORTB1 (number 44), J10[4]/A1
  @{ */
#define BOARD_INITPINS_LCD_YU_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LCD_YU_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LCD_YU_PIN 1U     /*!<@brief PORTB pin index: 1 */
                                         /* @} */

/*! @name PORTB2 (number 45), J10[6]/A2
  @{ */
#define BOARD_INITPINS_LCD_XL_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LCD_XL_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LCD_XL_PIN 2U     /*!<@brief PORTB pin index: 2 */
                                         /* @} */

/*! @name PORTB3 (number 46), J10[8]/A3
  @{ */
#define BOARD_INITPINS_LCD_YD_GPIO GPIOB /*!<@brief GPIO device name: GPIOB */
#define BOARD_INITPINS_LCD_YD_PORT PORTB /*!<@brief PORT device name: PORTB */
#define BOARD_INITPINS_LCD_YD_PIN 3U     /*!<@brief PORTB pin index: 3 */
                                         /* @} */

/*! @name PORTE29 (number 21), J10[9]
  @{ */
#define BOARD_INITPINS_SERVO1_GPIO GPIOE /*!<@brief GPIO device name: GPIOE */
#define BOARD_INITPINS_SERVO1_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_SERVO1_PIN 29U    /*!<@brief PORTE pin index: 29 */
                                         /* @} */

/*! @name PORTE30 (number 22), J10[11]
  @{ */
#define BOARD_INITPINS_SERVO2_GPIO GPIOE /*!<@brief GPIO device name: GPIOE */
#define BOARD_INITPINS_SERVO2_PORT PORTE /*!<@brief PORT device name: PORTE */
#define BOARD_INITPINS_SERVO2_PIN 30U    /*!<@brief PORTE pin index: 30 */
                                         /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
