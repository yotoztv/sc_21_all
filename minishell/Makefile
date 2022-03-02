NAME = minishell

SRC  = \
./src/start.c \
./src/parcer.c \
./src/parcer_2.c \
./src/parcer_3.c \
./src/parcer_4.c \
./src/parcer_5.c \
./src/echo.c \
./src/echo_2.c \
./src/echo_3.c \
./src/export.c \
./src/export_best.c \
./src/export_best_2.c \
./src/export_best_3.c \
./src/export_3.c \
./src/export_4.c \
./src/export_5.c \
./src/export_6.c \
./src/unset.c \
./src/unset_2.c \
./src/cpy_mtrx.c \
./src/init_start.c \
./src/my_exec.c \
./src/my_exits.c \
./src/my_is_it.c \
./src/next_point_x.c \
./src/parse_simp_org.c \
./src/parse_simple.c \
./src/redirect.c \
./src/signals.c \
./src/unitls_34.c \
./src/cd.c \
./src/cd_2.c \
./src/env.c \

OBJ = $(SRC:.c=.o)

HEADER = minishell.h

FLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJ) libft.a
	@gcc $(FLAGS) libft.a $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

libft.a:
	@make -C libft
	@cp libft/libft.a ./

clean:
	@make -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f libft.a
	@rm -f $(NAME)

re: fclean all

run:
	./$(NAME)

.PHONY: all bonus clean fclean re run
