/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibiya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 14:05:59 by ssibiya           #+#    #+#             */
/*   Updated: 2017/08/01 15:56:30 by ssibiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkmate.h"

static int	ft_checkmate(char **av)
{
	int	i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == 'R' && ft_rook(av, i, j) == 1)
				return (1);
			if (av[i][j] == 'P' && ft_pawn(av, i, j) == 1)
				return (1);
			if (av[i][j] == 'B' && ft_bishop(av, i, j) == 1)
				return (1);
			if (av[i][j] == 'Q' && (ft_bishop(av, i, j) == 1 || ft_rook(av, i, j) == 1))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int main (int ac, char **av)
{
	if (ac > 1 && ac == (int)(ft_strlen(av[1]) + 1))
	{
		int	i;

		i = 1;
		while (av[i] != NULL)
		{
			if (((int)ft_strlen(av[i]) + 1) == ac)
				i++;
			else
			{
				write(1, "Fail\n", 5);
				return (0);
			}
		}
		if (ft_checkmate(av) == 1)
			write(1, "Success\n", 8);
		else
			write(1, "Fail\n", 5);
	}
	else if (ac > 1)
		write(1, "Fail\n", 5);
	else
		write(1, "\n", 1);
	return (0);
}
