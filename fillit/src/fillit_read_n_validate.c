/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read_n_validate                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:17:22 by sshevchu          #+#    #+#             */
/*   Updated: 2019/04/29 14:56:42 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"
#include "set_template_bt.h"
#include "check_figure_ch.h"
#include "check_figure_bt.h"
#include "lsb_l.h"
#include "gen_tetrominoe_template_bt.h"

static _Bool		check_tetrominoe(const unsigned char *restrict s)
{
	return (check_figure_bt(set_template_bt((const char*)s))
		&& check_figure_ch((const char*)s));
}

static void			hashes_pattern(const unsigned char *restrict str,
									unsigned char *restrict figure)
{
	unsigned char	i;
	unsigned char	x;
	unsigned char	y;

	(void)((*(figure + 0) += 3) | (*(figure + 2) += 3));
	i = __UINT8_MAX__;
	while (++i < 20)
		if (*(str + i) == '#')
		{
			y = i / 5;
			x = i % 5;
			if (x < *(figure + 0))
				*(figure + 0) = x;
			if (x > *(figure + 1))
				*(figure + 1) = x;
			if (y < *(figure + 2))
				*(figure + 2) = y;
			if (y > *(figure + 3))
				*(figure + 3) = y;
		}
}

static t_tet_lst	get_tetrominoe(const unsigned char *restrict str,
									const unsigned char id)
{
	t_tet_lst		tetrominoe;
	unsigned char	figure[4];
	unsigned char	x;
	unsigned char	y;

	ft_bzero(figure, 4);
	hashes_pattern(str, figure);
	tetrominoe = (const t_tet_lst){
			.id = id,
			.width = (*(figure + 1) - *(figure + 0) + 1),
			.height = (*(figure + 3) - *(figure + 2) + 1) };
	y = __UINT8_MAX__;
	while (++y < tetrominoe.height)
	{
		x = __UINT8_MAX__;
		while (++x < tetrominoe.width)
			if (str[(*(figure + 2) + y) * 5 + *(figure + 0) + x] == '#')
				tetrominoe.bit_mask |= (1UL << (size_t)(16 * (y + 1) - 1 - x));
	}
	return (tetrominoe);
}

unsigned char		read_tetri(const int fd, t_tet_lst *restrict tetrominoe)
{
	unsigned char	buf[22];
	unsigned char	len;
	unsigned char	name;
	unsigned char	x;
	unsigned char	y;

	name = 'A';
	y = __UINT8_MAX__;
	len = 1;
	while (len != 0)
	{
		ft_bzero(buf, 21);
		read(fd, buf, 20);
		if (!check_tetrominoe(buf))
			return (0);
		tetrominoe[++y] = get_tetrominoe(buf, name++);
		x = y;
		while (--x != __UINT8_MAX__)
			if (tetrominoe[y].bit_mask == tetrominoe[x].bit_mask)
				tetrominoe[y].next = tetrominoe + x;
		len = (unsigned char)read(fd, buf + 21, 1);
		if (buf[21] != '\n')
			return (0);
	}
	return (name - 'A');
}
