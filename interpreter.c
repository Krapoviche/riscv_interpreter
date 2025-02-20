#include "interpreter.h"

int main(){
    FILE * code;
    printf("[DEBUG] Opening file\n");
    code = fopen("./code1.riscv", "r");
    printf("[DEBUG] Opened file\n");

    printf("[DEBUG] Initializing memory\n");
    memory central_memory = initialize_memory();
    printf("[DEBUG] Initialized memory\n");

    printf("[DEBUG] Loading code to memory\n");
    load_code_to_memory(central_memory, code);
    printf("[DEBUG] Loaded code to memory\n");
}
