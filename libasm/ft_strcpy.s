global _ft_strcpy

section .text

_ft_strcpy:
				mov		rax, 0
				mov		rcx, 0
loop:
				cmp		byte[rsi + rcx], 0
				jz		return
				mov		bl, byte[rsi + rcx]
				mov		byte[rdi + rcx], bl 

				
				
				inc		rcx
				jmp		loop
return:
				mov 	byte[rdi + rcx], 0
				mov		rax, rdi
				ret
