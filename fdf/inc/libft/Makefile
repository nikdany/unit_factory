NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = *.c

OBJ = $(SRC:.c=.o)
DEL = rm -f

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c -I . $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@$(DEL) $(OBJ)

fclean: clean
	@$(DEL) $(NAME)

re: fclean all