#ifndef CLOCK_H_
#define CLOCK_H_

#include <time.h>
#include "../memory/memory.h"

#define CPU_CLOCK_FREQ 2 // Hz

typedef struct cpu_clock
{
    float freq; // In Hz
} cpu_clock;

#endif
