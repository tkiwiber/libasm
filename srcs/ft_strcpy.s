global 			_ft_strcpy

section 		.text

_ft_strcpy:
			push	rdi				; push pointer for later
			xor		rcx, rcx		; clear RCX 

copy:
			mov cl, byte [rsi]		; moving byte to RCX (CL)
			mov byte [rdi], cl		; copy byte to *dest
			cmp cl, 0				; check if end of string
			je exit					; jump to exit if ZF=0
			inc rsi					; *src++
			inc rdi					; *dest++
			jmp copy				; next iteration

exit:
			pop rax					; pop pointer into rax for return
			ret