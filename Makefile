TOOLCHAIN_PREFIX = aarch64-linux-gnu-
CC = $(TOOLCHAIN_PREFIX)gcc
LD = $(TOOLCHAIN_PREFIX)ld
OBJCPY = $(TOOLCHAIN_PREFIX)objcopy

CFLAGS = -Wall -nostdlib -ggdb

SRCS = start.c uart.c printk.c string.c sh.c
OBJS = $(SRCS:.c=.o)

all: clean kernel.img

entry.o: entry.S
	$(CC) $(CFLAGS) -c entry.S -o entry.o

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Linking the object files to create kernel.elf
kernel.elf: entry.o $(OBJS)
	$(LD) -T kernel.ld -o kernel.elf entry.o $(OBJS)

# Convert kernel.elf to kernel.img
kernel.img: kernel.elf
	$(OBJCPY) -O binary kernel.elf kernel.img

clean:
	rm -f *.o kernel.elf kernel.img

check-asm:
	qemu-system-aarch64 -M raspi3b -kernel kernel.img -display none -d in_asm

qemu: kernel.img
	qemu-system-aarch64 -M raspi3b -kernel kernel.img -display none -serial null -serial stdio

qemu-gdb: kernel.img
	qemu-system-aarch64 -M raspi3b -s -S -kernel kernel.img -display none -serial null -serial stdio

