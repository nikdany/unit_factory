/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_figure_ch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:12:58 by sshevchu          #+#    #+#             */
/*   Updated: 2019/04/29 14:13:03 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_figure_ch.h"

inline t_v32qi	init_test(const char *restrict input)
{
	return ((const t_v32qi){
			input[0x00], input[0x01], input[0x02], input[0x03], input[0x04],
			input[0x05], input[0x06], input[0x07], input[0x08], input[0x09],
			input[0x0A], input[0x0B], input[0x0C], input[0x0D], input[0x0E],
			input[0x0F], input[0x10], input[0x11], input[0x12], input[0x13] });
}

inline t_v32qi	init_check_mask(unsigned v)
{
	return ((const t_v32qi[]){
			(const t_v32qi){ 0 } | '\n',
			(const t_v32qi){ 0 } | '.',
			(const t_v32qi){ 0 } | '#' }[v]);
}

inline int		init_check_calc(unsigned v, t_v32qi test_buffer)
{
	return ((const int[]){
			PMOW_MSK(init_check_mask(ch_newline) == test_buffer),
			PMOW_MSK(init_check_mask(ch_____dot) == test_buffer),
			PMOW_MSK(init_check_mask(ch____hash) == test_buffer) }[v]);
}

inline _Bool	init_checks_array(unsigned v,
								const int *restrict check_epi,
								t_v32qi buf)
{
	return ((const _Bool[]){
	check_epi[ch_newline] == init_check_calc(ch_newline, buf),
	check_epi[ch_____dot] == POP_COUNT(init_check_calc(ch_____dot, buf)),
	check_epi[ch____hash] == POP_COUNT(init_check_calc(ch____hash, buf)) }[v]);
}

_Bool			check_figure_ch(const char *restrict input)
{
	const t_v32qi	test_buffer = (const t_v32qi){ init_test(input) };
	const int		*check_epi = (const int[]){ 0x84210, 0x0000C, 0x00004 };

	return (init_checks_array(ch_newline, check_epi, test_buffer)
		&& init_checks_array(ch_____dot, check_epi, test_buffer)
		&& init_checks_array(ch____hash, check_epi, test_buffer));
}
