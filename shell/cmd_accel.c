/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Blazar_shell.h"
#include "Blazar_accelerometer.h"
#include <stdlib.h>
 
 /*******************************************************************************
 * Definitions
 ******************************************************************************/


 /*******************************************************************************
 * Variables
 ******************************************************************************/


 /*******************************************************************************
 * Prototypes
 ******************************************************************************/


 /*******************************************************************************
 * Code
 ******************************************************************************/
int32_t do_accel(p_shell_context_t context, int32_t argc, char **argv)
{
	if (argc == 1)
	{
		uint16_t buff[3];
		ACCEL_Read(buff);
		PRINTF("%d %d %d\r\n\r\n", buff[0], buff[1], buff[2]);
		
		return 0;
	}
	
	PRINTF("Error: Unknown option. \r\n\r\n");
	return 1;
}