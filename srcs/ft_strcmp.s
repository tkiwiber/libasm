;			int ft_strcmp(RDI = const char *s1, RSI = const char *s2);

global 		_ft_strcmp

section .text

_ft_strcmp:
			push	rdx					; store RDX at stack
			xor		rdx, rdx			; RDX = 0
			xor		rcx, rcx			; RCX = 0

start:
			mov		dl, byte [rdi]		; move byte into RDX (small byte DL)
			mov		cl, byte [rsi]		; move byte into RCX (small byte CL)

checknull:
			cmp		dl, 0				; check if null
			je		exit                 ; jump to exit if ZF=0

checkchar:
			cmp		dl, cl				; check to see if equal
			jne		exit		    	; exit if not same (ZF=1)

iteratenext:
			inc		rdi			    	; *s1++
			inc		rsi 				; *s2++
			jmp		start		    	; next iteration

exit:
			xor		rax, rax			; RAX = 0
			mov		al, dl              ; put result into RAX
			sub		eax, ecx			; calculate diff for return
			pop		rdx
			ret