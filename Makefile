CC = i686-elf-gcc
AS = nasm
EMU = qemu-system-i386

CFLAGS = -ffreestanding -O2 -Wall -Wextra
LDFLAGS = -T linker.ld -ffreestanding -O2 -nostdlib

OBJS = boot.o kernel.o

all: myos.bin

boot.o: boot.s
	$(AS) -f elf32 boot.s -o boot.o

kernel.o: kernel.c
	$(CC) -c kernel.c -o kernel.o $(CFLAGS)

myos.bin: $(OBJS)
	$(CC) $(LDFLAGS) -o myos.bin $(OBJS)

run: myos.bin
	$(EMU) -kernel $(TARGET)

clean:
	rm -f *.o myos.bin
