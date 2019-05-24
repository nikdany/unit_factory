/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:15:12 by sshevchu          #+#    #+#             */
/*   Updated: 2019/04/29 14:15:14 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strdel.h"

static void		ft_memdel(unsigned char *restrict *restrict ap)
{
	free(*ap);
	*ap = (NULL);
}

void			ft_strdel(unsigned char *restrict *restrict as)
{
	ft_memdel(as);
}
