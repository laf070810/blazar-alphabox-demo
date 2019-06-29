/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Blazar_shell.h"
#include "Blazar_Buzzer.h"
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
int32_t do_buzzer(p_shell_context_t context, int32_t argc, char **argv)
{
	if (argc == 1)
	{
		if (Initialized)
		{
			BUZZER_Deinit();
			PRINTF("Buzzer is deinitialized. \r\n\r\n");
			Initialized = false;
		}
		else
		{
			BUZZER_Init();
			PRINTF("Buzzer is initialized. \r\n\r\n");
			Initialized = true;
		}
		
		return 0;
	}
	if (argc == 2)
	{
		BUZZER_Play(atoi(argv[1]));
		PRINTF("Playing song %s\r\n\r\n", argv[1]);
		
		return 0;
	}
	if (argc == 3)
	{
		BUZZER_Set(atoi(argv[1]), atoi(argv[2]));
		PRINTF("Buzzer is set. \r\n\r\n");
		
		return 0;
	}
	
	PRINTF("Error: Unknown option. \r\n\r\n");
	return 1;
}
