section .rodata
	format db `%s %d\n\x0`
	string db "SO Rulz!!!", 0xa, 0
	len db 12

section .text

global main
extern printf

main:
	mov rdi, 1
	mov rsi, string
	movzx rdx, byte [len]
	mov rax,1 
	syscall
	
	mov rdi, 42
	mov rax, 60
	syscall
