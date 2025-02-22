#include "cpu.h"

cpu initialize_cpu(){
    cpu riscv_cpu;
    riscv_cpu.registers = malloc(sizeof(int) * 32);
    riscv_cpu.sp = (void**)&riscv_cpu.registers[2];
    *riscv_cpu.sp = CODE_SEGMENT_ADDRESS;
    riscv_cpu.clock.freq = CPU_CLOCK_FREQ;
    return riscv_cpu;
}

void start_clock(memory mem, cpu riscvcpu){
    // Compute time needed to achieve freq
    struct timespec ts;
    int gap_ns = (1e9 / riscvcpu.clock.freq);
    ts.tv_sec = gap_ns / 1e9;
    ts.tv_nsec = (gap_ns % 1000000000);

    // Fetch / Decode / Execute loop
    while(instruction_cycle(mem, riscvcpu)){
        nanosleep(&ts, &ts);
    }
}

int instruction_cycle(memory mem, cpu riscv_cpu){
    // Avoid executing the content of the data segment
    if(translate_address(mem, *riscv_cpu.sp) < mem.data_segment){
        int instruction = fetch(translate_address(mem, (*riscv_cpu.sp)));
        DEBUG("EXECUTE 0x%x\n", instruction);
        // decode(instruction);
        // execute(instruction);
        (*riscv_cpu.sp) += 4;

        return 1;
    }
    return 0;
}

int fetch(int* sp){
    return *sp;
}
