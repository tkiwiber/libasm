global		_ft_strlen

section		.text

_ft_strlen:
			cld					; DF = 0, from left to right
			mov		rsi, rdi	; save start index at RSI
			xor		ecx, ecx	; RCX = 0
			dec		rcx			; RCX = -1 or 0ffffffffffffffffh
			xor		eax, eax	; RAX = 0 or what to be found
			repne scasb			; scan the memory to find AL

			sub		rdi, rsi	; count diff between start/end index's
			dec		rdi			; remove /0 simbol
			mov		rax, rdi

			ret