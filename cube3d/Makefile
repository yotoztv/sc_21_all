# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlucio <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/27 09:39:39 by dlucio            #+#    #+#              #
#    Updated: 2020/10/27 09:39:41 by dlucio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC  = \
./src/check_map.c \
./src/check_map_2.c \
./src/check_map_3.c \
./src/check_map_4.c \
./src/check_map_4_1.c \
./src/check_map_5.c \
./src/cube3d.c \
./src/cube3d_2.c \
./src/cube3d_3.c \
./src/cube3d_4.c \
./src/get_next_line.c \
./src/get_next_line_utils.c \
./src/koko.c \
./src/qt_mlx.c \
./src/qt_mlx_2.c \
./src/save_file.c \
./src/sprite_all.c \
./src/sprite_all_2.c \
./src/sprite_turn.c \
./src/u_1.c \

OBJ = $(patsubst %.c,%.o,$(SRC))

HEADER = cube3d.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -C mlx_dylib
	@cp libft/libft.a ./
	@cp mlx_dylib/libmlx.dylib ./
	@gcc $(FLAGS) libft.a libmlx.dylib -framework OpenGl -framework AppKit $(SRC) -o $(NAME)

bonus: all

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

clean:
	@make -C libft clean
	@make -C mlx_dylib clean
	@rm -f $(OBJ)
	@rm -f preview.bmp

fclean: clean
	@make -C libft fclean
	@make -C mlx_dylib clean
	@rm -f libft.a
	@rm -f libmlx.dylib
	@rm -f $(NAME)
	@rm -f preview.bmp

re: fclean all

run:
	./$(NAME) map1.cub

.PHONY: all bonus clean fclean re run
