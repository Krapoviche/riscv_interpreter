#ifndef MEMORY_H_
#define MEMORY_H_

#include <stdlib.h>

#define MEMORY_SIZE 1024 // 1Ko memory
#define CODE_SEGMENT_ADDRESS 0x0 // Code starts at @0x0

typedef struct memory
{
    void* base_addr;
    int size;
    int code_segment_address;
} memory;


memory initialize_memory();
#endif
