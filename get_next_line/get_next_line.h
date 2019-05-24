/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:31:06 by mdanylch          #+#    #+#             */
/*   Updated: 2019/04/24 17:33:31 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"
# define BUFF_SIZE 1000000
# define CLEAR(x, y, z) x = y; y = z; ft_strdel(&x);

typedef	struct		s_gnl
{
	int				fd;
	char			*buf;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
