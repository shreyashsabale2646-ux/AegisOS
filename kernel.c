#include "src/fs/fs.h"
#include "src/memory/paging.h"
#include "src/scheduler/task.h"
#include "src/cpu/timer.h"
#include "src/memory/heap.h"
#include "src/cpu/gdt.h"
#include "src/cpu/idt.h"
#include "drivers/screen.h"
#include "keyboard.h"

// ================== STRING COMPARE ==================
int strcmp(char *a, char *b) {
    while (*a && (*a == *b)) {
        a++;
        b++;
    }
    return *a - *b;
}

// ================== SHELL ==================
void shell() {
    print_string("\n[AegisOS] > ");

    char cmd[20];
    int i = 0;

    while (1) {
        char c = get_char();

        if (c == '\n') {
            cmd[i] = 0;

            if (strcmp(cmd, "help") == 0) {
                print_string("\nCommands: help clear mem task ls about version");
            }
            else if (strcmp(cmd, "clear") == 0) {
                clear_screen();
            }
            else if (strcmp(cmd, "mem") == 0) {
                print_string("\nMemory OK");
            }
            else if (strcmp(cmd, "task") == 0) {
                run_tasks();
            }
            else if (strcmp(cmd, "ls") == 0) {
                list_files();
            }
	    else if (strcmp(cmd, "about")) {
    print_string("\nAegisOS by tean Aegis");
}
else if (strcmp(cmd, "version")) {
    print_string("\nAegisOS v1.0");
}
            else {
                print_string("\nUnknown command");
            }

            i = 0;
            print_string("\n[AegisOS]> ");
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
    init_paging();
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
