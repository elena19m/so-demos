# Linux Kernel

```
$ ls -lh /boot/vmlinuz-$(uname -r)

$ file /boot/vmlinuz-$(uname -r)

$ /usr/src/linux-headers-$(uname -r)/scripts/extract-vmlinux /boot/vmlinuz-$(uname -r) > uncompressed

$ objdump -d -M intel uncompressed | less
```
