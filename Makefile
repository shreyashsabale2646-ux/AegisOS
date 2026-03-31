AS = nasm
EMU = qemu-system-i386

TARGET = myos.bin

all: $(TARGET)

boot.bin: boot.s
	$(AS) -f bin boot.s -o boot.bin

$(TARGET): boot.bin
	cp boot.bin $(TARGET)

run: $(TARGET)
	$(EMU) -drive format=raw,file=$(TARGET)

clean:
	rm -f *.bin $(TARGET)
