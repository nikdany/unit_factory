# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/02 20:36:29 by mdanylch          #+#    #+#              #
#    Updated: 2019/08/10 15:40:47 by mdanylch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= wolf3d

SRC		= srcs/main.c \
		srcs/wolf_raycast.c srcs/wolf_validation.c srcs/wolf_event.c

OBJ		= $(SRC:.c=.o)
LIBFT	= includes/libft/
HDR		= includes/wolf3d.h
CC		= /usr/bin/gcc
CFLAGS	= -Wall -Wextra -Werror -g

CGFLAGS = -framework OpenGL -framework AppKit

SDL_INC	=	-I includes/frameworks/SDL2.framework/Header \
			-I includes/frameworks/SDL2_image.framework/Headers \

SDL_FLG	= -F includes/frameworks/
SDL_RUN	= -rpath frameworks -framework SDL2 -framework SDL2_image

DEL		= /bin/rm -f

all:	$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(SDL_FLG) $(SDL_RUN) $(SDL_INC) -o $(NAME) $(OBJ) -I $(HDR) -L $(LIBFT) -lft 
	@echo "Compilation complete"

map0:
	./wolf3d maps/map_0

map1:
	./wolf3d maps/map_1

%.o : %.c $(HDR) $(LIBFT)
	@$(CC) $(CFLAGS) $(SDL_FLG) $(SDL_INC) -o $@ -c $< -I .

clean:
	@make fclean -C $(LIBFT)
	@$(DEL) $(OBJ)
	@echo "Objects removed!"

fclean:		clean
	@make -C $(LIBFT) fclean
	@$(DEL) $(NAME)
	@echo "$(NAME) files removed!"


re:		fclean all

.PHONY:		re all clean fclean