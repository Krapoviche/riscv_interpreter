#include "memory.h"

memory initialize_memory(){
    memory mem;
    mem.base_addr = calloc(MEMORY_SIZE, sizeof(char));
    mem.code_segment = mem.base_addr + CODE_SEGMENT_ADDRESS;
    mem.data_segment= mem.base_addr + DATA_SEGMENT_ADDRESS;
    mem.last_address= mem.base_addr + LAST_ADDRESS;
    mem.size = MEMORY_SIZE;
    return mem;
}

void* translate_address(memory mem, void* address){
    return &mem.base_addr[(long)address];
}
