/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:44:47 by mdanylch          #+#    #+#             */
/*   Updated: 2018/12/05 19:45:47 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(str1 + i))
		i++;
	while (*(str2 + j) && j < n)
	{
		*(str1 + i) = *(str2 + j);
		i++;
		j++;
	}
	*(str1 + i) = '\0';
	return (str1);
}
