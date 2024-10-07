GCCFLAGS=-m32
NASMFLAGS=-f elf32

build: syscall_exit syscall_exit64 syscall_write64

syscall_exit: syscall_exit.o
	gcc $(GCCFLAGS) -o $@ $^

syscall_exit.o: syscall_exit.asm
	nasm $(NASMFLAGS) $^

syscall_exit64: syscall_exit64.o
	gcc -no-pie -o $@ $^

syscall_exit64.o: syscall_exit64.asm
	nasm -f elf64  $^

syscall_write64: syscall_write64.o
	gcc -no-pie -o $@ $^

syscall_write64.o: syscall_write64.asm
	nasm -f elf64  $^
clean:
	rm -f syscall_exit syscall_exit64 syscall_write64 syscall_exit.o syscall_exit64.o syscall_write64.o main main.o
