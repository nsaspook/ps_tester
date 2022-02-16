#ifndef TIMERS_H
#define TIMERS_H

#include <stdint.h>
#include <stdbool.h>

//Software timers - use these to refer to timers rather than
//integers.  Add more as needed.
//NOTE: 32767 ms max delay

enum APP_TIMERS {
	TMR_INTERNAL = 0, //Used in timers.c - do not remove or use elsewhere
	TMR_T1,
	TMR_T2,
	TMR_T3,
	TMR_T4,
	TMR_DISPLAY,
	//
	//(Add timers here as needed)
	//
	TMR_COUNT //number of timers - always keep at end of enum!
};

void StartTimer(uint8_t timer, uint16_t count);
bool TimerDone(uint8_t timer);
void WaitMs(uint16_t numMilliseconds);
void Timers_Isr(void);

#endif //TIMERS_H