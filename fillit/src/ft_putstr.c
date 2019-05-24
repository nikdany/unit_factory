/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:14:32 by sshevchu          #+#    #+#             */
/*   Updated: 2019/04/29 14:14:56 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putstr.h"

static size_t	ft_strlen(const unsigned char *restrict s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void		ft_putstr_fd(const unsigned char *restrict s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void			ft_putstr(const unsigned char *restrict s)
{
	ft_putstr_fd(s, 1);
}
