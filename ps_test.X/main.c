/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
	Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
	Device            :  PIC18F57K42
	Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#pragma warning disable 520
#pragma warning disable 1498 

#include "ps_test.h"
#include "scdm.h"

volatile adc_result_t ana[MAX_ADC_CHAN];
volatile bool disp_tick = false, adc_tick = false;
volatile uint8_t adc_chan = 0;
char buff1[255];
extern t_cli_ctx cli_ctx; // command buffer 
const char *build_date = __DATE__, *build_time = __TIME__;
MODE_TYPES mode = roll_mode;
double vval = 0.0, ival = 0.0;

void display_led(DISPLAY_TYPES led);

/*
 * 1/4 second trigger interrupt
 * TMR6
 * 
 * Blink LED and set flag
 */
void Led_Blink(void)
{
	LED_RESET_Toggle();
	/*
	 * xmit serial data flag
	 */
	disp_tick = true;
}

/*
 * ADC conversion complete interrupt routine
 * conversion start triggered by TMR5 interrupt
 * 
 * move conversion data into program data array
 * set flag
 */
void Adc_Isr(void)
{
	ana[adc_chan] = ADCC_GetConversionResult();
	if (adc_chan++ >= MAX_ADC_CHAN) {
		adc_chan = 0;
	}
	ADPCH = adc_chan;
	/*
	 * adc value valid flag
	 */
	adc_tick = true;
}

void fh_hw(void *a_data)
{
	puts((const char *) a_data);
}

void fh_hi(void *a_data)
{
	puts(" hi      ");
}

void fh_ho(void *a_data)
{
	puts(" ho      ");
}

/*
			 Main application
 */
void main(void)
{
	uint8_t dac_v = 0, mode_sw = 0;
	// Initialize the device
	SYSTEM_Initialize();

	LED_MODE_SetLow();
	LED_DB_SetLow();
	TMR6_SetInterruptHandler(Led_Blink);
	TMR5_SetInterruptHandler(Timers_Isr);
	ADCC_SetADIInterruptHandler(Adc_Isr);
	ADPCH = adc_chan;

	/*
	 * init serial command parser on USART
	 */
	scmd_init();

	// Enable high priority global interrupts
	INTERRUPT_GlobalInterruptHighEnable();

	// Enable low priority global interrupts.
	//INTERRUPT_GlobalInterruptLowEnable();

	DAC1_SetOutput(dac_v);

	while (true) {
		if (adc_tick) {
			if (ana[0] < 900) {
				display_led(oo00_off);
				display_led(oo30_off);
			} else {
				if (ana[0] > 1800) {
					display_led(oo00_g);
					display_led(oo30_g);
				} else {
					display_led(oo00_r);
					display_led(oo30_r);
				}
			}

			if (ana[1] < 50) {
				display_led(oo10_off);
				display_led(oo20_off);
			} else {
				if (ana[1] > 150) {
					display_led(oo10_g);
					display_led(oo20_g);
				} else {
					display_led(oo10_r);
					display_led(oo20_r);
				}
			}
			adc_tick = false;

			if (disp_tick) {
				vval = (double) ana[0] * V_SCALE;
				ival = (double) ana[1] * I_SCALE;
				printf(" PS Test %1u: DAC OUT=%2u, Supply ReadBack %4u V=%+5.1fV %4u I=%+3.1fmA\r\n", mode, (uint16_t) DAC1_GetOutput(), ana[0], vval, ana[1], ival);
//				puts(buff1);

				switch (mode) {
				case roll_mode:
					if (dac_v > ROLL_MAX) {
						dac_v = 0;
					}
					DAC1_SetOutput(++dac_v);
					LED_MODE_SetHigh();
					break;
				case static_mode:
					dac_v = STATIC_PS;
					DAC1_SetOutput(dac_v);
					LED_MODE_SetHigh();
					break;
				case off_mode:
				default:
					mode = off_mode;
					dac_v = 0;
					DAC1_SetOutput(dac_v);
					LED_MODE_SetLow();
					break;
				}

				/*
				 * read serial port for command data
				 * check mode switch
				 */
				cli_read(&cli_ctx);
				disp_tick = false;
				if (!MODESW_RB0_GetValue()) {
					if (++mode_sw > 4) {
						mode++;
						mode_sw = 0;
					}
				} else {
					mode_sw = 0;
				}
			}
		}
	}
}

/**
 End of File
 */