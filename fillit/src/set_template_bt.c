/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_template_bt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:17:47 by sshevchu          #+#    #+#             */
/*   Updated: 2019/04/29 14:17:58 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set_template_bt.h"

size_t	set_template_bt(const char *input)
{
	const t_v32qi	check_hash = (const t_v32qi){ 0 } | '#';
	size_t			check_hash_pos;

	check_hash_pos =
		(size_t)__builtin_ia32_pmovmskb256(check_hash == (const t_v32qi){
			input[0x00], input[0x01], input[0x02], input[0x03],
			input[0x05], input[0x06], input[0x07], input[0x08],
			input[0x0A], input[0x0B], input[0x0C], input[0x0D],
			input[0x0F], input[0x10], input[0x11], input[0x12] });
	return ((const size_t){ 0UL
		| (((check_hash_pos & 0x000FUL) >> 0x0UL) << 0 * 8UL)
		| (((check_hash_pos & 0x00F0UL) >> 0x4UL) << 2 * 8UL)
		| (((check_hash_pos & 0x0F00UL) >> 0x8UL) << 4 * 8UL)
		| (((check_hash_pos & 0xF000UL) >> 0xCUL) << 6 * 8UL) });
}
