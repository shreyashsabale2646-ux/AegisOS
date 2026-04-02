void kernel_main();

void _start() {
    kernel_main();
}

void kernel_main() {
    char *video = (char*) 0xb8000;

<<<<<<< HEAD
    video[0] = 'K';
    video[1] = 0x07;

    video[2] = 'R';
    video[3] = 0x07;
=======
    char msg[] = "KERNEL";

    for (int i = 0; msg[i] != 0; i++) {
        video[i*2] = msg[i];
        video[i*2 + 1] = 0x07;
    }

    while(1);
>>>>>>> 8fb140c (day2: improved kernel string output)
}
