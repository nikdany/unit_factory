# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/02 20:36:29 by mdanylch          #+#    #+#              #
#    Updated: 2019/07/18 17:13:59 by mdanylch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fractol

SRC     = srcs/main.c \
			srcs/fractal_draw.c \
			srcs/fractal_formulas_1.c \
			srcs/fractal_formulas_2.c \
			srcs/fractol_controls.c

OBJ		= $(SRC:.c=.o)
LIBFT	= includes/libft/
HDR		= includes/fractol.h
CC		= /usr/bin/gcc
CFLAGS	= -Wall -Wextra -Werror
FMLX	= -framework OpenGL -framework AppKit -lmlx
DEL		= /bin/rm -f

all:	$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I $(HDR) -L $(LIBFT)  -lft $(FMLX)
	@echo "Compilation complete"

go:
	./fractol 1

me:
	./fractol 1 2 3 4 5 6 7 8

%.o : %.c $(HDR) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ -c $< -I .

clean:
	@make fclean -C $(LIBFT)
	@$(DEL) $(OBJ)
	@echo "Objects removed!"

fclean:     clean
	@make -C $(LIBFT) fclean
	@$(DEL) $(NAME)
	@echo "$(NAME) files removed!"


re:		fclean all

.PHONY:		re all clean fclean