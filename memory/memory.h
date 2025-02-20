#ifndef MEMORY_H_
#define MEMORY_H_

#include <stdlib.h>

#define MEMORY_SIZE 1024 // 1Ko memory
#define CODE_SEGMENT_ADDRESS 0x0 // Code starts at @0x0
#define DATA_SEGMENT_ADDRESS 0x100 // Data starts at @0x100 => 256 BYTES for code => 64 instructions max
#define LAST_ADDRESS 0x3FF

// ######################################
// # CODE SEGMENT - 0x0 -> 0xFF         #
// ######################################
// # DATA SEGMENT - 0x100 -> 0x3FF      #
// ######################################

typedef struct memory
{
    void* base_addr;
    void* code_segment;
    void* data_segment;
    void* last_address;
    int size;
} memory;


memory initialize_memory();
#endif
