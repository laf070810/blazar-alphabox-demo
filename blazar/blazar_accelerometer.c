/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "blazar_accelerometer.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/


/*******************************************************************************
 * Variables
 ******************************************************************************/
static i2c_rtos_handle_t master_rtos_handle;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/


/*******************************************************************************
 * Code
 ******************************************************************************/
void ACCEL_Init(void)
{
    i2c_master_config_t masterConfig;
    uint32_t sourceClock;
    status_t status;
	
	/*
     * masterConfig.baudRate_Bps = 100000U;
     * masterConfig.enableStopHold = false;
     * masterConfig.glitchFilterWidth = 0U;
     * masterConfig.enableMaster = true;
     */
    I2C_MasterGetDefaultConfig(&masterConfig);
    masterConfig.baudRate_Bps = I2C_BAUDRATE;
    sourceClock = EXAMPLE_I2C_MASTER_CLK_FREQ;

    status = I2C_RTOS_Init(&master_rtos_handle, EXAMPLE_I2C_MASTER, &masterConfig, sourceClock);
    if (status != kStatus_Success)
    {
        PRINTF("I2C master: error during init, %d", status);
    }
}

void ACCEL_WriteRegister(uint8_t RegisterAddress, uint8_t Data)
{
	i2c_master_transfer_t masterXfer;
	status_t status;
	
	masterXfer.slaveAddress = I2C_MASTER_SLAVE_ADDR_7BIT;
    masterXfer.direction = kI2C_Write;
    masterXfer.subaddress = RegisterAddress;
    masterXfer.subaddressSize = 1;
    masterXfer.data = &Data;
    masterXfer.dataSize = 1;
    masterXfer.flags = kI2C_TransferDefaultFlag;
	
    status = I2C_RTOS_Transfer(&master_rtos_handle, &masterXfer);
    if (status != kStatus_Success)
    {
        PRINTF("I2C master: error during write transaction, %d", status);
    }
}

uint8_t ACCEL_ReadRegister(uint8_t RegisterAddress)
{
	i2c_master_transfer_t masterXfer;
	status_t status;
	uint8_t buff[1];
	
	masterXfer.slaveAddress = I2C_MASTER_SLAVE_ADDR_7BIT;
    masterXfer.direction = kI2C_Read;
    masterXfer.subaddress = RegisterAddress;
    masterXfer.subaddressSize = 1;
    masterXfer.data = buff;
    masterXfer.dataSize = 1;
    masterXfer.flags = kI2C_TransferDefaultFlag;

    status = I2C_RTOS_Transfer(&master_rtos_handle, &masterXfer);
    if (status != kStatus_Success)
    {
        PRINTF("I2C master: error during read transaction, %d", status);
    }
	
	return buff[0];
}

void ACCEL_Read(uint16_t * buf)
{
	ACCEL_WriteRegister(0x2A, 0x01);
	
	buf[0] = ACCEL_ReadRegister(0x01) * 256 + ACCEL_ReadRegister(0x02);
	buf[1] = ACCEL_ReadRegister(0x03) * 256 + ACCEL_ReadRegister(0x04);
	buf[2] = ACCEL_ReadRegister(0x05) * 256 + ACCEL_ReadRegister(0x06);
}
