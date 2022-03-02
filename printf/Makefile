# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlucio <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/01 20:23:16 by dlucio            #+#    #+#              #
#    Updated: 2020/08/01 20:23:18 by dlucio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC  = 	ft_printf.c \
ft_printf_dig_ch_str.c \
ft_printf_hex_up.c \
ft_printf_p_u_pr.c \
ft_printf_spec.c \
lib_funcs.c \
edit_print_all.c \
lib_2.c \
ft_convertion.c \

FLAGS = -Wall -Wextra -Werror

INCLUDE = ./ft_printf.h

OBJ = $(SRC:.c=.o)

all : $(NAME)
$(NAME) : $(OBJ) $(INCLUDE)
	@ar rc $(NAME) $(OBJ)

%.o : %.c
	gcc $(FLAGS) -c -o $@ $<

clean : 
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
