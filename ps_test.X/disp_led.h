/* 
 * File:   disp_led.h
 * Author: root
 *
 * Created on February 15, 2022, 1:17 PM
 */

#ifndef DISP_LED_H
#define	DISP_LED_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "ps_test.h"

	typedef enum {
		oo00_off,
		oo00_g,
		oo00_r,
		oo10_off,
		oo10_g,
		oo10_r,
		oo20_off,
		oo20_g,
		oo20_r,
		oo30_off,
		oo30_g,
		oo30_r,
		oooff,
	} DISPLAY_TYPES;

void display_led(DISPLAY_TYPES);

#ifdef	__cplusplus
}
#endif

#endif	/* DISP_LED_H */

