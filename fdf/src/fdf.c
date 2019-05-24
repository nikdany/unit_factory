/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:30:12 by mdanylch          #+#    #+#             */
/*   Updated: 2019/05/01 05:27:19 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_fdf	*ft_init_base(void)
{
	t_fdf *base;

	base = malloc(sizeof(t_fdf));
	base->l = 0;
	base->c = 0;
	base->mlx = mlx_init();
	base->win = mlx_new_window(base->mlx, 1280, 720, "FDF");
	base->go = 20;
	base->x_in = 100;
	base->y_in = 100;
	base->iso = 0;
	base->z = 0;
	return (base);
}

int		ft_digit_nbr(char const *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		i = str[i] == '-' ? (i + 1) : i;
		if (str[i] && ft_isdigit(str[i]))
		{
			while (str[i] && ft_isdigit(str[i]))
				i++;
			j++;
		}
		if ((str[i] != '\0' && str[i] != ' ' && str[i] != '-'))
			return (0);
	}
	return (j);
}

int		ft_lines_nbr(char *str, t_fdf *base)
{
	char	*line;

	INT2(i, fd);
	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		close(fd);
		return (-1);
	}
	while (get_next_line(fd, &line) == 1)
	{
		if ((i = ft_digit_nbr(line)) > base->c)
			base->c = i;
		if (base->c == i && base->c != 0)
			base->l++;
		else
		{
			ft_strdel(&line);
			return (-1);
		}
		ft_strdel(&line);
	}
	close(fd);
	return (open(str, O_RDONLY));
}

int		ft_read_fdf(char *str, t_fdf *base)
{
	char	*line;
	char	**tmp;

	INT3(i, j, fd);
	INI2(i, -1, j, -1);
	if ((fd = ft_lines_nbr(str, base)) < 0)
		return (0);
	base->altitude = (int**)malloc(sizeof(int*) * base->l);
	while ((get_next_line(fd, &line)) > 0 && ++i < base->l)
	{
		base->altitude[i] = (int *)malloc(sizeof(int) * base->c);
		tmp = ft_strsplit(line, ' ');
		while (++j < base->c)
			base->altitude[i][j] = ft_atoi(tmp[j]);
		while (j > -1)
			ft_strdel(&tmp[j--]);
		ft_strdel(&line);
		free(tmp);
	}
	close(fd);
	return (1);
}

int		main(int argc, char **argv)
{
	t_fdf	*base;

	if (argc == 2)
	{
		base = ft_init_base();
		if (ft_read_fdf(argv[1], base) == 0)
		{
			ft_putstr("Not valid map!\n");
			return (0);
		}
		ft_render(base);
		mlx_hook(base->win, 2, 4, ft_key_in, base);
		mlx_hook(base->win, 17, 4, ft_close, (void *)0);
		mlx_loop(base->mlx);
	}
	else
		ft_putstr("Usage: ./fdf file\n");
	return (0);
}
