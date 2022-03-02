global	_ft_strdup
extern	_malloc
extern	_ft_strlen
extern	_ft_strcpy

section .text
_ft_strdup:
			call		_ft_strlen
			inc			rax
			push		rdi
			mov			rdi, rax
			call		_malloc
			pop			rdi
			cmp			rax, 0
			jz			error
			mov			rsi, rdi
			mov			rdi, rax
			call		_ft_strcpy
			ret
error:
			ret
