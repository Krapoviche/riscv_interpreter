#include "interpreter.h"

int main(){
    FILE * code;
    DEBUG("Opening file\n");
    code = fopen("./code1.riscv", "r");
    DEBUG("Opened file\n");

    DEBUG("Initializing memory\n");
    initialize_memory();
    DEBUG("Initialized memory\n");

    DEBUG("Loading code to memory\n");
    load_code_to_memory(code);
    DEBUG("Loaded code to memory\n");

    DEBUG("Initializing CPU\n");
    initialize_cpu();
    DEBUG("Initialized CPU\n");

    start_clock();
}
