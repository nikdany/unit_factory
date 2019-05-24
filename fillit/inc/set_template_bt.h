/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_template_bt.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:30:15 by sshevchu          #+#    #+#             */
/*   Updated: 2019/04/29 14:30:28 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_TEMPLATE_BT_H
# define SET_TEMPLATE_BT_H

# include <string.h>

# ifndef T_V32QI
#  define T_V32QI

typedef __attribute__((__ext_vector_type__(32),__aligned__(32))) char	t_v32qi;

# endif

size_t	set_template_bt(const char *input) __attribute__
((__target__("avx2"),__const__,__aligned__));

#endif
