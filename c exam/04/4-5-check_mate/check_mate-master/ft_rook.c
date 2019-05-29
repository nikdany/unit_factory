/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibiya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 14:26:25 by ssibiya           #+#    #+#             */
/*   Updated: 2017/08/01 15:38:10 by ssibiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkmate.h"

int	ft_rook(char **board, int y, int x)
{
	int	len;
	int	j;

	len = (int)ft_strlen(board[y]);
	j = x;
	while (++j < len && ft_opiece(board[y][j]) != 1) //Horizontal++
	{
		if (board[y][j] == 'K')
			return (1);
	}
	j = x;
	while (--j >= 0 && ft_opiece(board[y][j]) != 1) //Horizontal--
	{
		if (board[y][j] == 'K')
			return (1);
	}
	j = y;
	while (++j <= len && ft_opiece(board[j][x]) != 1) //Vertical--
	{
		if (board[j][x] == 'K')
			return (1);
	}
	j = y;
	while (--j >= 1 && ft_opiece(board[j][x]) != 1) //Vertical++
	{
		if (board[j][x] == 'K')
			return (1);
	}
	return (0);
}
