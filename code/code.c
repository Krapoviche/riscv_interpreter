#include "code.h"

void load_code_to_memory(memory mem, FILE* code_file){
    int* instruction_pointer = mem.base_addr + mem.code_segment_address;

    // Read instructions
    DEBUG("Start reading instructions :\n");
    while(fscanf(code_file, "%x", instruction_pointer) != -1){

        DEBUG("\t%x\n", *instruction_pointer);
        instruction_pointer++;


        // Go to next line
        fscanf(code_file, "%*[^\n]%*c");
    }
    DEBUG("End reading instructions.\n");

}
