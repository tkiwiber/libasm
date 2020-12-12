;			ft_write (RDI = *str)

global		_ft_strlen

section		.text

_ft_strlen:
			cld					; DF = 0, from left to right
			mov		rsi, rdi	; save start index at RSI
			xor		ecx, ecx	; RCX = 0
			dec		rcx			; RCX = -1 or 0ffffffffffffffffh
			xor		eax, eax	; RAX = 0 for what to be found (AL)
find:
			repne 	scasb		; scan the memory to find AL
			sub		rdi, rsi	; count diff between start/end index's
			dec		rdi			; remove /0 simbol
exit:
			mov		rax, rdi	; result
			ret