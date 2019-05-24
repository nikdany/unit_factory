# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/01 03:03:51 by mdanylch          #+#    #+#              #
#    Updated: 2019/05/01 03:33:43 by mdanylch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Werror -Wextra

SRC     = src/fdf.c \
			src/render.c \
			src/ft_close.c

LIBFT   = inc/libft/
OBJ = $(SRC:.c=.o)
DEL = rm -f
HDR  = inc/fdf.h
FMLX    = -framework OpenGL -framework AppKit -lmlx
DEL      = /bin/rm -f

all: $(NAME)

$(NAME):    $(OBJ) $(LIBFT)
	@make -C $(LIBFT)	
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I $(HDR) -L $(LIBFT)  -lft $(FMLX)

%.o : %.c $(HDR) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ -c $< -I .

clean:
	@make fclean -C $(LIBFT)
	@$(DEL) $(OBJ)

fclean:     clean
	@make -C $(LIBFT) fclean
	@$(DEL) $(NAME)

re: fclean all

.PHONY:     re all clean fclean