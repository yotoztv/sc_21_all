# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlucio <dlucio@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/26 01:51:00 by dlucio            #+#    #+#              #
#    Updated: 2020/05/26 01:51:12 by dlucio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC  = 	ft_isprint.c \
   	ft_memset.c \
   	ft_strjoin.c \
   	ft_strtrim.c \
   	ft_bzero.c \
   	ft_itoa.c \
   	ft_putchar_fd.c \
   	ft_strlcat.c \
   	ft_substr.c \
   	ft_calloc.c \
   	ft_memccpy.c \
   	ft_putendl_fd.c \
   	ft_strlcpy.c \
   	ft_tolower.c \
   	ft_isalnum.c \
   	ft_memchr.c \
   	ft_putstr_fd.c \
   	ft_strmapi.c \
   	ft_toupper.c \
   	ft_isalpha.c \
   	ft_memcmp.c \
   	ft_split.c \
   	ft_strncmp.c \
   	ft_isascii.c \
   	ft_memcpy.c \
   	ft_strchr.c \
   	ft_strnstr.c \
   	ft_strlen.c \
   	ft_isdigit.c \
   	ft_memmove.c \
   	ft_strdup.c \
   	ft_strrchr.c \
   	ft_atoi.c \
   	ft_putnbr_fd.c \

FLAGS = -Wall -Wextra -Werror

INCLUDE = ./libft.h

OBJ = $(SRC:.c=.o)

all : $(NAME)
$(NAME) : $(OBJ) $(INCLUDE)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o : %.c
	gcc $(FLAGS) -c -o $@ $<

clean : 
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)
	@rm -rf libft.so

re: fclean all

so:
	gcc -c -fPIC ft_*.c
	gcc -shared -o libft.so ft_*.o

.PHONY: all clean fclean re
