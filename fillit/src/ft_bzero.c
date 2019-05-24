/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:13:26 by sshevchu          #+#    #+#             */
/*   Updated: 2019/04/29 14:13:28 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bzero.h"

static void		*ft_memset(void *restrict b, int c, size_t len)
{
	while (len > 0)
	{
		len--;
		((unsigned char *)b)[len] = (unsigned char)c;
	}
	return (b);
}

void			ft_bzero(void *restrict s, size_t n)
{
	ft_memset(s, 0, n);
}
