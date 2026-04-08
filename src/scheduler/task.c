#include "../../drivers/screen.h"
void task1() {
    print_string("\n[Task1 running]");
}

void task2() {
    print_string("\n[Task2 running]");
}

void run_tasks() {
    for (int k=0 ;k<5;k++) {
        task1();

        for (int i = 0; i < 10000000; i++);

        task2();

        for (int i = 0; i < 10000000; i++);
    }
print_string("\nTasks completed\n");
}
