;			ssize_t read(RDI = int fildes, RSI = void *buf, RDX = size_t nbyte);

global		_ft_read
extern		___error

section .text

_ft_read:
			mov		rax, 0x2000003			; write vector number
			syscall						; call system function write
			jc		.error					; syscall set CF = 1 if any errors occur and copy code number in RAX
			ret							; return number of written letters (RAX)
.error:
			push	rdx					; here we have error number at RAX. Store RDX to re-use it leter
			mov		rdx, rax				; save error code to rdx
			call	___error				; get pointer to ERRNO using C function
			mov		[rax], rdx				; write this error code at errno adress
			pop		rdx						; restore RDX before exit
			mov		rax, -1					; set returned value to -1
			ret