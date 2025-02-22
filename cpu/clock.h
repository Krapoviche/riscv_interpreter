#ifndef CLOCK_H_
#define CLOCK_H_

#include <time.h>
#include "../memory/memory.h"

#define CPU_CLOCK_FREQ 2 // Hz

#if defined(STEP_BY_STEP)
    #define INTER_CYCLE_WAIT(a, b) getchar()
#else
    #define INTER_CYCLE_WAIT(a, b) nanosleep(a, b);
#endif

typedef struct cpu_clock
{
    int freq; // In Hz
} cpu_clock;

#endif
