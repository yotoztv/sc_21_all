NAME = libasm.a
SRC = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_strdup.s ft_read.s
OBJ = $(SRC:.s=.o)

NA = nasm
NAFLAGS = -f macho64 -Werror

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $?
	ranlib $(NAME)

%.o: %.s
	$(NA) $(NAFLAGS) $< -o $@


clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
