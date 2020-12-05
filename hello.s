global	_main

section	.text
_main:
	mov		rax, 0x02000004
	mov		rdi, 1
	mov		rsi, message
	mov		rdx, 20
	syscall
	mov		rax, 0x02000001
	mov		rdi, 0
	syscall

section	.data
message:
	db	"Hello, world!", 65, 10

