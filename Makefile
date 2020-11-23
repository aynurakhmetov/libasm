all:
	nasm -f macho64 ft_strlen.s
	nasm -f macho64 ft_strcpy.s
	nasm -f macho64 ft_strcmp.s
	nasm -f macho64 ft_strdup.s
	nasm -f macho64 ft_write.s
	nasm -f macho64 ft_read.s
	gcc -g -Wall -Wextra -Werror main.c ft_strlen.o ft_strcpy.o ft_strcmp.o ft_strdup.o ft_write.o ft_read.o
	./a.out

