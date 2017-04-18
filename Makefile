# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eozdek <eozdek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:11:28 by eozdek            #+#    #+#              #
#    Updated: 2017/03/24 08:23:14 by eren_ozdek       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= computor
FILES	= get_next_line.c main.c parse_arg.c ft_list.c calc.c parse_term.c \
ft_error.c ft_double.c print_result.c delta.c square.c natural_parse.c
SRCS	= $(addprefix src/, $(FILES))
OBJS	= $(SRCS:src/%.c=.obj/%.o)
INC		= -I includes -I libft/includes -I ft_printf/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft
# PRINTF  = -L ft_printf -lftprintf
CC		= gcc

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[96m                  Makefile by e🏀 zdek\033[97m         "
	@echo "\033[91mCompiling 😇\033[97m"
		@make -C libft
		# @make -C ft_printf
		@$(CC) $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(PRINTF) $(LIB)
		@echo "\033[90mDone 😎\033[97m"
.obj/%.o: src/%.c
	mkdir -p .obj
	@$(CC) -c $< -o $@ $(FLAGS) $(INC)

clean:
	@echo "\033[92mDeleting 💀\033[97m"
	@rm -rf .obj
	@make clean -C libft
	#@make clean -C ft_printf
	@echo "\033[96mClean done 😡\033[97m"

fclean: clean
	@echo "\033[92mDeleting 💀\033[97m"
	@make fclean -C libft
	#@make fclean -C ft_printf
	@rm -f $(NAME)
	@echo "\033[96mFclean Done 👿\033[97m"

re: fclean all

.PHONY: all clean fclean re
