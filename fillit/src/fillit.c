/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:17:02 by sshevchu          #+#    #+#             */
/*   Updated: 2019/04/29 15:01:24 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"

static unsigned char	*initialize_map(unsigned char solve_cnt)
{
	unsigned char		*str;
	unsigned char		x;
	unsigned char		y;

	str = ft_strnew(solve_cnt * (solve_cnt + 1));
	y = __UINT8_MAX__;
	while (++y < solve_cnt)
	{
		x = __UINT8_MAX__;
		while (++x < solve_cnt)
			str[y * (solve_cnt + 1) + x] = '.';
		str[y * (solve_cnt + 1) + x] = '\n';
	}
	return (str);
}

static void				display_map(t_tet_lst *restrict tetrominoe,
								unsigned char fig_cnt,
								unsigned char solve_cnt)
{
	unsigned char	*str;
	unsigned char	x;
	unsigned char	y;

	str = initialize_map(solve_cnt);
	while (fig_cnt > 0)
	{
		y = __UINT8_MAX__;
		while (++y < tetrominoe->height)
		{
			x = __UINT8_MAX__;
			while (++x < tetrominoe->width)
				if ((tetrominoe->bit_mask >> (16 * (y + 1) - 1 - x)) & 1U)
					str[(tetrominoe->y + y) * (solve_cnt + 1)
						+ x + tetrominoe->x] = tetrominoe->id;
		}
		tetrominoe++;
		fig_cnt--;
	}
	ft_putstr(str);
	ft_strdel(&str);
}

int						main(int argc, char **argv)
{
	t_tet_lst		tetrominoe[MAX_TETRO_CNT + 1];
	unsigned short	map[16];
	unsigned char	fig_cnt;
	unsigned char	solve_cnt;

	if (argc != 2)
	{
		ft_putendl((unsigned char *)"usage: ./fillit [input_file]");
		return (1);
	}
	ft_bzero(tetrominoe, sizeof(t_tet_lst) * (MAX_TETRO_CNT + 1));
	if (!(fig_cnt =
		(unsigned char)read_tetri(open(argv[1], O_RDONLY), tetrominoe)))
	{
		ft_putendl((unsigned char *)"error");
		return (1);
	}
	ft_bzero(map, sizeof(unsigned short) * 16);
	if ((solve_cnt = solve(tetrominoe, fig_cnt, map)) == 0)
	{
		ft_putendl((unsigned char *)"error");
		return (1);
	}
	display_map(tetrominoe, fig_cnt, solve_cnt);
	return (0);
}
