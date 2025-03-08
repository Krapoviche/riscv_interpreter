#include "memory.h"

void initialize_memory(){
    mem.base_addr = calloc(MEMORY_SIZE, sizeof(char));
    mem.code_segment = mem.base_addr + CODE_SEGMENT_ADDRESS;
    mem.data_segment= mem.base_addr + DATA_SEGMENT_ADDRESS;
    mem.last_address= mem.base_addr + LAST_ADDRESS;
    mem.size = MEMORY_SIZE;
}

uint32_t* translate_address(uint32_t address){
    return &mem.base_addr[address];
}
