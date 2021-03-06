/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_tetrominoe_template_bt.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:16:03 by sshevchu          #+#    #+#             */
/*   Updated: 2019/04/29 14:16:13 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gen_tetrominoe_template_bt.h"

size_t	gen_tetrominoe_template_bt(size_t nth_case)
{
	return ((const size_t[]){
		0x000000000000000FUL, 0x0001000100010001UL,
		0x0000000000030003UL, 0x0000000000020007UL,
		0x0000000100030001UL, 0x0000000000040007UL,
		0x0000000000070001UL, 0x0000000100010003UL,
		0x0000000000010007UL, 0x0000000200020003UL,
		0x0000000300010001UL, 0x0000000200030001UL,
		0x0000000000060003UL, 0x0000000200030002UL,
		0x0000000000070002UL, 0x0000000300020002UL,
		0x0000000000030006UL, 0x0000000100030002UL,
		0x0000000000070004UL, 0x0000000000000000UL
	}[nth_case]);
}
