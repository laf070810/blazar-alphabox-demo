#ifndef _BLAZAR_SHELL_H_
#define _BLAZAR_SHELL_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "fsl_shell.h"
#include "fsl_debug_console.h"

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define SHELL_Printf PRINTF

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
int32_t do_hello(p_shell_context_t context, int32_t argc, char **argv);
int32_t do_led(p_shell_context_t context, int32_t argc, char **argv);
int32_t do_buzzer(p_shell_context_t context, int32_t argc, char **argv);
int32_t do_switch(p_shell_context_t context, int32_t argc, char **argv);
int32_t do_adc(p_shell_context_t context, int32_t argc, char **argv);
int32_t do_seg(p_shell_context_t context, int32_t argc, char **argv);
int32_t do_accel(p_shell_context_t context, int32_t argc, char **argv);
int32_t do_homework(p_shell_context_t context, int32_t argc, char **argv);
int32_t do_reset(p_shell_context_t context, int32_t argc, char **argv);

/*******************************************************************************
 * Variables
 ******************************************************************************/
static const shell_command_context_t xHelloCommand = {"hello",
                                                    "\r\n\"hello\": Display hello\r\n",
                                                    do_hello, 0};

static const shell_command_context_t xLedCommand = {"led",
                                                    "\r\n\"led\": Control the LEDs\r\n",
                                                    do_led, 4};

static const shell_command_context_t xBuzzerCommand = {"buzzer",
                                                    "\r\n\"buzzer\": Control the buzzer\r\n",
                                                    do_buzzer, 4};

static const shell_command_context_t xSwitchCommand = {"switch",
                                                    "\r\n\"switch\": Control the switches\r\n",
                                                    do_switch, 0};

static const shell_command_context_t xAdcCommand = {"adc",
                                                    "\r\n\"adc\": Control the adc\r\n",
                                                    do_adc, 3};

static const shell_command_context_t xSegCommand = {"seg",
                                                    "\r\n\"seg\": Control the 7-seg\r\n",
                                                    do_seg, 3};

static const shell_command_context_t xAccelCommand = {"accel",
                                                    "\r\n\"accel\": Control the accelerometer\r\n",
                                                    do_accel, 3};

static const shell_command_context_t xHomeworkCommand = {"homework",
                                                    "\r\n\"homework\": For homework\r\n",
                                                    do_homework, 3};

static const shell_command_context_t xResetCommand = {"reset",
                                                    "\r\n\"reset\": Reset the system\r\n",
                                                    do_reset, 3};

/*******************************************************************************
 * API
 ******************************************************************************/
/* SHELL user send data callback */
void SHELL_SendDataCallback(uint8_t *buf, uint32_t len);

/* SHELL user receive data callback */
void SHELL_ReceiveDataCallback(uint8_t *buf, uint32_t len);

/*!
 * @brief Open a shell.
 */
void SHELL_Open(void);

#endif /* _BLAZAR_SHELL_H_ */
