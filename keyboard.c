unsigned char inb(unsigned short port) {
    unsigned char result;
    asm volatile ("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

char keyboard_map[128] = {
    0,27,'1','2','3','4','5','6','7','8','9','0','-','=', '\b',
    '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n',
    0,'a','s','d','f','g','h','j','k','l',';','\'','`',
    0,'\\','z','x','c','v','b','n','m',',','.','/',
    0,'*',0,' '
};

char get_char() {
    unsigned char scancode;

    while (1) {
        scancode = inb(0x60);

        // ignore key release (>= 128)
        if (scancode < 128) {
            char c = keyboard_map[scancode];

            if (c != 0) {
                // wait until key is released
                while (inb(0x60) == scancode);
                return c;
            }
        }
    }
}
