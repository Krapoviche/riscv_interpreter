#include "code.h"

void load_code_to_memory(FILE* code_file){
    uint32_t* instruction_pointer = mem.code_segment;

    // Read instructions
    DEBUG("Start reading instructions :\n");
    while(fscanf(code_file, "%x", instruction_pointer) != -1){

        DEBUG("\t0x%x\n", *instruction_pointer);
        instruction_pointer++;


        // Go to next line
        fscanf(code_file, "%*[^\n]%*c");
    }


    // Load 0 in 0, 1 in 1, branch if 0 and 1 != to the start address
    *instruction_pointer = 0x2b7;
    *(instruction_pointer + 1) = 0x1337;
    *(instruction_pointer + 2) = 0x629063;

    DEBUG("End reading instructions.\n");
}
