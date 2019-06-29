#ifndef _ACCELEROMETER_H_
#define _ACCELEROMETER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fsl_i2c_freertos.h"
#include "fsl_debug_console.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_I2C_MASTER_BASE (I2C0_BASE)
#define EXAMPLE_I2C_MASTER_IRQN (I2C0_IRQn)
#define EXAMPLE_I2C_MASTER_CLK_SRC (I2C0_CLK_SRC)
#define EXAMPLE_I2C_MASTER_CLK_FREQ CLOCK_GetFreq((I2C0_CLK_SRC))

#define EXAMPLE_I2C_MASTER ((I2C_Type *)EXAMPLE_I2C_MASTER_BASE)

#define I2C_MASTER_SLAVE_ADDR_7BIT (0x1DU)
#define I2C_BAUDRATE (100000) /* 100K */

/*******************************************************************************
 * Variables
 ******************************************************************************/


/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief Init the accelerometer.
 *
 */
void ACCEL_Init(void);

/*!
 * @brief Write a byte of Data to specified register on MMA8451Q
 *
 * @param RegisterAddress    The register address
 * @param Data               The data to write
 */
void ACCEL_WriteRegister(uint8_t RegisterAddress, uint8_t Data);

/*!
 * @brief  Read a register from the MMA8451Q
 *
 * @param  RegisterAddress     The register address
 * @return Data stored in Register
 */
uint8_t ACCEL_ReadRegister(uint8_t RegisterAddress);

/*!
 * @brief Read the accelerometer.
 *
 * @param buf    An array consisting of 3 elements the store the acceleration readout. The 3 elements correspond to 3 directions: [X, Y, Z]. 
 */
void ACCEL_Read(uint16_t * buf);

#endif /* _ACCELEROMETER_H_ */
