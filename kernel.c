#include "src/cpu/timer.h"
#include "src/memory/heap.h"
#include "src/cpu/gdt.h"
#include "src/cpu/idt.h"
#include "drivers/screen.h"
#include "keyboard.h"

// ================== STRING COMPARE ==================
int strcmp(char *a, char *b) {
    int i = 0;
    while (a[i] && b[i]) {
        if (a[i] != b[i]) return 0;
        i++;
    }
    return a[i] == b[i];
}

// ================== SHELL ==================
void shell() {
    print_string("\n> ");

    char cmd[20];
    int i = 0;

    while (1) {
        char c = get_char();

        if (c == '\n') {
            cmd[i] = 0;

            if (strcmp(cmd, "help")) {
                print_string("\nCommands: help clear mem task");
            }
            else if (strcmp(cmd, "clear")) {
                clear_screen();
            }
            else if (strcmp(cmd, "mem")) {
                print_string("\nMemory OK");
            }
            else if (strcmp(cmd, "task")) {
                print_string("\nTask running");
            }
            else {
                print_string("\nUnknown command");
            }

            i = 0;
            print_string("\n> ");
        } 
        else {
            if (c != 0 && i < 19) {   // prevent overflow + ignore invalid
                cmd[i++] = c;
                print_char(c);
            }
        }
    }
}

// ================== KERNEL ENTRY ==================

void kernel_main() {
    init_gdt();
    init_idt();
    init_timer();
    clear_screen();

    print_string("AegisOS v1.0\n");
    print_string("Boot Successful\n\n");

    print_string("Welcome to AegisOS  Kernel");

    int* x = (int*) kmalloc(4);
    *x = 123;

    shell();
}
