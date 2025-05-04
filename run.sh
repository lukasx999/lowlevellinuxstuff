#!/usr/bin/env bash
set -euxo pipefail

cc init.c -o init -static
echo -e "init busybox" | tr ' ' '\n' | cpio -ov --format=newc > initramfs.cpio

qemu-system-x86_64 \
    -kernel linux/arch/x86_64/boot/bzImage \
    -initrd initramfs.cpio \
    -nographic \
    -append "console=ttyS0" \
