section .rodata
	format db `%s %d\n\x0`
	string db `SO Rulz!!!\x0`

section .text

global main
extern printf

main:
	mov eax, 42
	push eax
	push string
	push format
	call printf
	add esp, 12
	; printf(format, string, 42)

	mov ebx, 42
	mov eax, 1
	int 0x80
