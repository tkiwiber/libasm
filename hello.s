global	_hello

section	.text
_hello:
	mov		rax, 0x02000004
	mov		rdi, 1
	mov		rsi, message
	mov		rdx, 14
	syscall
	;mov		rax, 0x02000001
	;mov		rdi, 0
	;syscall

section	.data
message:
	db	"Hello, world!", 10
