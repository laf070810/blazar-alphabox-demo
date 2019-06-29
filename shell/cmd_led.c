/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Blazar_shell.h"
#include "Blazar_LED.h"
#include <stdlib.h>
 
 /*******************************************************************************
 * Definitions
 ******************************************************************************/


 /*******************************************************************************
 * Variables
 ******************************************************************************/
static bool Initialized = false;

 /*******************************************************************************
 * Prototypes
 ******************************************************************************/


 /*******************************************************************************
 * Code
 ******************************************************************************/
int32_t do_led(p_shell_context_t context, int32_t argc, char **argv)
{
	if (argc == 1)
	{
		if (Initialized)
		{
			LED_Deinit();
			PRINTF("LED is off. \r\n\r\n");
			Initialized = false;
		}
		else
		{
			LED_Init();
			LED_SetMode(1);
			PRINTF("LED is on. \r\n\r\n");
			Initialized = true;
		}
		
		return 0;
	}
	if (argc == 2)
	{
		LED_SetMode(atoi(argv[1]));
		PRINTF("LED is set to mode %s. \r\n\r\n", argv[1]);
		
		return 0;
	}
	if (argc == 5)
	{
		uint8_t Color[3] = {atoi(argv[2]), atoi(argv[3]), atoi(argv[4])};
		LED_Set(atoi(argv[1]), Color);
		PRINTF("LED is set. \r\n\r\n");
		
		return 0;
	}
	
	PRINTF("Error: Unknown option. \r\n\r\n");
	return 1;
}
