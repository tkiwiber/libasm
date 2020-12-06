global _ft_strcpy

section .text

_ft_strcpy:
	push	rdi				; push pointer for later
	xor		rcx, rcx		; clear rcx 

copy:
	mov cl, byte [rsi]		; moving byte to rcx (cl)
	mov byte [rdi], cl
	cmp cl, 0
	je exitstrcpy
	add rsi, 1
	add rdi, 1
	jmp copy

exitstrcpy:
	pop rax					; pop pointer into rax for return
	ret