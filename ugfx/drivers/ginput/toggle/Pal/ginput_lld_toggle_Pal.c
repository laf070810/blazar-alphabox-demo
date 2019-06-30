/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.io/license.html
 */

#include "gfx.h"

#if (GFX_USE_GINPUT && GINPUT_NEED_TOGGLE) /*|| defined(__DOXYGEN__)*/

#include "../../../../src/ginput/ginput_driver_toggle.h"

GINPUT_TOGGLE_DECLARE_STRUCTURE();

void ginput_lld_toggle_init(const GToggleConfig *ptc) {
	
}

unsigned ginput_lld_toggle_getbits(const GToggleConfig *ptc) {
	return GPIOA->PDIR;
}

#endif /* GFX_USE_GINPUT && GINPUT_NEED_TOGGLE */
