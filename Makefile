TOOLCHAIN_PREFIX = aarch64-linux-gnu-
CC = $(TOOLCHAIN_PREFIX)gcc
LD = $(TOOLCHAIN_PREFIX)ld
OBJCPY = $(TOOLCHAIN_PREFIX)objcopy

CFLAGS = -Wall

SRCS = start.c uart.c printk.c string.c sh.c
OBJS = $(SRCS:.c=.o)

all: clean kernel8.img

entry.o: entry.S
	$(CC) $(CFLAGS) -c entry.S -o entry.o

# Rule to compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Linking the object files to create kernel8.elf
kernel8.elf: entry.o $(OBJS)
	$(LD) -T kernel.ld -o kernel8.elf entry.o $(OBJS)

# Convert kernel8.elf to kernel8.img
kernel8.img: kernel8.elf
	$(OBJCPY) -O binary kernel8.elf kernel8.img

clean:
	rm -f *.o kernel8.elf kernel8.img

check-asm:
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -display none -d in_asm

qemu: kernel8.img
	qemu-system-aarch64 -M raspi3b -kernel kernel8.img -display none -serial null -serial stdio
