segment .text
global _ft_strlen

_ft_strlen:
	mov rax, -1

while:
	inc rax
	cmp qword[rdi + rax], 0
	jnz while
	ret
	