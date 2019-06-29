/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v5.0
processor: MKL25Z128xxx4
package_id: MKL25Z128VLK4
mcu_data: ksdk2_0
processor_version: 5.0.0
board: FRDM-KL25Z
pin_labels:
- {pin_num: '21', pin_signal: CMP0_IN5/ADC0_SE4b/PTE29/TPM0_CH2/TPM_CLKIN0, label: 'J10[9]', identifier: SERVO1}
- {pin_num: '22', pin_signal: DAC0_OUT/ADC0_SE23/CMP0_IN4/PTE30/TPM0_CH3/TPM_CLKIN1, label: 'J10[11]', identifier: SERVO2}
- {pin_num: '23', pin_signal: PTE31/TPM0_CH4, label: 'J2[13]', identifier: LCD_RST}
- {pin_num: '24', pin_signal: PTE24/TPM0_CH0/I2C0_SCL, label: 'U7[4]/I2C0_SCL', identifier: ACCEL_SCL;A_SCL}
- {pin_num: '25', pin_signal: PTE25/TPM0_CH1/I2C0_SDA, label: 'U7[6]/I2C0_SDA', identifier: ACCEL_SDA;A_SDA}
- {pin_num: '27', pin_signal: TSI0_CH2/PTA1/UART0_RX/TPM2_CH0, label: 'J1[2]/D0/UART0_RX', identifier: DEBUG_UART_RX;SW1}
- {pin_num: '28', pin_signal: TSI0_CH3/PTA2/UART0_TX/TPM2_CH1, label: 'J1[4]/D1/UART0_TX', identifier: DEBUG_UART_TX;A_INT1}
- {pin_num: '31', pin_signal: PTA5/USB_CLKIN/TPM0_CH2, label: 'J1[12]/D5', identifier: SW3}
- {pin_num: '32', pin_signal: PTA12/TPM1_CH0, label: 'J1[8]/D3', identifier: SW2}
- {pin_num: '33', pin_signal: PTA13/TPM1_CH1, label: 'J2[2]/D8', identifier: SW4}
- {pin_num: '34', pin_signal: PTA14/SPI0_PCS0/UART0_TX, label: 'U7[11]/INT1_ACCEL', identifier: ACCEL_INT1;SW5}
- {pin_num: '35', pin_signal: PTA15/SPI0_SCK/UART0_RX, label: 'U7[9]/INT2_ACCEL', identifier: ACCEL_INT2;SW8}
- {pin_num: '36', pin_signal: PTA16/SPI0_MOSI/SPI0_MISO, label: 'J2[9]', identifier: SW8;SW6}
- {pin_num: '37', pin_signal: PTA17/SPI0_MISO/SPI0_MOSI, label: 'J2[11]', identifier: SW7}
- {pin_num: '41', pin_signal: XTAL0/PTA19/UART1_TX/TPM_CLKIN1/LPTMR0_ALT1, label: 'Y1[1]/XTAL', identifier: XTAL0;LCD_LED}
- {pin_num: '43', pin_signal: ADC0_SE8/TSI0_CH0/PTB0/LLWU_P5/I2C0_SCL/TPM1_CH0, label: 'J10[2]/A0', identifier: LCD_XR}
- {pin_num: '44', pin_signal: ADC0_SE9/TSI0_CH6/PTB1/I2C0_SDA/TPM1_CH1, label: 'J10[4]/A1', identifier: LCD_YU}
- {pin_num: '45', pin_signal: ADC0_SE12/TSI0_CH7/PTB2/I2C0_SCL/TPM2_CH0, label: 'J10[6]/A2', identifier: LCD_XL}
- {pin_num: '46', pin_signal: ADC0_SE13/TSI0_CH8/PTB3/I2C0_SDA/TPM2_CH1, label: 'J10[8]/A3', identifier: LCD_YD}
- {pin_num: '47', pin_signal: PTB8/EXTRG_IN, label: 'J9[1]', identifier: LCD_RS}
- {pin_num: '48', pin_signal: PTB9, label: 'J9[3]', identifier: LCD_CS}
- {pin_num: '49', pin_signal: PTB10/SPI1_PCS0, label: 'J9[5]', identifier: LCD_RD}
- {pin_num: '50', pin_signal: PTB11/SPI1_SCK, label: 'J9[7]', identifier: LCD_WR}
- {pin_num: '53', pin_signal: TSI0_CH11/PTB18/TPM2_CH0, label: 'D3[1]/LED_RGB_BLUE', identifier: LED_RED;LED_RGB_GREEN;LED_RGB_BLUE}
- {pin_num: '54', pin_signal: TSI0_CH12/PTB19/TPM2_CH1, label: 'D3[4]/LED_RGB_GREEN', identifier: LED_GREEN;LED_RGB_RED;LED_RGB_BLUE;LED_RGB_GREEN}
- {pin_num: '63', pin_signal: CMP0_IN0/PTC6/LLWU_P10/SPI0_MOSI/EXTRG_IN/SPI0_MISO, label: 'J1[11]', identifier: LED_4}
- {pin_num: '64', pin_signal: CMP0_IN1/PTC7/SPI0_MISO/SPI0_MOSI, label: 'J1[1]', identifier: LED_3}
- {pin_num: '65', pin_signal: CMP0_IN2/PTC8/I2C0_SCL/TPM0_CH4, label: 'J1[14]', identifier: BUZZER_EN}
- {pin_num: '66', pin_signal: CMP0_IN3/PTC9/I2C0_SDA/TPM0_CH5, label: 'J1[16]', identifier: LED_RGB_RED}
- {pin_num: '69', pin_signal: PTC12/TPM_CLKIN0, label: 'J2[1]', identifier: LED_1}
- {pin_num: '70', pin_signal: PTC13/TPM_CLKIN1, label: 'J2[3]', identifier: LED_2}
- {pin_num: '73', pin_signal: PTD0/SPI0_PCS0/TPM0_CH0, label: 'J2[6]/D10', identifier: LCD_DATA1;LCD_DATA0}
- {pin_num: '74', pin_signal: ADC0_SE5b/PTD1/SPI0_SCK/TPM0_CH1, label: 'J2[12]/D3[3]/D13/LEDRGB_BLUE', identifier: LED_BLUE;LCD_DATA2;LCD_DATA1}
- {pin_num: '75', pin_signal: PTD2/SPI0_MOSI/UART2_RX/TPM0_CH2/SPI0_MISO, label: 'J2[8]/D11', identifier: LCD_DATA3;LCD_DATA2}
- {pin_num: '76', pin_signal: PTD3/SPI0_MISO/UART2_TX/TPM0_CH3/SPI0_MOSI, label: 'J2[10]/D12', identifier: LCD_DATA4;LCD_DATA3}
- {pin_num: '77', pin_signal: PTD4/LLWU_P14/SPI1_PCS0/UART2_RX/TPM0_CH4, label: 'J1[6]/D2', identifier: LCD_DATA4}
- {pin_num: '78', pin_signal: ADC0_SE6b/PTD5/SPI1_SCK/UART2_TX/TPM0_CH5, label: 'J2[4]/D9', identifier: LCD_DATA5}
- {pin_num: '79', pin_signal: ADC0_SE7b/PTD6/LLWU_P15/SPI1_MOSI/UART0_RX/SPI1_MISO, label: 'J2[17]', identifier: LCD_DATA6}
- {pin_num: '80', pin_signal: PTD7/SPI1_MISO/UART0_TX/SPI1_MOSI, label: 'J2[19]', identifier: LCD_DATA7}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '63', peripheral: GPIOC, signal: 'GPIO, 6', pin_signal: CMP0_IN0/PTC6/LLWU_P10/SPI0_MOSI/EXTRG_IN/SPI0_MISO, direction: OUTPUT}
  - {pin_num: '64', peripheral: GPIOC, signal: 'GPIO, 7', pin_signal: CMP0_IN1/PTC7/SPI0_MISO/SPI0_MOSI, direction: OUTPUT}
  - {pin_num: '66', peripheral: TPM0, signal: 'CH, 5', pin_signal: CMP0_IN3/PTC9/I2C0_SDA/TPM0_CH5, direction: OUTPUT}
  - {pin_num: '69', peripheral: GPIOC, signal: 'GPIO, 12', pin_signal: PTC12/TPM_CLKIN0, direction: OUTPUT}
  - {pin_num: '70', peripheral: GPIOC, signal: 'GPIO, 13', pin_signal: PTC13/TPM_CLKIN1, direction: OUTPUT}
  - {pin_num: '53', peripheral: TPM2, signal: 'CH, 0', pin_signal: TSI0_CH11/PTB18/TPM2_CH0, identifier: LED_RGB_BLUE, direction: OUTPUT}
  - {pin_num: '54', peripheral: TPM2, signal: 'CH, 1', pin_signal: TSI0_CH12/PTB19/TPM2_CH1, identifier: LED_RGB_GREEN, direction: OUTPUT}
  - {pin_num: '27', peripheral: GPIOA, signal: 'GPIO, 1', pin_signal: TSI0_CH2/PTA1/UART0_RX/TPM2_CH0, identifier: SW1, direction: INPUT, gpio_interrupt: kPORT_InterruptFallingEdge,
    pull_enable: enable, passive_filter: disable}
  - {pin_num: '32', peripheral: GPIOA, signal: 'GPIO, 12', pin_signal: PTA12/TPM1_CH0, direction: INPUT, gpio_interrupt: kPORT_InterruptFallingEdge, pull_enable: enable}
  - {pin_num: '33', peripheral: GPIOA, signal: 'GPIO, 13', pin_signal: PTA13/TPM1_CH1, direction: INPUT, gpio_interrupt: kPORT_InterruptFallingEdge, pull_enable: enable}
  - {pin_num: '34', peripheral: GPIOA, signal: 'GPIO, 14', pin_signal: PTA14/SPI0_PCS0/UART0_TX, identifier: SW5, direction: INPUT, gpio_interrupt: kPORT_InterruptFallingEdge,
    pull_enable: enable}
  - {pin_num: '36', peripheral: GPIOA, signal: 'GPIO, 16', pin_signal: PTA16/SPI0_MOSI/SPI0_MISO, identifier: SW6, direction: INPUT, gpio_interrupt: kPORT_InterruptFallingEdge,
    pull_enable: enable}
  - {pin_num: '37', peripheral: GPIOA, signal: 'GPIO, 17', pin_signal: PTA17/SPI0_MISO/SPI0_MOSI, direction: INPUT, gpio_interrupt: kPORT_InterruptFallingEdge, pull_enable: enable}
  - {pin_num: '35', peripheral: GPIOA, signal: 'GPIO, 15', pin_signal: PTA15/SPI0_SCK/UART0_RX, identifier: SW8, direction: INPUT, gpio_interrupt: kPORT_InterruptFallingEdge,
    pull_enable: enable}
  - {pin_num: '23', peripheral: GPIOE, signal: 'GPIO, 31', pin_signal: PTE31/TPM0_CH4, direction: OUTPUT, gpio_init_state: 'true', pull_enable: disable}
  - {pin_num: '47', peripheral: GPIOB, signal: 'GPIO, 8', pin_signal: PTB8/EXTRG_IN, direction: OUTPUT, gpio_init_state: 'true', pull_enable: disable}
  - {pin_num: '48', peripheral: GPIOB, signal: 'GPIO, 9', pin_signal: PTB9, direction: OUTPUT, gpio_init_state: 'true', pull_enable: disable}
  - {pin_num: '49', peripheral: GPIOB, signal: 'GPIO, 10', pin_signal: PTB10/SPI1_PCS0, direction: OUTPUT, gpio_init_state: 'true', pull_enable: disable}
  - {pin_num: '50', peripheral: GPIOB, signal: 'GPIO, 11', pin_signal: PTB11/SPI1_SCK, direction: OUTPUT, gpio_init_state: 'true', pull_enable: disable}
  - {pin_num: '41', peripheral: GPIOA, signal: 'GPIO, 19', pin_signal: XTAL0/PTA19/UART1_TX/TPM_CLKIN1/LPTMR0_ALT1, identifier: LCD_LED, direction: OUTPUT, gpio_init_state: 'true',
    pull_enable: disable}
  - {pin_num: '73', peripheral: GPIOD, signal: 'GPIO, 0', pin_signal: PTD0/SPI0_PCS0/TPM0_CH0, identifier: LCD_DATA0, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '74', peripheral: GPIOD, signal: 'GPIO, 1', pin_signal: ADC0_SE5b/PTD1/SPI0_SCK/TPM0_CH1, identifier: LCD_DATA1, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '75', peripheral: GPIOD, signal: 'GPIO, 2', pin_signal: PTD2/SPI0_MOSI/UART2_RX/TPM0_CH2/SPI0_MISO, identifier: LCD_DATA2, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '76', peripheral: GPIOD, signal: 'GPIO, 3', pin_signal: PTD3/SPI0_MISO/UART2_TX/TPM0_CH3/SPI0_MOSI, identifier: LCD_DATA3, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '77', peripheral: GPIOD, signal: 'GPIO, 4', pin_signal: PTD4/LLWU_P14/SPI1_PCS0/UART2_RX/TPM0_CH4, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '78', peripheral: GPIOD, signal: 'GPIO, 5', pin_signal: ADC0_SE6b/PTD5/SPI1_SCK/UART2_TX/TPM0_CH5, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '79', peripheral: GPIOD, signal: 'GPIO, 6', pin_signal: ADC0_SE7b/PTD6/LLWU_P15/SPI1_MOSI/UART0_RX/SPI1_MISO, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '80', peripheral: GPIOD, signal: 'GPIO, 7', pin_signal: PTD7/SPI1_MISO/UART0_TX/SPI1_MOSI, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '65', peripheral: TPM0, signal: 'CH, 4', pin_signal: CMP0_IN2/PTC8/I2C0_SCL/TPM0_CH4, direction: OUTPUT}
  - {pin_num: '31', peripheral: GPIOA, signal: 'GPIO, 5', pin_signal: PTA5/USB_CLKIN/TPM0_CH2, direction: INPUT, gpio_interrupt: kPORT_InterruptFallingEdge, pull_enable: enable}
  - {pin_num: '28', peripheral: GPIOA, signal: 'GPIO, 2', pin_signal: TSI0_CH3/PTA2/UART0_TX/TPM2_CH1, identifier: A_INT1, direction: OUTPUT}
  - {pin_num: '25', peripheral: I2C0, signal: SDA, pin_signal: PTE25/TPM0_CH1/I2C0_SDA, identifier: A_SDA}
  - {pin_num: '24', peripheral: I2C0, signal: SCL, pin_signal: PTE24/TPM0_CH0/I2C0_SCL, identifier: A_SCL}
  - {pin_num: '55', peripheral: ADC0, signal: 'SE, 14', pin_signal: ADC0_SE14/TSI0_CH13/PTC0/EXTRG_IN/CMP0_OUT}
  - {pin_num: '56', peripheral: ADC0, signal: 'SE, 15', pin_signal: ADC0_SE15/TSI0_CH14/PTC1/LLWU_P6/RTC_CLKIN/I2C1_SCL/TPM0_CH0}
  - {pin_num: '57', peripheral: ADC0, signal: 'SE, 11', pin_signal: ADC0_SE11/TSI0_CH15/PTC2/I2C1_SDA/TPM0_CH1}
  - {pin_num: '58', peripheral: UART1, signal: RX, pin_signal: PTC3/LLWU_P7/UART1_RX/TPM0_CH2/CLKOUTa}
  - {pin_num: '61', peripheral: UART1, signal: TX, pin_signal: PTC4/LLWU_P8/SPI0_PCS0/UART1_TX/TPM0_CH3}
  - {pin_num: '43', peripheral: GPIOB, signal: 'GPIO, 0', pin_signal: ADC0_SE8/TSI0_CH0/PTB0/LLWU_P5/I2C0_SCL/TPM1_CH0, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '44', peripheral: GPIOB, signal: 'GPIO, 1', pin_signal: ADC0_SE9/TSI0_CH6/PTB1/I2C0_SDA/TPM1_CH1, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '45', peripheral: GPIOB, signal: 'GPIO, 2', pin_signal: ADC0_SE12/TSI0_CH7/PTB2/I2C0_SCL/TPM2_CH0, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '46', peripheral: GPIOB, signal: 'GPIO, 3', pin_signal: ADC0_SE13/TSI0_CH8/PTB3/I2C0_SDA/TPM2_CH1, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '16', peripheral: UART2, signal: RX, pin_signal: ADC0_DM3/ADC0_SE7a/PTE23/TPM2_CH1/UART2_RX}
  - {pin_num: '15', peripheral: UART2, signal: TX, pin_signal: ADC0_DP3/ADC0_SE3/PTE22/TPM2_CH0/UART2_TX}
  - {pin_num: '21', peripheral: GPIOE, signal: 'GPIO, 29', pin_signal: CMP0_IN5/ADC0_SE4b/PTE29/TPM0_CH2/TPM_CLKIN0, direction: OUTPUT}
  - {pin_num: '22', peripheral: GPIOE, signal: 'GPIO, 30', pin_signal: DAC0_OUT/ADC0_SE23/CMP0_IN4/PTE30/TPM0_CH3/TPM_CLKIN1, direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
    /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Port B Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortB);
    /* Port C Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);
    /* Port D Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortD);
    /* Port E Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    gpio_pin_config_t SW1_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA1 (pin 27)  */
    GPIO_PinInit(BOARD_INITPINS_SW1_GPIO, BOARD_INITPINS_SW1_PIN, &SW1_config);

    gpio_pin_config_t A_INT1_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA2 (pin 28)  */
    GPIO_PinInit(BOARD_INITPINS_A_INT1_GPIO, BOARD_INITPINS_A_INT1_PIN, &A_INT1_config);

    gpio_pin_config_t SW3_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA5 (pin 31)  */
    GPIO_PinInit(BOARD_INITPINS_SW3_GPIO, BOARD_INITPINS_SW3_PIN, &SW3_config);

    gpio_pin_config_t SW2_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA12 (pin 32)  */
    GPIO_PinInit(BOARD_INITPINS_SW2_GPIO, BOARD_INITPINS_SW2_PIN, &SW2_config);

    gpio_pin_config_t SW4_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA13 (pin 33)  */
    GPIO_PinInit(BOARD_INITPINS_SW4_GPIO, BOARD_INITPINS_SW4_PIN, &SW4_config);

    gpio_pin_config_t SW5_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA14 (pin 34)  */
    GPIO_PinInit(BOARD_INITPINS_SW5_GPIO, BOARD_INITPINS_SW5_PIN, &SW5_config);

    gpio_pin_config_t SW8_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA15 (pin 35)  */
    GPIO_PinInit(BOARD_INITPINS_SW8_GPIO, BOARD_INITPINS_SW8_PIN, &SW8_config);

    gpio_pin_config_t SW6_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA16 (pin 36)  */
    GPIO_PinInit(BOARD_INITPINS_SW6_GPIO, BOARD_INITPINS_SW6_PIN, &SW6_config);

    gpio_pin_config_t SW7_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA17 (pin 37)  */
    GPIO_PinInit(BOARD_INITPINS_SW7_GPIO, BOARD_INITPINS_SW7_PIN, &SW7_config);

    gpio_pin_config_t LCD_LED_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTA19 (pin 41)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_LED_GPIO, BOARD_INITPINS_LCD_LED_PIN, &LCD_LED_config);

    gpio_pin_config_t LCD_XR_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTB0 (pin 43)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_XR_GPIO, BOARD_INITPINS_LCD_XR_PIN, &LCD_XR_config);

    gpio_pin_config_t LCD_YU_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTB1 (pin 44)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_YU_GPIO, BOARD_INITPINS_LCD_YU_PIN, &LCD_YU_config);

    gpio_pin_config_t LCD_XL_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTB2 (pin 45)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_XL_GPIO, BOARD_INITPINS_LCD_XL_PIN, &LCD_XL_config);

    gpio_pin_config_t LCD_YD_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTB3 (pin 46)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_YD_GPIO, BOARD_INITPINS_LCD_YD_PIN, &LCD_YD_config);

    gpio_pin_config_t LCD_RS_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTB8 (pin 47)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_RS_GPIO, BOARD_INITPINS_LCD_RS_PIN, &LCD_RS_config);

    gpio_pin_config_t LCD_CS_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTB9 (pin 48)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_CS_GPIO, BOARD_INITPINS_LCD_CS_PIN, &LCD_CS_config);

    gpio_pin_config_t LCD_RD_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTB10 (pin 49)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_RD_GPIO, BOARD_INITPINS_LCD_RD_PIN, &LCD_RD_config);

    gpio_pin_config_t LCD_WR_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTB11 (pin 50)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_WR_GPIO, BOARD_INITPINS_LCD_WR_PIN, &LCD_WR_config);

    gpio_pin_config_t LED_4_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC6 (pin 63)  */
    GPIO_PinInit(BOARD_INITPINS_LED_4_GPIO, BOARD_INITPINS_LED_4_PIN, &LED_4_config);

    gpio_pin_config_t LED_3_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC7 (pin 64)  */
    GPIO_PinInit(BOARD_INITPINS_LED_3_GPIO, BOARD_INITPINS_LED_3_PIN, &LED_3_config);

    gpio_pin_config_t LED_1_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC12 (pin 69)  */
    GPIO_PinInit(BOARD_INITPINS_LED_1_GPIO, BOARD_INITPINS_LED_1_PIN, &LED_1_config);

    gpio_pin_config_t LED_2_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC13 (pin 70)  */
    GPIO_PinInit(BOARD_INITPINS_LED_2_GPIO, BOARD_INITPINS_LED_2_PIN, &LED_2_config);

    gpio_pin_config_t LCD_DATA0_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTD0 (pin 73)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_DATA0_GPIO, BOARD_INITPINS_LCD_DATA0_PIN, &LCD_DATA0_config);

    gpio_pin_config_t LCD_DATA1_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTD1 (pin 74)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_DATA1_GPIO, BOARD_INITPINS_LCD_DATA1_PIN, &LCD_DATA1_config);

    gpio_pin_config_t LCD_DATA2_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTD2 (pin 75)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_DATA2_GPIO, BOARD_INITPINS_LCD_DATA2_PIN, &LCD_DATA2_config);

    gpio_pin_config_t LCD_DATA3_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTD3 (pin 76)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_DATA3_GPIO, BOARD_INITPINS_LCD_DATA3_PIN, &LCD_DATA3_config);

    gpio_pin_config_t LCD_DATA4_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTD4 (pin 77)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_DATA4_GPIO, BOARD_INITPINS_LCD_DATA4_PIN, &LCD_DATA4_config);

    gpio_pin_config_t LCD_DATA5_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTD5 (pin 78)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_DATA5_GPIO, BOARD_INITPINS_LCD_DATA5_PIN, &LCD_DATA5_config);

    gpio_pin_config_t LCD_DATA6_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTD6 (pin 79)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_DATA6_GPIO, BOARD_INITPINS_LCD_DATA6_PIN, &LCD_DATA6_config);

    gpio_pin_config_t LCD_DATA7_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTD7 (pin 80)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_DATA7_GPIO, BOARD_INITPINS_LCD_DATA7_PIN, &LCD_DATA7_config);

    gpio_pin_config_t SERVO1_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTE29 (pin 21)  */
    GPIO_PinInit(BOARD_INITPINS_SERVO1_GPIO, BOARD_INITPINS_SERVO1_PIN, &SERVO1_config);

    gpio_pin_config_t SERVO2_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTE30 (pin 22)  */
    GPIO_PinInit(BOARD_INITPINS_SERVO2_GPIO, BOARD_INITPINS_SERVO2_PIN, &SERVO2_config);

    gpio_pin_config_t LCD_RST_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTE31 (pin 23)  */
    GPIO_PinInit(BOARD_INITPINS_LCD_RST_GPIO, BOARD_INITPINS_LCD_RST_PIN, &LCD_RST_config);

    const port_pin_config_t SW1 = {/* Internal pull-up resistor is enabled */
                                   kPORT_PullUp,
                                   /* Slow slew rate is configured */
                                   kPORT_SlowSlewRate,
                                   /* Passive filter is disabled */
                                   kPORT_PassiveFilterDisable,
                                   /* Low drive strength is configured */
                                   kPORT_LowDriveStrength,
                                   /* Pin is configured as PTA1 */
                                   kPORT_MuxAsGpio};
    /* PORTA1 (pin 27) is configured as PTA1 */
    PORT_SetPinConfig(BOARD_INITPINS_SW1_PORT, BOARD_INITPINS_SW1_PIN, &SW1);

    /* Interrupt configuration on PORTA1 (pin 27): Interrupt on falling edge */
    PORT_SetPinInterruptConfig(BOARD_INITPINS_SW1_PORT, BOARD_INITPINS_SW1_PIN, kPORT_InterruptFallingEdge);

    const port_pin_config_t SW2 = {/* Internal pull-up resistor is enabled */
                                   kPORT_PullUp,
                                   /* Slow slew rate is configured */
                                   kPORT_SlowSlewRate,
                                   /* Passive filter is disabled */
                                   kPORT_PassiveFilterDisable,
                                   /* Low drive strength is configured */
                                   kPORT_LowDriveStrength,
                                   /* Pin is configured as PTA12 */
                                   kPORT_MuxAsGpio};
    /* PORTA12 (pin 32) is configured as PTA12 */
    PORT_SetPinConfig(BOARD_INITPINS_SW2_PORT, BOARD_INITPINS_SW2_PIN, &SW2);

    /* Interrupt configuration on PORTA12 (pin 32): Interrupt on falling edge */
    PORT_SetPinInterruptConfig(BOARD_INITPINS_SW2_PORT, BOARD_INITPINS_SW2_PIN, kPORT_InterruptFallingEdge);

    const port_pin_config_t SW4 = {/* Internal pull-up resistor is enabled */
                                   kPORT_PullUp,
                                   /* Slow slew rate is configured */
                                   kPORT_SlowSlewRate,
                                   /* Passive filter is disabled */
                                   kPORT_PassiveFilterDisable,
                                   /* Low drive strength is configured */
                                   kPORT_LowDriveStrength,
                                   /* Pin is configured as PTA13 */
                                   kPORT_MuxAsGpio};
    /* PORTA13 (pin 33) is configured as PTA13 */
    PORT_SetPinConfig(BOARD_INITPINS_SW4_PORT, BOARD_INITPINS_SW4_PIN, &SW4);

    /* Interrupt configuration on PORTA13 (pin 33): Interrupt on falling edge */
    PORT_SetPinInterruptConfig(BOARD_INITPINS_SW4_PORT, BOARD_INITPINS_SW4_PIN, kPORT_InterruptFallingEdge);

    const port_pin_config_t SW5 = {/* Internal pull-up resistor is enabled */
                                   kPORT_PullUp,
                                   /* Fast slew rate is configured */
                                   kPORT_FastSlewRate,
                                   /* Passive filter is disabled */
                                   kPORT_PassiveFilterDisable,
                                   /* Low drive strength is configured */
                                   kPORT_LowDriveStrength,
                                   /* Pin is configured as PTA14 */
                                   kPORT_MuxAsGpio};
    /* PORTA14 (pin 34) is configured as PTA14 */
    PORT_SetPinConfig(BOARD_INITPINS_SW5_PORT, BOARD_INITPINS_SW5_PIN, &SW5);

    /* Interrupt configuration on PORTA14 (pin 34): Interrupt on falling edge */
    PORT_SetPinInterruptConfig(BOARD_INITPINS_SW5_PORT, BOARD_INITPINS_SW5_PIN, kPORT_InterruptFallingEdge);

    const port_pin_config_t SW8 = {/* Internal pull-up resistor is enabled */
                                   kPORT_PullUp,
                                   /* Fast slew rate is configured */
                                   kPORT_FastSlewRate,
                                   /* Passive filter is disabled */
                                   kPORT_PassiveFilterDisable,
                                   /* Low drive strength is configured */
                                   kPORT_LowDriveStrength,
                                   /* Pin is configured as PTA15 */
                                   kPORT_MuxAsGpio};
    /* PORTA15 (pin 35) is configured as PTA15 */
    PORT_SetPinConfig(BOARD_INITPINS_SW8_PORT, BOARD_INITPINS_SW8_PIN, &SW8);

    /* Interrupt configuration on PORTA15 (pin 35): Interrupt on falling edge */
    PORT_SetPinInterruptConfig(BOARD_INITPINS_SW8_PORT, BOARD_INITPINS_SW8_PIN, kPORT_InterruptFallingEdge);

    const port_pin_config_t SW6 = {/* Internal pull-up resistor is enabled */
                                   kPORT_PullUp,
                                   /* Fast slew rate is configured */
                                   kPORT_FastSlewRate,
                                   /* Passive filter is disabled */
                                   kPORT_PassiveFilterDisable,
                                   /* Low drive strength is configured */
                                   kPORT_LowDriveStrength,
                                   /* Pin is configured as PTA16 */
                                   kPORT_MuxAsGpio};
    /* PORTA16 (pin 36) is configured as PTA16 */
    PORT_SetPinConfig(BOARD_INITPINS_SW6_PORT, BOARD_INITPINS_SW6_PIN, &SW6);

    /* Interrupt configuration on PORTA16 (pin 36): Interrupt on falling edge */
    PORT_SetPinInterruptConfig(BOARD_INITPINS_SW6_PORT, BOARD_INITPINS_SW6_PIN, kPORT_InterruptFallingEdge);

    const port_pin_config_t SW7 = {/* Internal pull-up resistor is enabled */
                                   kPORT_PullUp,
                                   /* Fast slew rate is configured */
                                   kPORT_FastSlewRate,
                                   /* Passive filter is disabled */
                                   kPORT_PassiveFilterDisable,
                                   /* Low drive strength is configured */
                                   kPORT_LowDriveStrength,
                                   /* Pin is configured as PTA17 */
                                   kPORT_MuxAsGpio};
    /* PORTA17 (pin 37) is configured as PTA17 */
    PORT_SetPinConfig(BOARD_INITPINS_SW7_PORT, BOARD_INITPINS_SW7_PIN, &SW7);

    /* Interrupt configuration on PORTA17 (pin 37): Interrupt on falling edge */
    PORT_SetPinInterruptConfig(BOARD_INITPINS_SW7_PORT, BOARD_INITPINS_SW7_PIN, kPORT_InterruptFallingEdge);

    /* PORTA19 (pin 41) is configured as PTA19 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_LED_PORT, BOARD_INITPINS_LCD_LED_PIN, kPORT_MuxAsGpio);

    PORTA->PCR[19] = ((PORTA->PCR[19] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                      /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding
                       * pin. */
                      | PORT_PCR_PE(kPORT_PullDisable));

    /* PORTA2 (pin 28) is configured as PTA2 */
    PORT_SetPinMux(BOARD_INITPINS_A_INT1_PORT, BOARD_INITPINS_A_INT1_PIN, kPORT_MuxAsGpio);

    const port_pin_config_t SW3 = {/* Internal pull-up resistor is enabled */
                                   kPORT_PullUp,
                                   /* Slow slew rate is configured */
                                   kPORT_SlowSlewRate,
                                   /* Passive filter is disabled */
                                   kPORT_PassiveFilterDisable,
                                   /* Low drive strength is configured */
                                   kPORT_LowDriveStrength,
                                   /* Pin is configured as PTA5 */
                                   kPORT_MuxAsGpio};
    /* PORTA5 (pin 31) is configured as PTA5 */
    PORT_SetPinConfig(BOARD_INITPINS_SW3_PORT, BOARD_INITPINS_SW3_PIN, &SW3);

    /* Interrupt configuration on PORTA5 (pin 31): Interrupt on falling edge */
    PORT_SetPinInterruptConfig(BOARD_INITPINS_SW3_PORT, BOARD_INITPINS_SW3_PIN, kPORT_InterruptFallingEdge);

    /* PORTB0 (pin 43) is configured as PTB0 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_XR_PORT, BOARD_INITPINS_LCD_XR_PIN, kPORT_MuxAsGpio);

    /* PORTB1 (pin 44) is configured as PTB1 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_YU_PORT, BOARD_INITPINS_LCD_YU_PIN, kPORT_MuxAsGpio);

    /* PORTB10 (pin 49) is configured as PTB10 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_RD_PORT, BOARD_INITPINS_LCD_RD_PIN, kPORT_MuxAsGpio);

    PORTB->PCR[10] = ((PORTB->PCR[10] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                      /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding
                       * pin. */
                      | PORT_PCR_PE(kPORT_PullDisable));

    /* PORTB11 (pin 50) is configured as PTB11 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_WR_PORT, BOARD_INITPINS_LCD_WR_PIN, kPORT_MuxAsGpio);

    PORTB->PCR[11] = ((PORTB->PCR[11] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                      /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding
                       * pin. */
                      | PORT_PCR_PE(kPORT_PullDisable));

    /* PORTB18 (pin 53) is configured as TPM2_CH0 */
    PORT_SetPinMux(BOARD_INITPINS_LED_RGB_BLUE_PORT, BOARD_INITPINS_LED_RGB_BLUE_PIN, kPORT_MuxAlt3);

    /* PORTB19 (pin 54) is configured as TPM2_CH1 */
    PORT_SetPinMux(BOARD_INITPINS_LED_RGB_GREEN_PORT, BOARD_INITPINS_LED_RGB_GREEN_PIN, kPORT_MuxAlt3);

    /* PORTB2 (pin 45) is configured as PTB2 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_XL_PORT, BOARD_INITPINS_LCD_XL_PIN, kPORT_MuxAsGpio);

    /* PORTB3 (pin 46) is configured as PTB3 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_YD_PORT, BOARD_INITPINS_LCD_YD_PIN, kPORT_MuxAsGpio);

    /* PORTB8 (pin 47) is configured as PTB8 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_RS_PORT, BOARD_INITPINS_LCD_RS_PIN, kPORT_MuxAsGpio);

    PORTB->PCR[8] = ((PORTB->PCR[8] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
                     | PORT_PCR_PE(kPORT_PullDisable));

    /* PORTB9 (pin 48) is configured as PTB9 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_CS_PORT, BOARD_INITPINS_LCD_CS_PIN, kPORT_MuxAsGpio);

    PORTB->PCR[9] = ((PORTB->PCR[9] &
                      /* Mask bits to zero which are setting */
                      (~(PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                     /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding pin. */
                     | PORT_PCR_PE(kPORT_PullDisable));

    /* PORTC0 (pin 55) is configured as ADC0_SE14 */
    PORT_SetPinMux(PORTC, 0U, kPORT_PinDisabledOrAnalog);

    /* PORTC1 (pin 56) is configured as ADC0_SE15 */
    PORT_SetPinMux(PORTC, 1U, kPORT_PinDisabledOrAnalog);

    /* PORTC12 (pin 69) is configured as PTC12 */
    PORT_SetPinMux(BOARD_INITPINS_LED_1_PORT, BOARD_INITPINS_LED_1_PIN, kPORT_MuxAsGpio);

    /* PORTC13 (pin 70) is configured as PTC13 */
    PORT_SetPinMux(BOARD_INITPINS_LED_2_PORT, BOARD_INITPINS_LED_2_PIN, kPORT_MuxAsGpio);

    /* PORTC2 (pin 57) is configured as ADC0_SE11 */
    PORT_SetPinMux(PORTC, 2U, kPORT_PinDisabledOrAnalog);

    /* PORTC3 (pin 58) is configured as UART1_RX */
    PORT_SetPinMux(PORTC, 3U, kPORT_MuxAlt3);

    /* PORTC4 (pin 61) is configured as UART1_TX */
    PORT_SetPinMux(PORTC, 4U, kPORT_MuxAlt3);

    /* PORTC6 (pin 63) is configured as PTC6 */
    PORT_SetPinMux(BOARD_INITPINS_LED_4_PORT, BOARD_INITPINS_LED_4_PIN, kPORT_MuxAsGpio);

    /* PORTC7 (pin 64) is configured as PTC7 */
    PORT_SetPinMux(BOARD_INITPINS_LED_3_PORT, BOARD_INITPINS_LED_3_PIN, kPORT_MuxAsGpio);

    /* PORTC8 (pin 65) is configured as TPM0_CH4 */
    PORT_SetPinMux(BOARD_INITPINS_BUZZER_EN_PORT, BOARD_INITPINS_BUZZER_EN_PIN, kPORT_MuxAlt3);

    /* PORTC9 (pin 66) is configured as TPM0_CH5 */
    PORT_SetPinMux(BOARD_INITPINS_LED_RGB_RED_PORT, BOARD_INITPINS_LED_RGB_RED_PIN, kPORT_MuxAlt3);

    /* PORTD0 (pin 73) is configured as PTD0 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_DATA0_PORT, BOARD_INITPINS_LCD_DATA0_PIN, kPORT_MuxAsGpio);

    /* PORTD1 (pin 74) is configured as PTD1 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_DATA1_PORT, BOARD_INITPINS_LCD_DATA1_PIN, kPORT_MuxAsGpio);

    /* PORTD2 (pin 75) is configured as PTD2 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_DATA2_PORT, BOARD_INITPINS_LCD_DATA2_PIN, kPORT_MuxAsGpio);

    /* PORTD3 (pin 76) is configured as PTD3 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_DATA3_PORT, BOARD_INITPINS_LCD_DATA3_PIN, kPORT_MuxAsGpio);

    /* PORTD4 (pin 77) is configured as PTD4 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_DATA4_PORT, BOARD_INITPINS_LCD_DATA4_PIN, kPORT_MuxAsGpio);

    /* PORTD5 (pin 78) is configured as PTD5 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_DATA5_PORT, BOARD_INITPINS_LCD_DATA5_PIN, kPORT_MuxAsGpio);

    /* PORTD6 (pin 79) is configured as PTD6 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_DATA6_PORT, BOARD_INITPINS_LCD_DATA6_PIN, kPORT_MuxAsGpio);

    /* PORTD7 (pin 80) is configured as PTD7 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_DATA7_PORT, BOARD_INITPINS_LCD_DATA7_PIN, kPORT_MuxAsGpio);

    /* PORTE22 (pin 15) is configured as UART2_TX */
    PORT_SetPinMux(PORTE, 22U, kPORT_MuxAlt4);

    /* PORTE23 (pin 16) is configured as UART2_RX */
    PORT_SetPinMux(PORTE, 23U, kPORT_MuxAlt4);

    /* PORTE24 (pin 24) is configured as I2C0_SCL */
    PORT_SetPinMux(BOARD_INITPINS_A_SCL_PORT, BOARD_INITPINS_A_SCL_PIN, kPORT_MuxAlt5);

    /* PORTE25 (pin 25) is configured as I2C0_SDA */
    PORT_SetPinMux(BOARD_INITPINS_A_SDA_PORT, BOARD_INITPINS_A_SDA_PIN, kPORT_MuxAlt5);

    /* PORTE29 (pin 21) is configured as PTE29 */
    PORT_SetPinMux(BOARD_INITPINS_SERVO1_PORT, BOARD_INITPINS_SERVO1_PIN, kPORT_MuxAsGpio);

    /* PORTE30 (pin 22) is configured as PTE30 */
    PORT_SetPinMux(BOARD_INITPINS_SERVO2_PORT, BOARD_INITPINS_SERVO2_PIN, kPORT_MuxAsGpio);

    /* PORTE31 (pin 23) is configured as PTE31 */
    PORT_SetPinMux(BOARD_INITPINS_LCD_RST_PORT, BOARD_INITPINS_LCD_RST_PIN, kPORT_MuxAsGpio);

    PORTE->PCR[31] = ((PORTE->PCR[31] &
                       /* Mask bits to zero which are setting */
                       (~(PORT_PCR_PE_MASK | PORT_PCR_ISF_MASK)))

                      /* Pull Enable: Internal pullup or pulldown resistor is not enabled on the corresponding
                       * pin. */
                      | PORT_PCR_PE(kPORT_PullDisable));

    SIM->SOPT4 = ((SIM->SOPT4 &
                   /* Mask bits to zero which are setting */
                   (~(SIM_SOPT4_TPM2CH0SRC_MASK)))

                  /* TPM2 channel 0 input capture source select: TPM2_CH0 signal. */
                  | SIM_SOPT4_TPM2CH0SRC(SOPT4_TPM2CH0SRC_TPM2_CH0));

    SIM->SOPT5 = ((SIM->SOPT5 &
                   /* Mask bits to zero which are setting */
                   (~(SIM_SOPT5_UART1TXSRC_MASK | SIM_SOPT5_UART1RXSRC_MASK)))

                  /* UART1 transmit data source select: UART1_TX pin. */
                  | SIM_SOPT5_UART1TXSRC(SOPT5_UART1TXSRC_UART_TX)

                  /* UART1 receive data source select: UART1_RX pin. */
                  | SIM_SOPT5_UART1RXSRC(SOPT5_UART1RXSRC_UART_RX));
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/