#ifndef CPU_H_
#define CPU_H_

#include "clock.h"
#include "../memory/memory.h"
#include "../utils/utils.h"

typedef struct cpu
{
    int* registers;
    void** sp;
    cpu_clock clock;
} cpu;

cpu initialize_cpu(void);
void start_clock(memory mem, cpu riscvcpu);
int instruction_cycle(memory mem, cpu riscv_cpu);
int fetch(int* sp);

#endif
