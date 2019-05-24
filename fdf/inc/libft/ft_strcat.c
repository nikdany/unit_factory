/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:51:16 by mdanylch          #+#    #+#             */
/*   Updated: 2018/12/05 19:51:20 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (*(str1 + i))
		i++;
	while (*str2)
	{
		*(str1 + i) = *str2;
		i++;
		str2++;
	}
	*(str1 + i) = '\0';
	return (str1);
}
