void kernel_main() {
    char *video = (char*) 0xb8000;

    video[0] = 'K';
    video[1] = 0x07;

    video[2] = 'R';
    video[3] = 0x07;
}
