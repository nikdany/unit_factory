/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opiece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibiya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:37:02 by ssibiya           #+#    #+#             */
/*   Updated: 2017/08/01 15:38:01 by ssibiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checkmate.h"

int	ft_opiece(char piece)
{
	if (piece == 'P' || piece == 'Q' || piece == 'B' || piece == 'R')
		return (1);
	return (0);
}
