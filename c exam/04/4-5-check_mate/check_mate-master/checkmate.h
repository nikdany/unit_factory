/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmate.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssibiya <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 14:12:04 by ssibiya           #+#    #+#             */
/*   Updated: 2017/08/01 15:57:53 by ssibiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CHECKMATE_H
#define _CHECKMATE_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *s);
int		ft_opiece(char piece);
int		ft_rook(char **board, int y, int x);
int		ft_pawn(char **board, int y, int x);
int		ft_bishop(char **board, int y, int x);

#endif
