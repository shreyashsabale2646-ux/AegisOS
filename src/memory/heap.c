int heap_top = 0x10000;

void* kmalloc(int size) {
    int addr = heap_top;
    heap_top += size;
    return (void*)addr;
}
