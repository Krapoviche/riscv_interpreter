#ifndef CPU_H_
#define CPU_H_

#include <stdint.h>
#include "clock.h"
#include "../memory/memory.h"
#include "../utils/utils.h"

typedef struct cpu
{
    uint32_t* registers;
    uint32_t* sp;
    cpu_clock clock;
} cpu;

cpu initialize_cpu(void);
void start_clock(memory mem, cpu riscvcpu);
int instruction_cycle(memory mem, cpu riscv_cpu);
int fetch(uint32_t* sp);

#endif
