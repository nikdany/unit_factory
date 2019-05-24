/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_figure_ch.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:27:20 by sshevchu          #+#    #+#             */
/*   Updated: 2019/04/29 14:27:23 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_FIGURE_CH_H
# define CHECK_FIGURE_CH_H

# ifndef T_V32QI
#  define T_V32QI

typedef __attribute__((__ext_vector_type__(32),__aligned__(32))) char	t_v32qi;

# endif

# ifndef POP_COUNT
#  define POP_COUNT(u) (__builtin_popcount((unsigned)u))
# endif

# ifndef PMOW_MSK
#  define PMOW_MSK(u) (__builtin_ia32_pmovmskb256(u))
# endif

enum	e_checks
{
	ch_newline,
	ch_____dot,
	ch____hash
};

t_v32qi	init_test(const char *restrict input) __attribute__
((__target__("avx2"),__const__));

t_v32qi	init_check_mask(unsigned v) __attribute__
((__target__("avx2"),__const__));

int		init_check_calc(unsigned v, t_v32qi test_buffer) __attribute__
((__target__("avx2"),__const__));

_Bool	init_checks_array(unsigned v,
		const int *restrict check_epi,
		t_v32qi buf) __attribute__
((__target__("avx2"),__const__));

_Bool	check_figure_ch(const char *restrict input) __attribute__
((target("avx2"),__const__,__aligned__));

#endif
