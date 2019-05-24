/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:13:49 by sshevchu          #+#    #+#             */
/*   Updated: 2019/04/29 14:13:52 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putendl.h"

static void		ft_putchar_fd(unsigned char c, int fd)
{
	write(fd, &c, sizeof(c));
}

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

static void		ft_putendl_fd(const unsigned char *restrict s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void			ft_putendl(const unsigned char *restrict s)
{
	ft_putendl_fd(s, 1);
}
