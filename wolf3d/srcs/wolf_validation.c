/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:38:15 by mdanylch          #+#    #+#             */
/*   Updated: 2019/08/07 13:29:29 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/wolf3d.h"

void			ft_puterror(const char *msg, int ret)
{
	ft_putendl(msg);
	exit(ret);
}

static	int		ft_digit_nbr(char const *str, int i)
{
	while (str[i] && (str[i] == ' ' || str[i] == '1' || str[i] == 'P'))
		i++;
	if ((str[i] != '\0'))
		ft_puterror(ERR_SYMBOL, i);
	if (i < 3 || i > 100)
		ft_puterror(ERR_LENGTH, i);
	return (i);
}

static	int		ft_lines_nbr(char *str, t_base *base, int i, char *line)
{
	base->fd = open(str, O_RDONLY);
	if (base->fd < 0 || read(base->fd, 0, 0) < 0)
		ft_puterror(ERR_MAP, base->fd);
	while (get_next_line(base->fd, &line) == 1)
	{
		if ((i = ft_digit_nbr(line, 0)) > W3D.size.x && W3D.size.x == 0)
			W3D.size.x = i;
		if (W3D.size.x == i && W3D.size.x != 0)
			W3D.size.y++;
		else
		{
			ft_strdel(&line);
			return (-1);
		}
		ft_strdel(&line);
	}
	if (W3D.size.y < 3 || W3D.size.y > 100)
		ft_puterror(ERR_HEIGHT, W3D.size.y);
	close(base->fd);
	return (open(str, O_RDONLY));
}

static	void	ft_write_map(t_base *base, int i, int j, char *tmp)
{
	while (++j < W3D.size.x)
	{
		if ((i == 0 || i == (W3D.size.y - 1) || j == 0 \
			|| j == (W3D.size.x - 1)) && (tmp[j] != WALL))
			ft_puterror(ERR_WALL, j);
		if (tmp[j] != FREE && tmp[j] != PLYR && tmp[j] != WALL)
			ft_puterror(ERR_SYMBOL, j);
		if (tmp[j] == FREE && !W3D.player)
		{
			W3D.pos.x = j + 0.5;
			W3D.pos.y = i + 0.5;
			W3D.player = -1;
		}
		if (tmp[j] == PLYR && W3D.player <= 0)
		{
			W3D.pos.x = j + 0.5;
			W3D.pos.y = i + 0.5;
			W3D.player = 1;
		}
		W3D.wmap[i][j] = tmp[j];
	}
}

void			wolf_validation(char *str, t_base *base, int i)
{
	char	*line;
	int		fd;

	if ((fd = ft_lines_nbr(str, base, 0, "0")) < 0)
		ft_puterror(ERR_LENGTH, base->fd);
	W3D.wmap = (char**)malloc(sizeof(char*) * W3D.size.y);
	while ((get_next_line(fd, &line)) > 0 && ++i < W3D.size.y)
	{
		W3D.wmap[i] = (char *)malloc(sizeof(char) * W3D.size.x);
		ft_write_map(base, i, -1, line);
		ft_strdel(&line);
	}
	if (W3D.player == 0)
		ft_puterror(ERR_FREE, base->fd);
}
