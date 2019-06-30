/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.io/license.html
 */

#ifndef _GDISP_LLD_TOGGLE_BOARD_H
#define _GDISP_LLD_TOGGLE_BOARD_H

#include "fsl_gpio.h"
#include "pin_mux.h"

#define GINPUT_TOGGLE_NUM_PORTS			8			// The total number of toggle inputs
#define GINPUT_TOGGLE_CONFIG_ENTRIES	1			// The total number of GToggleConfig entries

#define GINPUT_TOGGLE_L_UP				1		// Joystick Up
#define GINPUT_TOGGLE_L_DOWN			12				// Joystick Down
#define GINPUT_TOGGLE_L_LEFT			5				// Joystick Left
#define GINPUT_TOGGLE_L_RIGHT			13				// Joystick Right
#define GINPUT_TOGGLE_R_UP				14				// Joystick Up
#define GINPUT_TOGGLE_R_DOWN			16				// Joystick Down
#define GINPUT_TOGGLE_R_LEFT			17				// Joystick Left
#define GINPUT_TOGGLE_R_RIGHT			15				// Joystick Right

#define GINPUT_TOGGLE_DECLARE_STRUCTURE()														\
	const GToggleConfig GInputToggleConfigTable[GINPUT_TOGGLE_CONFIG_ENTRIES] = {				\
		{GPIOA,																					\
			GINPUT_TOGGLE_L_UP|GINPUT_TOGGLE_L_DOWN|GINPUT_TOGGLE_L_LEFT|GINPUT_TOGGLE_L_RIGHT|GINPUT_TOGGLE_R_UP|GINPUT_TOGGLE_R_DOWN|GINPUT_TOGGLE_R_LEFT|GINPUT_TOGGLE_R_RIGHT,\
			0,																					\
			0}																					\
	}

#endif /* _GDISP_LLD_TOGGLE_BOARD_H */
