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

adc_result_t ana0, ana1;
volatile bool disp_tick = false;
char buff1[128];

void display_led(DISPLAY_TYPES led);

void Led_Blink(void)
{
	LED_E0_Toggle();
	disp_tick = true;
}

/*
			 Main application
 */
void main(void)
{
	uint8_t dac_v = 1;
	// Initialize the device
	SYSTEM_Initialize();

	TMR6_SetInterruptHandler(Led_Blink);
	TMR5_SetInterruptHandler(Timers_Isr);

	// Enable high priority global interrupts
	INTERRUPT_GlobalInterruptHighEnable();

	// Enable low priority global interrupts.
	//INTERRUPT_GlobalInterruptLowEnable();

	DAC1_SetOutput(dac_v);

	while (true) {
		// Add your application code
		ADCC_StartConversion(channel_ANA0);
		do {
		} while (!ADCC_IsConversionDone());
		ana0 = ADCC_GetConversionResult();

		ADCC_StartConversion(channel_ANA1);
		do {
		} while (!ADCC_IsConversionDone());
		ana1 = ADCC_GetConversionResult();

		if (ana0 < 900) {
			display_led(oo00_off);
			display_led(oo30_off);
		} else {
			if (ana0 > 2500) {
				display_led(oo00_g);
				display_led(oo30_g);
			} else {
				display_led(oo00_r);
				display_led(oo30_r);
			}
		}

		if (ana1 < 900) {
			display_led(oo10_off);
			display_led(oo20_off);
		} else {
			if (ana1 > 2500) {
				display_led(oo10_g);
				display_led(oo20_g);
			} else {
				display_led(oo10_r);
				display_led(oo20_r);
			}
		}

		if (disp_tick) {
			sprintf(buff1, "E220 %4u %4u \r\n", ana0, ana1);
			puts(buff1);
			DAC1_SetOutput(++dac_v);
			disp_tick = false;
		}
	}
}


/**
 End of File
 */