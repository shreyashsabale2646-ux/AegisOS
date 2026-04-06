CC = gcc
LD = ld

CFLAGS = -m32 -ffreestanding -fno-pie -fno-pic -c
LDFLAGS = -m elf_i386 -T linker.ld --oformat binary -nostdlib

all:
	nasm -f bin boot.asm -o boot.bin
	nasm -f elf32 kernel_entry.asm -o kernel_entry.o
	$(CC) $(CFLAGS) kernel.c -o kernel.o
	$(CC) $(CFLAGS) drivers/screen.c -o screen.o
	$(CC) $(CFLAGS) src/cpu/idt.c -o idt.o
	$(CC) $(CFLAGS) src/cpu/gdt.c -o gdt.o
	$(CC) $(CFLAGS) src/memory/heap.c -o heap.o
	$(CC) $(CFLAGS) keyboard.c -o keyboard.o
	$(CC) $(CFLAGS) src/cpu/timer.c -o timer.o
	$(LD) $(LDFLAGS) kernel_entry.o kernel.o screen.o idt.o gdt.o heap.o keyboard.o timer.o -o kernel.bin
	cat boot.bin kernel.bin > os.bin

run: all
	qemu-system-i386 -drive format=raw,file=os.bin

clean:
	rm -f *.o *.bin os.bin
