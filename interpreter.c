#include "interpreter.h"

int main(){
    FILE * code;
    DEBUG("Opening file\n");
    code = fopen("./code1.riscv", "r");
    DEBUG("Opened file\n");

    DEBUG("Initializing memory\n");
    memory central_memory = initialize_memory();
    DEBUG("Initialized memory\n");

    DEBUG("Loading code to memory\n");
    load_code_to_memory(central_memory, code);
    DEBUG("Loaded code to memory\n");
}
