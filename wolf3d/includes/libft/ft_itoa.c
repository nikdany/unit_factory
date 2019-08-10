/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:31:39 by mdanylch          #+#    #+#             */
/*   Updated: 2019/01/20 19:53:18 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nb;

	nb = n;
	i = 1;
	if (n < 0)
		i++;
	while ((n = n / 10))
		i++;
	if (!(str = ft_memalloc(i + 1)))
		return (NULL);
	n = nb < 0 ? -1 : 1;
	nb *= n;
	while (i--)
	{
		if (i == 0 && n == -1)
			str[i] = '-';
		else
			str[i] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
