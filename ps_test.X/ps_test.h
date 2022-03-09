/* 
 * File:   ps_test.h
 * Author: root
 *
 * Created on February 13, 2022, 1:47 PM
 */

#ifndef PS_TEST_H
#define	PS_TEST_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "mcc_generated_files/mcc.h"
#include "timers.h"
#include "disp_led.h"
#include "mcc_generated_files/adcc.h"

#define MAX_ADC_CHAN	2
#define STATIC_PS	20
#define ROLL_MAX	19
	
#define	V_SCALE		0.405194
#define I_SCALE		0.004
	
	extern const char *build_date, *build_time;

	typedef enum {
		off_mode,
		roll_mode,
		static_mode,
	} MODE_TYPES;
#ifdef	__cplusplus
}
#endif

#endif	/* PS_TEST_H */

