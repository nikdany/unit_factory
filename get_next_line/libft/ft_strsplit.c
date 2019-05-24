/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 11:01:07 by mdanylch          #+#    #+#             */
/*   Updated: 2019/01/23 22:16:42 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	k;

	if (!s || !c ||
		!(str = (char**)ft_memalloc(sizeof(*str) * (ft_cntw(s, c) + 1))))
		return (NULL);
	k = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		i = 0;
		while (*(s + i) != c && *(s + i))
			i++;
		str[k] = *s ? ft_strsub(s, 0, i) : 0;
		if (*s && !str[k])
		{
			free(str[k]);
			return (NULL);
		}
		k++;
		s = s + i;
	}
	return (str);
}
