/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_figure_bt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:12:32 by sshevchu          #+#    #+#             */
/*   Updated: 2019/04/29 14:12:39 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_figure_bt.h"
#include "gen_tetrominoe_template_bt.h"
#include "lsb_l.h"

extern size_t			check_figure_bt(size_t f)
{
	const size_t	shift = (const size_t)lsb_l(f);
	const size_t	test_limit = 13UL + 5UL + 1UL;
	size_t			i;
	size_t			j;

	j = ~0UL;
	while (++j < 3)
	{
		i = ~0UL;
		while (++i < test_limit)
			if ((f >> (shift - j)) == gen_tetrominoe_template_bt(i))
				return (f >> (shift - j));
	}
	return (0);
}
