/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "Blazar_shell.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void vTaskShell(void *pvParameters);

/*******************************************************************************
 * Variables
 ******************************************************************************/
static TaskHandle_t xHandleTaskShell; 

/*******************************************************************************
 * Code
 ******************************************************************************/
void SHELL_SendDataCallback(uint8_t *buf, uint32_t len)
{
    while (len--)
    {
        PUTCHAR(*(buf++));
    }
}

void SHELL_ReceiveDataCallback(uint8_t *buf, uint32_t len)
{
    while (len--)
    {
        *(buf++) = GETCHAR();
    }
}

static void vTaskShell(void *pvParameters)
{
	shell_context_struct user_context;
	
	/* Init SHELL */
    SHELL_Init(&user_context, SHELL_SendDataCallback, SHELL_ReceiveDataCallback, SHELL_Printf, "SHELL>> ");

    /* Add new command to commands list */
    SHELL_RegisterCommand(&xHelloCommand);
	SHELL_RegisterCommand(&xBuzzerCommand);
	SHELL_RegisterCommand(&xLedCommand);
	SHELL_RegisterCommand(&xSwitchCommand);
	SHELL_RegisterCommand(&xAdcCommand);
	SHELL_RegisterCommand(&xSegCommand);
	SHELL_RegisterCommand(&xAccelCommand);
	SHELL_RegisterCommand(&xHomeworkCommand);
	SHELL_RegisterCommand(&xResetCommand);

    SHELL_Main(&user_context);
}

void SHELL_Open(void)
{
	xTaskCreate(vTaskShell, "TaskShell", configMINIMAL_STACK_SIZE + 256, NULL, 1, &xHandleTaskShell);
}
