/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:27:39 by sshevchu          #+#    #+#             */
/*   Updated: 2019/04/29 15:05:03 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# ifndef MAX_TETRO_CNT
#  define MAX_TETRO_CNT 26
# endif

# include <string.h>
# include "ft_strnew.h"
# include "ft_strdel.h"
# include "ft_putstr.h"
# include "ft_putendl.h"
# include "ft_bzero.h"

# ifndef T_TET_LST
#  define T_TET_LST

typedef struct s_tetro_list			t_tet_lst;

# endif

# ifndef S_TETRO_LIST
#  define S_TETRO_LIST

struct								s_tetro_list
{
	t_tet_lst			*restrict	next;
	unsigned long					bit_mask;
	unsigned char					width;
	unsigned char					height;
	unsigned char					id;
	unsigned char					y;
	unsigned char					x;
	unsigned char					stub[3];
};

# endif

# ifndef T_MAP_OFFSET
#  define T_MAP_OFFSET

typedef unsigned long __attribute__
((__aligned__(2),__may_alias__))	t_map_offset;

# endif

unsigned char						read_tetri(const int fd,
												t_tet_lst *restrict tetris);
unsigned char						solve(t_tet_lst *restrict tetris,
												const int count,
												unsigned short *restrict map);

#endif
