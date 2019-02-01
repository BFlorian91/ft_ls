# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 16:42:03 by flbeaumo          #+#    #+#              #
#    Updated: 2019/01/18 18:45:42 by flbeaumo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c parsing.c check.c map.c func.c solving.c

OBJ = $(SRCS:.c=.o)

HEADER = fillit.h

LIBFT = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(SRCS) $(LIBFT) -o $@ $(CFLAGS)
	@echo "\\033[1;34m FILLIT\033[0m				\033[0;32m[SUCESS] \033[0m"

%.o: %.c $(LIBFT)
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADER)
	@echo "\033[0;33m Compiling:\033[0m			\033[0;32m [OK] \033[0m" $<

$(LIBFT):
	@make -C ./libft/
clean:
	@rm -rf $(OBJ)
	@make clean -C ./libft/
	@echo "\033[1;31m Remove Object:\033[0m			\033[0;32m [OK] \033[0m" $<

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./libft/
	@echo "\033[1;31m Remove Binary:\033[0m			\033[0;32m [OK] \033[0m"

re: fclean all
