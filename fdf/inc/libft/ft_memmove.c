/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:13:13 by mdanylch          #+#    #+#             */
/*   Updated: 2018/12/10 19:41:56 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if ((int)n >= 0)
	{
		while (n--)
		{
			if (dest <= src)
			{
				((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
				i++;
			}
			else
				((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
		return (dest);
	}
	return (NULL);
}
