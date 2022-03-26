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
char buff1[255];
extern t_cli_ctx cli_ctx; // command buffer 
const char *build_date = __DATE__, *build_time = __TIME__;
MODE_TYPES mode = off_mode;
double vval = 0.0, ival = 0.0;
uint8_t dac_v = 0, mode_sw = 0, roll_max = ROLL_MAX, static_ps = STATIC_PS;
PS_TYPE ps_type[] = {
	{
		.v_scale = V_SCALE_0,
		.i_scale = I_SCALE_0,
	},
	{
		.v_scale = V_SCALE_1,
		.i_scale = I_SCALE_1,
	},
	{
		.v_scale = V_SCALE_2,
		.i_scale = I_SCALE_2,
	},
	{
		.v_scale = V_SCALE_3,
		.i_scale = I_SCALE_3,
	},
	{
		.v_scale = V_SCALE_4,
		.i_scale = I_SCALE_4,
	},
};

PS_TYPE *ps_type_ptr = ps_type;
volatile uint8_t ps_type_index = ESS;

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
	static adcc_channel_t c_adc_chan = PS_V_ANA;

	ana[c_adc_chan] = ADCC_GetConversionResult();

	/*
	 * convert ADC channels to ADC data array values
	 */
	switch (c_adc_chan) {
	case PS_V_ANA:
		c_adc_chan = PS_I_ANA;
		break;
	case PS_I_ANA:
		c_adc_chan = channel_DAC1;
		break;
	case channel_DAC1:
		c_adc_chan = PWM5_ANA;
		break;
	case PWM5_ANA:
		c_adc_chan = PWM6_ANA;
		break;
	case PWM6_ANA:
		c_adc_chan = PS_V_ANA;
		break;
	default:
		c_adc_chan = PS_V_ANA;
		break;
	}
	ADPCH = c_adc_chan;
	/*
	 * adc value valid flag
	 */
	adc_tick = true;
}

/*
 * Serial command functions
 */
void fh_pr(void *a_data)
{
	puts((const char *) a_data);
	puts("\r\n Ramp to 1000VDC ON \r\n");
	mode = roll_mode;
}

void fh_ps(void *a_data)
{
	puts("\r\n Steady 1000VDC ON \r\n");
	roll_max = ROLL_MAX;
	static_ps = STATIC_PS;
	mode = static_mode;
}

void fh_po(void *a_data)
{
	puts("\r\n Voltage OFF \r\n");
	mode = off_mode;
}

void fh_pp(void *a_data)
{
	puts("\r\n Voltage ON \r\n");
	mode = static_mode;
}

void fh_pu(void *a_data)
{
	puts("\r\n Voltage UP \r\n");
	roll_max = ROLL_MAX + 10;
	static_ps = STATIC_PS + 11;
}

void fh_pd(void *a_data)
{
	puts("\r\n Voltage DOWN \r\n");
	roll_max = ROLL_MAX - 12;
	static_ps = STATIC_PS - 12;
}

void fh_pl(void *a_data)
{
	puts("\r\n Voltage LOW \r\n");
	roll_max = 2;
	static_ps = 3;
}

void fh_p0(void *a_data)
{
	puts("\r\n EXT Suppression Supply \r\n");
	ps_type_index = ESS;
	DATAEE_WriteByte(EEPSDATA, ps_type_index);
}

void fh_p1(void *a_data)
{
	puts("\r\n ACCEL Suppression Supply \r\n");
	ps_type_index = ASS;
	DATAEE_WriteByte(EEPSDATA, ps_type_index);
}

/*
	     Main application
 */
