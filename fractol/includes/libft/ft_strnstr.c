/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:33:36 by mdanylch          #+#    #+#             */
/*   Updated: 2018/12/06 13:14:59 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		i = 0;
		while (*(needle + i) && *(haystack + i) && len - i > 0
				&& *(needle + i) == *(haystack + i))
			i++;
		if (!*(needle + i))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
