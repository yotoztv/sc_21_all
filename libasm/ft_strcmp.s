global _ft_strcmp

section .text

_ft_strcmp:
				mov			rcx, 0
				mov			rdx, 0
				mov			rax, 0
				push		rbx
loop:
				cmp			byte[rdi + rcx], 0
				jz			return
				cmp			byte[rsi + rcx], 0
				jz			return
				mov			dl, byte[rsi + rcx]
				cmp			byte[rdi + rcx], dl
				jnz			return
				inc			rcx
				jmp			loop
return:
				mov			al, byte[rdi + rcx]
				mov			bl, byte[rsi + rcx]
				sub			rax, rbx
				pop			rbx
				ret
