#include "types.h"
#include "io.h"
#include "debug.h"

void benchmark_start(void) {
    // reset counters
    IO_TM2CNT_L = 0;
    IO_TM3CNT_L = 0;

    // make sure timer 2 is disabled
    IO_TM2CNT_H = 0;
    IO_TM3CNT_H = 0;
    
    // init timers (tim3 count up mode, tim2 every clock cycle)
    IO_TM3CNT_H = TIMER_ENABLE | 0x4;
    IO_TM2CNT_H = TIMER_1CLK | TIMER_ENABLE;
}

u32 benchmark_end(void) {
    // stop timers
    IO_TM2CNT_H = 0;
    IO_TM3CNT_H = 0;

    // return result
    return (u32)(IO_TM2CNT_L | (IO_TM3CNT_L << 16u));
}