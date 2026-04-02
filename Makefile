AS = nasm
EMU = qemu-system-i386

TARGET = myos.bin

all: $(TARGET)

boot.bin: boot.s
	$(AS) -f bin boot.s -o boot.bin

kernel.bin: kernel.asm
	$(AS) -f bin kernel.asm -o kernel.bin

$(TARGET): boot.bin kernel.bin
	cat boot.bin kernel.bin > $(TARGET)

run: $(TARGET)
	$(EMU) -drive format=raw,file=$(TARGET)

clean:
	rm -f *.bin $(TARGET)
