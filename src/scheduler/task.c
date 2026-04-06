#include "../../drivers/screen.h"
void task1() {
    print_string("\n[Task1 running]");
}

void task2() {
    print_string("\n[Task2 running]");
}

void run_tasks() {
    while (1) {
        task1();

        for (int i = 0; i < 10000000; i++);

        task2();

        for (int i = 0; i < 10000000; i++);
    }
}
