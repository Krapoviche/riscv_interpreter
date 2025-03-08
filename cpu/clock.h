#ifndef CLOCK_H_
#define CLOCK_H_

#include <time.h>
#include "../memory/memory.h"

#ifndef CPU_CLOCK_FREQ
#define CPU_CLOCK_FREQ 1 // Hz
#endif

#define NS_PER_SECOND 1000000000

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
