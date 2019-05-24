# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 14:26:23 by sshevchu          #+#    #+#              #
#    Updated: 2019/04/29 14:26:27 by sshevchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fillit 

SRC_DIR	:= ./src
INC_DIR	:= ./inc

SRC		:= fillit.c \
		   fillit_read_n_validate.c \
		   fillit_resolve.c \
		   ft_bzero.c \
		   ft_putendl.c \
		   ft_putstr.c \
		   ft_strdel.c \
		   ft_strnew.c \
		   set_template_bt.c \
		   check_figure_ch.c \
		   check_figure_bt.c \
		   gen_tetrominoe_template_bt.c \
		   lsb_l.c

SRC		:= $(addprefix $(SRC_DIR)/,$(SRC))
OBJ		:= $(SRC:.c=.o)

CFLAGS	+= -I$(INC_DIR) -std=c99 -Wall -Wextra -Werror -Weverything

FLAG	?=

ifeq ($(FLAG),OPTIMIZE)
	CFLAGS	+= -Ofast -march=native -mtune=native -pipe -fpic
else ifeq ($(FLAG),SANITIZE)
	CFLAGS	+= -g -fsanitize="address" -fno-omit-frame-pointer -I$(INC_DIR)
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
