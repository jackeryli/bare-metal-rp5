set confirm off
set architecture aarch64
target remote 127.0.0.1:1234
symbol-file kernel.elf
set disassemble-next-line auto
