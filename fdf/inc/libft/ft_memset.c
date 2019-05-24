/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:13:30 by mdanylch          #+#    #+#             */
/*   Updated: 2018/12/05 20:01:03 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	SYNOPSIS
**void *memset(void *b, int c, size_t len);
**
**	DESCRIPTION
**The memset() function writes len bytes of
**value c (converted to an unsigned char) to the string b.
**
**	RETURN VALUES
**The memset() function returns its first argument.
*/

void	*ft_memset(void *dest, int c, size_t n)
{
	while (n > 0)
	{
		n--;
		*(((unsigned char *)dest) + n) = (unsigned char)c;
	}
	return (dest);
}
