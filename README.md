# Bare Metal rpi3b

## How to use

```sh
make qemu
```

With gdb support:

```sh
make qemu-gdb
# Run on another terminal
gdb-multiarch -x .gdbinit
```

## Index

- bootloader: boot from kernel.ld and entry.S
- miniuart: display character on the qemu
- printk: formating print function
- shell: simple shell

## Reference

- https://github.com/rlepigre/bare-metal-aarch64/tree/master
- https://grasslab.github.io/osdi/en/index.html
- https://pdos.csail.mit.edu/6.828/2023/xv6.html