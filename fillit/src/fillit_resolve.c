/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_resolve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:18:10 by sshevchu          #+#    #+#             */
/*   Updated: 2019/04/29 15:02:06 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "fillit.h"

static _Bool			solve_map(t_tet_lst *restrict tetrominoe,
									const unsigned char size,
									unsigned short *restrict map)
{
	const t_tet_lst			*t = tetrominoe;
	const unsigned char		pos = t->next ? t->next->x + t->next->y * size : 0;
	t_map_offset			*map_offset;

	if (tetrominoe->id == 0)
		return (1);
	tetrominoe->y = (pos / size) - 1;
	while (++(tetrominoe->y) <= size - tetrominoe->height)
	{
		tetrominoe->x = ((tetrominoe->y == (pos / size))
			? ((pos % size) - 1) : __UINT8_MAX__);
		while ((++(tetrominoe->x) <= size - tetrominoe->width)
		&& (map_offset = (t_map_offset*)(map + tetrominoe->y)))
			if (!(*map_offset & (tetrominoe->bit_mask >> tetrominoe->x)))
			{
				*map_offset ^= tetrominoe->bit_mask >> tetrominoe->x;
				if (solve_map(tetrominoe + 1, size, map))
					return (1);
				*map_offset ^= tetrominoe->bit_mask >> tetrominoe->x;
			}
	}
	tetrominoe->x = 0;
	tetrominoe->y = 0;
	return (0);
}

unsigned char			solve(t_tet_lst *restrict tetris,
								const int count,
								unsigned short *restrict map)
{
	unsigned char		solve_cnt;

	solve_cnt = 2;
	while (solve_cnt * solve_cnt < count * 4)
		solve_cnt++;
	while (!(solve_map(tetris, solve_cnt, map)) && (solve_cnt <= 16))
	{
		ft_bzero(map, sizeof(unsigned short) * 16);
		solve_cnt++;
	}
	return (solve_cnt == 17 ? 0 : solve_cnt);
}
