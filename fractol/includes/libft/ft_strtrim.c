/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:09:59 by mdanylch          #+#    #+#             */
/*   Updated: 2019/01/24 19:19:42 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	while (ft_isspace(s[i]) && s[i])
		i++;
	j = ft_strlen(s + i) - 1;
	while (s[i] && ft_isspace(s[j + i]))
		j--;
	return (ft_strsub(s, i, j + 1));
}
