segment .text
global _ft_strcmp

_ft_strcmp:
	mov rax, -1
	mov rdx, 0
while:
	inc rax
	mov dl, byte[rsi + rax]
	cmp byte[rdi + rax], dl 
	jne return
	cmp rdx, 0
	je return
	jmp while

return:
	mov al, byte[rdi + rax]
	sub rax, rdx
	ret