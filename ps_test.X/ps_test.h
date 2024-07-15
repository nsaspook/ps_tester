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
#include "eadog.h"
#include "mydisplay.h"
#include "ringbufs.h"

#define MAX_ADC_CHAN	channel_FVR_Buffer2
#define MAX_ADC_BUFFER	32
#define STATIC_PS	20
#define ROLL_MAX	19

#define EECKSUM		0x00
#define EEPSDATA	0x10

#define ESS		0
#define ASS		1


	/*
	 * electrical unit scaling for various power supplies
	 */
#define	V_SCALE_0		0.405194
#define I_SCALE_0		0.004
#define	V_SCALE_1		0.810
#define I_SCALE_1		0.004
#define	V_SCALE_2		0.405194
#define I_SCALE_2		0.004
#define	V_SCALE_3		0.405194
#define I_SCALE_3		0.004
#define	V_SCALE_4		0.405194
#define I_SCALE_4		0.004

#define EADOGM_CMD_CLR		1
#define EADOGM_CMD_CURSOR_ON     0b00001111
#define EADOGM_CMD_CURSOR_OFF    0b00001100
#define EADOGM_CMD_DISPLAY_ON    0b00001100
#define EADOGM_CMD_DISPLAY_OFF   0b00001000
#define EADOGM_CMD_DDRAM_ADDR    0b10000000
#define EADOGM_CMD_CGRAM_ADDR    0b01000000
#define EADOGM_CMD_SELECT_R0     0b00011000
#define EADOGM_CMD_SELECT_R1     0b00010000
#define EADOGM_CMD_SET_TABLE2    0b00101010
#define EADOGM_COLSPAN		16	
#define NHD

	extern const char *build_date, *build_time;
	const char build_version[] = "V1.02 PS TEST";

	typedef enum {
		off_mode,
		roll_mode,
		static_mode,
	} MODE_TYPES;

	typedef struct PS_TYPE {
		double v_scale;
		double i_scale;
	} PS_TYPE;

	typedef struct ADC_BUFFER_TYPE {
		adc_result_t ana[MAX_ADC_CHAN];
	} ADC_BUFFER_TYPE;

	extern char buff1[255];
	void ps_math(double, adcc_channel_t);
	void clear_stat_buffer(adcc_channel_t);
#ifdef	__cplusplus
}
#endif

#endif	/* PS_TEST_H */

