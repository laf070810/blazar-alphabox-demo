/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.io/license.html
 */

#ifndef _GDISP_LLD_BOARD_H
#define _GDISP_LLD_BOARD_H

#include "blazar_lcd.h"

static GFXINLINE void init_board(GDisplay *g) {
	GPIO_LCDPinsInit();
}

static GFXINLINE void post_init_board(GDisplay *g) {
	(void) g;
}

static GFXINLINE void setpin_reset(GDisplay *g, gBool state) {
	if (state)
	{
		LCD_RST_CLR;
	}
	else
	{
		LCD_RST_SET;
	}
}

static GFXINLINE void set_backlight(GDisplay *g, gU8 percent) {
	LCD_LED_CLR;
}

static GFXINLINE void acquire_bus(GDisplay *g) {
	(void) g;
}

static GFXINLINE void release_bus(GDisplay *g) {
	(void) g;
}

static GFXINLINE void write_index(GDisplay *g, gU16 index) {
	LCD_WR_REG(index);
}

static GFXINLINE void write_data(GDisplay *g, gU16 data) {
	LCD_WR_DATA(data);  
}

static GFXINLINE void setreadmode(GDisplay *g) {
	GPIO_ConfigLCDDataPins(0);
}

static GFXINLINE void setwritemode(GDisplay *g) {
	GPIO_ConfigLCDDataPins(1);
}

static GFXINLINE gU16 read_data(GDisplay *g) {
	return GPIO_ReadLCDDataPins();
}

#endif /* _GDISP_LLD_BOARD_H */
