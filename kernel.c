#include "src/memory/heap.h"
#include "src/cpu/gdt.h"
#include "src/cpu/idt.h"
#include "drivers/screen.h"

void kernel_main() {
    init_gdt();
    init_idt();
    clear_screen();

    print_string("AegisOS v1.0\n");
    print_string("Boot Successful\n\n");

    print_string("Welcome to AegisOS  Kernel");

    int* x = (int*) kmalloc(4);
    *x = 123;
}
