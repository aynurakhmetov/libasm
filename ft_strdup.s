segment .text
global _ft_strdup
extern _malloc
extern ___error
extern _ft_strlen
extern _ft_strcpy

_ft_strdup:
	call _ft_strlen
	push rdi
	mov rdi, rax
	inc rdi
	call _malloc
	cmp rax, 0
	je _error
	mov rdi, rax
	pop rsi
	call _ft_strcpy
	ret

_error:
	call ___error
	ret
	