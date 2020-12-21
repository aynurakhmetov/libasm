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
	cmp rax, 0
	je return_
	mov al, byte[rdi + rax]
	sub rax, rdx
	cmp rax, 0
	jg retplus
	jl retminus
	ret

retplus:
	mov rax, 1
	ret

retminus:
	mov rax, -1
	ret

return_:
	mov al, byte[rdi + rax]
	sub rax, rdx
	ret
