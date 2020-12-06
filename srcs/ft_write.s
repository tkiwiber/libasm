section .text
	global _ft_write

_ft_write:
	test	edi, edi	; check if fd < 0 (set SF)
	js		error		; jump to error exit

	test	esi, esi	; if ptr == NULL (set ZF)
	jz		error		; jump to error exit

	test	edx, edx	; if size < 0 (set SF)
	js		error		; error

	push	rdx			; store size in stack
	mov		rdx, 0		; size = 0

	mov     rax, 0x2000004	; write call
	syscall					; write (fd, buf, 0)
	pop		rdx				; get size from stack

	test	eax, eax		; if return != 0
	jne		error			; error

    mov     rax, 0x2000004	; write call
    syscall					; write (fd, buf, len)

	cmp		rax, 14			; if ret != 14
	jne		end				; end
	cmp		rdx, 14			; if len != 14
	jne		error			;
	ret

error:
	mov		rax, -1	; return = -1
	ret				;

end:
	ret