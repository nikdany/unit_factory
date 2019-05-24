/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:57:11 by mdanylch          #+#    #+#             */
/*   Updated: 2018/12/06 16:02:49 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strncmp(const char *str1, const char *str2, size_t len)
{
	while (len > 0 && (*(unsigned char *)str1 || *(unsigned char *)str2))
	{
		if (*(unsigned char *)str1 == *(unsigned char *)str2)
		{
			str1++;
			str2++;
			len--;
		}
		else
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
	}
	return (0);
}
