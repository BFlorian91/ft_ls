# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 16:42:03 by flbeaumo          #+#    #+#              #
#    Updated: 2019/02/01 21:01:17 by alcaroff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = $(addprefix $(SRCS_PATH)/, \
	   main.c parse_flags.c parse_files.c )

OBJ = $(SRCS:.c=.o)

SRCS_PATH = srcs

HEADER_PATH = includes

LIB_C_PATH = ./libft/

LIB_PRINT_PATH = ./ft_printf/

LIBFT = libft/libft.a 

PRINTF = ft_printf/libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

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
	@$(CC) $(SRCS) $(LIBFT) $(PRINTF) -o $@ $(CFLAGS) -I $(HEADER_PATH)
	@clear
	@echo "\033[2A $(GREEN) [ Compile status ]		 [OK] $(NC)"

%.o: %.c $(LIBFT) $(PRINTF)
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADER_PATH)
	@echo "\033[1A $(YELLOW)Compiling:$(LBLUE) $< \033[K 	$(GREEN) [OK] $(NC)"

$(LIBFT):
	@make -C ./libft/

$(PRINTF):
	@make -C ft_printf/

norm:
	norminette $(SRCS_PATH) $(HEADER_PATH) $(LIB_C_PATH) $(LIB_PRINT_PATH)

clean:
	@rm -rf $(OBJ)
	@make clean -C ./libft/
	@make clean -C ft_printf/
	@echo "$(RED) Remove Object:$(NC)			$(GREEN) [OK] $(NC)" $<

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./libft/ 
	@make fclean -C ./ft_printf/
	@echo "$(RED) Remove Binary:$(NC)			$(GREEN) [OK] $(NC)"

re: fclean all
