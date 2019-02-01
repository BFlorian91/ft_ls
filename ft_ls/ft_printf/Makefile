# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 15:15:20 by alcaroff          #+#    #+#              #
#    Updated: 2019/02/01 10:40:04 by flbeaumo         ###   ########.fr        #
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
	ft/ft_itoa_base.c \
	ft/ft_itoa_base_un.c \
	ft/ft_getwstr.c \
	ft/ft_atoi.c \
	ft/ft_bzero.c \
	ft/ft_isalpha.c \
	ft/ft_isdigit.c \
	ft/ft_strcmp.c \
	ft/ft_strcpy.c \
	ft/ft_strdup.c \
	ft/ft_strndup.c \
	ft/ft_strlen.c \
	ft/ft_strtolower.c \
	ft/ft_getchar.c \
	ft/ft_strisspace.c \
	ft/ft_putstr.c \
	ft/ft_putchar.c
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
