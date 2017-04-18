#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eozdek <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/26 20:29:17 by eozdek            #+#    #+#              #
#    Updated: 2016/02/26 20:29:38 by eozdek           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY : clean, fclean, re
.SUFFIXES :

NAME = libftprintf.a

PATH_LIBFT = libft/
ARCHIVE_LIBFT = libft.a
LIBFT = $(PATH_LIBFT)$(ARCHIVE_LIBFT)

SRC =	ft_wchar.c \
        flags.c \
        ft_binary.c \
        ft_precision.c \
        ft_convert.c \
        ft_hexa.c \
        ft_itoa_base.c \
        ft_mod.c \
        ft_number.c \
        ft_octal.c \
        ft_pointer.c \
        ft_octal.c \
        ft_hexa.c \
        ft_unsigned.c \
        ft_string.c \
        ft_putwst.c \
        ft_putstr_nb.c \
        ft_printf.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar r $(NAME) $(OBJ)
	ranlib $(NAME)

$(LIBFT) :
	make -C $(PATH_LIBFT)

%.o : %.c
	gcc -c $^ -Wall -Werror -Wextra -o $@ -I $(PATH_LIBFT)

clean :
	rm -f $(OBJ)
	make fclean -C $(PATH_LIBFT)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(PATH_LIBFT)

re : fclean all
