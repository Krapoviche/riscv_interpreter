#include "utils.h"

void memory_dump(memory mem){
    int offset = 0;
    uint32_t* memory_read = mem.base_addr;
    printf("#############################\n");

    while(&(memory_read[offset]) <= mem.last_address){
        if((void*)&(memory_read[offset]) == mem.code_segment){
            printf("#############################\n");
            printf("# Code Segment              #\n");
            printf("#############################\n");
        } else if((void*)&(memory_read[offset]) == mem.data_segment){
            printf("#############################\n");
            printf("# Data Segment              #\n");
            printf("#############################\n");
        }

        if(memory_read[offset] != 0){
            printf("# @0x%x # 0x%x\n", offset * 4, memory_read[offset]);
        }
        offset+=1;
    }
    printf("#############################\n");
}
