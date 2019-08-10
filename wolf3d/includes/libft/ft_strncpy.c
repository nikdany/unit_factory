/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:46:30 by mdanylch          #+#    #+#             */
/*   Updated: 2018/12/06 13:43:48 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(src);
	while (i < n)
	{
		if (i < j)
			*(dest + i) = *(src + i);
		else
			*(dest + i) = '\0';
		i++;
	}
	return (dest);
}
