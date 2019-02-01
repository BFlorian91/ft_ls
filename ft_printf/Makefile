# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 15:15:20 by alcaroff          #+#    #+#              #
#    Updated: 2019/02/01 20:52:27 by alcaroff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFT		=	libft/libft.a
FLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	includes
SRC			=	\
	ft_printf.c \
	lst_manager.c \
	parser.c \
	parse_str.c \
	check_exceptions.c \
	print_specifier.c \
	is.c \
	ft/pf_itoa_base.c \
	ft/pf_itoa_base_un.c \
	ft/pf_getwstr.c \
	ft/pf_atoi.c \
	ft/pf_bzero.c \
	ft/pf_isalpha.c \
	ft/pf_isdigit.c \
	ft/pf_strcmp.c \
	ft/pf_strcpy.c \
	ft/pf_strdup.c \
	ft/pf_strndup.c \
	ft/pf_strlen.c \
	ft/pf_strtolower.c \
	ft/pf_getchar.c \
	ft/pf_strisspace.c \
	ft/pf_putstr.c \
	ft/pf_putchar.c
OBJ			=	$(SRC:%.c=%.o)

NC = 	 \033[0m
RED =	 \033[0;31m
LRED = 	 \033[1;31m
LBLUE =  \033[1;34m
GREEN =  \033[0;32m
LGREEN = \033[1;32m
ORANGE = \033[0;33m
YELLOW = \033[1;33m

all: $(NAME)
	

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@gcc -c $< $(FLAGS) -o $@ -I $(INCLUDES)
	@echo "\033[1A $(YELLOW)Compiling:$(LBLUE) $< \033[K 	$(GREEN) [OK] $(NC)"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
