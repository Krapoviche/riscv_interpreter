#ifndef MEMORY_H_
#define MEMORY_H_

#include <stdlib.h>
#include <stdint.h>

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
    uint32_t* base_addr;
    uint32_t* code_segment;
    uint32_t* data_segment;
    uint32_t* last_address;
    int size;
} memory;

void initialize_memory(void);
uint32_t* translate_address(uint32_t address);

memory mem;

#endif
