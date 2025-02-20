#include "memory.h"

memory initialize_memory(){
    memory mem;
    mem.base_addr = malloc(MEMORY_SIZE);
    mem.size = MEMORY_SIZE;
    mem.code_segment_address = CODE_SEGMENT_ADDRESS;
    return mem;
}
