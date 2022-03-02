global	_ft_read

extern	___error

section .text

_ft_read:
			mov		rax, 0x02000003 
			syscall
			jc		error
			ret

error:		
			mov		rdx, rax
			call	___error
			mov		[rax], rdx
			mov		rax, -1
			ret