void main(void)
{
	uint8_t lcd_update = 0, i = 0;

	// Initialize the device
	SYSTEM_Initialize();

	LED_MODE_SetLow();
	LED_DB_SetLow();
	TMR6_SetInterruptHandler(Led_Blink);
	TMR5_SetInterruptHandler(Timers_Isr);
	ADCC_SetADIInterruptHandler(Adc_Isr);
	ADPCH = PS_V_ANA;
	PWM5_LoadDutyValue(0); // set PS signals to zero
	PWM6_LoadDutyValue(0);
	DMA1_SetSCNTIInterruptHandler(source_dma_done);

	// Enable high priority global interrupts
	INTERRUPT_GlobalInterruptHighEnable();

	// Enable low priority global interrupts.
	INTERRUPT_GlobalInterruptLowEnable();

	DAC1_SetOutput(dac_v);

	init_display();
	eaDogM_CursorOff();
	eaDogM_WriteString("SPI display testing");
	/*
	 * init serial command parser on USART
	 */
	while (linux_getc(&i)); // clear receive buffer and fifo
	scmd_init();
	sprintf(buff1, "\r\n Build %s %s\r\n", build_date, build_time);
	puts(buff1);

	if (DATAEE_ReadByte(EECKSUM) != '1') {
		DATAEE_WriteByte(EECKSUM, '1');
		DATAEE_WriteByte(EECKSUM + 1, '9');
		DATAEE_WriteByte(EECKSUM + 2, '5');
		DATAEE_WriteByte(EECKSUM + 3, '7');
		DATAEE_WriteByte(EEPSDATA, ESS); // default power supply type
	} else {
		ps_type_index = DATAEE_ReadByte(EEPSDATA); // read power supply type
	}

	while (true) {
		if (adc_tick) {
			if (ana[PS_V_ANA] < 900) {
				display_led(oo00_off);
			} else {
				if (ana[PS_V_ANA] > 1800) {
					display_led(oo00_g);
				} else {
					display_led(oo00_r);
				}
			}

			if (ana[PS_I_ANA] < 50) {
				display_led(oo10_off);
			} else {
				if (ana[PS_I_ANA] > 150) {
					display_led(oo10_g);
				} else {
					display_led(oo10_r);
				}
			}
			adc_tick = false;

			if (!OVERLOAD_GetValue()) {
				display_led(oo30_r);
			} else {
				display_led(oo30_off);
			}


			if (!HVON_IN_RA4_GetValue()) {
				display_led(oo20_g);
			} else {
				display_led(oo20_off);
			}

			if (disp_tick) {
				ps_type_ptr = &ps_type[ps_type_index]; // set power supply scaling pointer
				vval = (double) ana[PS_V_ANA] * ps_type_ptr->v_scale;
				ival = (double) ana[PS_I_ANA] * ps_type_ptr->i_scale;
				printf(" PS TYPE %1u: PS Test %1u: DAC OUT %4.4umV B=%.2u, Supply ReadBack %4.4umV V=%+6.1fV %4.4umV I=%+3.1fmA \r\n",
					ps_type_index, mode, ana[channel_DAC1], (uint16_t) DAC1_GetOutput(), ana[PS_V_ANA], vval, ana[PS_I_ANA], ival);
				if (!(lcd_update++ & 0x03)) { // slow LCD update rate
					sprintf(buff1, "%4.4umV %4.4umV %4.4umV", ana[channel_DAC1], ana[PS_V_ANA], ana[PS_I_ANA]);
					eaDogM_WriteStringAtPos(0, 0, buff1);
					sprintf(buff1, "%4.4umV %4.4umV %4.4umV", ana[DAC_ANA], ana[PWM5_ANA], ana[PWM6_ANA]);
					eaDogM_WriteStringAtPos(1, 0, buff1);
					sprintf(buff1, "D%.2u, M%1u, P%1u", (uint16_t) DAC1_GetOutput(), mode, ps_type_index);
					eaDogM_WriteStringAtPos(2, 0, buff1);
					sprintf(buff1, "V=%+6.1fV I=%+3.1fmA", vval, ival);
					eaDogM_WriteStringAtPos(3, 0, buff1);
				}
				/*
				 * mode switch state machine
				 */
				switch (mode) {
				case roll_mode: // sawtooth voltage ramp
					if (dac_v > roll_max) {
						dac_v = 0;
					}
					DAC1_SetOutput(++dac_v);
					LED_MODE_SetHigh();
					HVON_OUT_RA5_SetLow();
					break;
				case static_mode: // 1000 vdc unloaded
					dac_v = static_ps;
					DAC1_SetOutput(dac_v);
					LED_MODE_SetHigh();
					HVON_OUT_RA5_SetLow();
					break;
				case off_mode: // voltage shutdown
				default:
					mode = off_mode;
					dac_v = 0;
					DAC1_SetOutput(dac_v);
					LED_MODE_SetLow();
					HVON_OUT_RA5_SetHigh();
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
						LED_DB_SetHigh();
					}
				} else {
					mode_sw = 0;
					LED_DB_SetLow();
				}
			}
		}
	}
}

/**
 End of File
 */