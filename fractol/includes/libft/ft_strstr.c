/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:39:22 by mdanylch          #+#    #+#             */
/*   Updated: 2018/12/06 13:12:44 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		i = 0;
		while (*(needle + i) && *(needle + i) == *(haystack + i))
			i++;
		if (!*(needle + i))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
