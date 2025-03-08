#ifndef CPU_H_
#define CPU_H_

#include <stdint.h>
#include <time.h>

#include "clock.h"
#include "../memory/memory.h"
#include "../utils/utils.h"

typedef struct cpu
{
    uint32_t* registers;
    uint32_t* sp;
    cpu_clock clock;
} cpu;

void initialize_cpu(void);
void start_clock(void);
void reset_gap(struct timespec* gap);
int run_cycle_iteration(struct timespec* gap);
int instruction_cycle(void);
int fetch(uint32_t* sp);

cpu riscvcpu;

#endif
