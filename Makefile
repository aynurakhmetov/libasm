# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarva <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/29 22:45:00 by gmarva            #+#    #+#              #
#    Updated: 2020/11/29 22:45:02 by gmarva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

FILES_S = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_strdup.s ft_write.s ft_read.s
MAIN = main.c
GCC_COMPIL = gcc -Wall -Werror -Wextra
NASM_COMPIL = nasm -f macho64

FILES_O= $(FILES_S:.s=.o)
MAIN_O = $(MAIN:.c=.o)

all: $(NAME)

%.o: %.s
	@$(NASM_COMPIL) $< -o $@
	@echo "$@ ready"

%.o: %.c
	@$(GCC_COMPIL) -c $(MAIN)

$(NAME): $(FILES_O)
	@ar rcs $(NAME) $?
	@ranlib $(NAME)
	@echo "library .a ready"

test: $(MAIN_O) $(NAME)
	@$(GCC_COMPIL)  $^ -I ./libasm.h -o test
	@./test

clean:
	@rm -f $(FILES_O) $(MAIN_O)
	@echo "O-files deleted"

fclean: clean
	@rm -f $(NAME)
	@rm -r test
	@echo "All files deleted"

re: fclean all

.PHONY: clean fclean all re
