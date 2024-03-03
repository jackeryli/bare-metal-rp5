TOOLCHAIN_PREFIX = aarch64-linux-gnu-
CC = $(TOOLCHAIN_PREFIX)gcc
LD = $(TOOLCHAIN_PREFIX)ld
OBJCPY = $(TOOLCHAIN_PREFIX)objcopy

CFLAGS = -Wall

# QEMUOPTS = -machine virt -cpu cortex-a76 -bios none m 128M -smp $(nproc) -nographic
# QEMUOPTS += -drive file=kernel8.img,if=none,format=raw,id=x0
# QEMUOPTS += -device virtio-blk-device,drive=x0,bus=virtio-mmio-bus.0

all: clean kernel8.img

entry.o: entry.S
	$(CC) $(CFLAGS) -c entry.S -o entry.o

kernel8.img: entry.o
	$(LD) -T kernel.ld -o kernel8.elf entry.o
	$(OBJCPY) -O binary kernel8.elf kernel8.img

clean:
	rm -f *.o kernel8.elf kernel8.img

check-asm:
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -display none -d in_asm

qemu:
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -display none -serial null -serial stdio