segment .text
global _ft_strcpy

_ft_strcpy:
	mov rax, 0
	push rdi

while:
	cmp byte[rsi + rax], 0
	je return
	mov dl, byte[rsi + rax]
	mov byte[rdi + rax], dl
	inc rax
	jmp while

return:
	mov byte[rdi + rax], 0
	pop rax
	ret
	