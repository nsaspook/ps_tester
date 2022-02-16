#include "disp_led.h"

void display_led(DISPLAY_TYPES led)
{
	switch (led) {
	case oo00_off:
		IO_00_SetLow();
		IO_01_SetLow();
		break;
	case oo00_r:
		IO_00_SetLow();
		IO_01_SetHigh();
		break;
	case oo00_g:
		IO_00_SetHigh();
		IO_01_SetLow();
		break;
	case oo10_off:
		IO_10_SetLow();
		IO_11_SetLow();
		break;
	case oo10_r:
		IO_10_SetLow();
		IO_11_SetHigh();
		break;
	case oo10_g:
		IO_10_SetHigh();
		IO_11_SetLow();
		break;
	case oo20_off:
		IO_20_SetLow();
		IO_21_SetLow();
		break;
	case oo20_r:
		IO_20_SetLow();
		IO_21_SetHigh();
		break;
	case oo20_g:
		IO_20_SetHigh();
		IO_21_SetLow();
		break;
	case oo30_off:
		IO_30_SetLow();
		IO_31_SetLow();
		break;
	case oo30_r:
		IO_30_SetLow();
		IO_31_SetHigh();
		break;
	case oo30_g:
		IO_30_SetHigh();
		IO_31_SetLow();
		break;
	default:
		IO_00_SetLow();
		IO_01_SetLow();
		IO_10_SetLow();
		IO_11_SetLow();
		IO_20_SetLow();
		IO_21_SetLow();
		IO_30_SetLow();
		IO_31_SetLow();
		break;
	}

}
