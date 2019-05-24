/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:15:28 by sshevchu          #+#    #+#             */
/*   Updated: 2019/04/29 14:15:30 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strnew.h"

static void		*ft_memset(void *b, int c, size_t len)
{
	while (len > 0)
	{
		len--;
		((unsigned char*)b)[len] = (unsigned char)c;
	}
	return (b);
}

static void		ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

static void		*ft_memalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

unsigned char	*ft_strnew(size_t size)
{
	return (ft_memalloc((size + 1) * sizeof(char)));
}
