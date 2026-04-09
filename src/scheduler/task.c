#include "drivers/screen.h"

void task1() {
    print_string("\n[Task1 executing]");
}

void task2() {
    print_string("\n[Task2 executing]");
}

void run_tasks() {

    print_string("\nStarting task execution...\n");

    for (int k = 0; k < 5; k++) {   // ONLY 5 TIMES (IMPORTANT)

        task1();

        for (int i = 0; i < 5000000; i++);   // delay

        task2();

        for (int i = 0; i < 5000000; i++);   // delay
    }

    print_string("\nTasks completed\n");
}
