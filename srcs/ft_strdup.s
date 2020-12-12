;			char *ft_strdup(RDI = const char *s1);

global 		_ft_strdup
extern 		_malloc
extern 		_ft_strlen
extern		_ft_strcpy

section .text

_ft_strdup:
			push	rdi						; save *s1 at stack
			call	_ft_strlen				; RDI already contains *s1, as a result RAX = strlen(s1)
			inc		rax						; extra simbol for "\0"
			mov		rdi, rax				; sotre at RDI nbytes for new string
			call	_malloc					; allocate memory
			test	rax, rax				; if malloc return == NULL
			je		.error					; goto error
			mov		rdi, rax				; rax = allocated memory
			pop		rsi						; = *s1
			call	_ft_strcpy				; it will copy rsi to rdi and mov rdi to rax

.error:
			ret								; no error handle as malloc already sets ERRNO and other funcs are unprotected