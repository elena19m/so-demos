section .rodata
	format db `%s %d\n\x0`
	string db `SO Rulz!!!\x0`

section .text

global main
extern printf

main:
	mov rdi, format
	mov rsi, string
	mov rdx, 42
	xor rax, rax
	call printf
	; printf(format, string, 42)

	mov rdi, 38
	mov rax, 60
	syscall
