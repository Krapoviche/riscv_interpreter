#include "cpu.h"

void initialize_cpu(){
    riscvcpu.registers = malloc(sizeof(uint32_t) * 32);
    riscvcpu.sp = (uint32_t*)&riscvcpu.registers[2];
    *riscvcpu.sp = CODE_SEGMENT_ADDRESS;
    riscvcpu.clock.freq = CPU_CLOCK_FREQ;
}

void start_clock(){
    // Compute time needed to achieve freq
    struct timespec gap;

    // Fetch / Decode / Execute loop
    int cycle_success = 1;
    while(cycle_success){
        reset_gap(&gap);
        run_cycle_iteration(&gap);
        INTER_CYCLE_WAIT(&gap, &gap);
    }
}

void reset_gap(struct timespec* gap){
    int gap_ns = (NS_PER_SECOND / riscvcpu.clock.freq);
    gap->tv_sec = gap_ns / NS_PER_SECOND;
    gap->tv_nsec = (gap_ns % NS_PER_SECOND);
}

int run_cycle_iteration(struct timespec* gap){
    struct timespec fetch_decode_execute_start, fetch_decode_execute_end, time_spent;

    // Measure iteration duration
    clock_gettime(CLOCK_MONOTONIC, &fetch_decode_execute_start);
    int ret = instruction_cycle();
    clock_gettime(CLOCK_MONOTONIC, &fetch_decode_execute_end);

    // Subtract the iteration duration from the gap duration to maintain frequency
    time_spent = sub_timespec(&fetch_decode_execute_end, &fetch_decode_execute_start);
    *gap = sub_timespec(gap, &time_spent);

    return ret;
}

int instruction_cycle(){
    // Avoid executing the content of the data segment
    if(translate_address(*riscvcpu.sp) < mem.data_segment){
        int instruction = fetch(translate_address((*riscvcpu.sp)));
        DEBUG("EXECUTE 0x%x\n", instruction);
        // decode(instruction);
        // execute(instruction);
        (*riscvcpu.sp)++;

        return 1;
    }
    return 0;
}

int fetch(uint32_t* sp){
    return *sp;
}
