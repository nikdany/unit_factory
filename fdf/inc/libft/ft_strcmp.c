/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:31:39 by mdanylch          #+#    #+#             */
/*   Updated: 2018/12/06 15:50:56 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *str1, const char *str2)
{
	while ((*(unsigned char *)str1 || *(unsigned char *)str2))
	{
		if (*(unsigned char *)str1 == *(unsigned char *)str2)
		{
			str1++;
			str2++;
		}
		else
			return (*(unsigned char *)str1 - *(unsigned char *)str2);
	}
	return (0);
}
