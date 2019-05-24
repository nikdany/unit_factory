/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 01:16:56 by mdanylch          #+#    #+#             */
/*   Updated: 2019/05/01 03:24:28 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		ft_key_in(int key, t_fdf *base)
{
	if (key == 53)
		exit(0);
	if (key == 19)
		base->iso = 1;
	else if (key == 18)
		base->iso = 0;
	else if (key == 20)
		base->iso = 2;
	else if (key == 69 && base->go < 100)
		base->go += 1;
	else if (key == 78 && base->go > 1)
		base->go -= 1;
	else if (key == 67)
		base->z += 4;
	else if (key == 75)
		base->z -= 4;
	ft_render(base);
	return (0);
}

void	ft_win_settings(t_fdf *base)
{
	base->x_in = 1280 / 2 - base->go * (base->c / 2);
	base->y_in = 720 / 2 - base->go * (base->l / 2);
	if (base->all_x == NULL && base->all_y == NULL)
	{
		base->all_x = malloc(sizeof(int) * base->c);
		base->all_y = malloc(sizeof(int) * base->c);
	}
	mlx_clear_window(base->mlx, base->win);
}

void	ft_algoritm(t_fdf *base)
{
	INT8(delta_x, delta_y, ofst_1, ofst_2, sign_x, sign_y, x, y);
	sign_x = base->x0 < base->x1 ? 1 : -1;
	sign_y = base->y0 < base->y1 ? 1 : -1;
	delta_x = abs(base->x1 - base->x0);
	delta_y = abs(base->y1 - base->y0);
	ofst_1 = delta_x - delta_y;
	x = base->x0;
	y = base->y0;
	while (x != base->x1 || y != base->y1)
	{
		ofst_2 = ofst_1 * 2;
		mlx_pixel_put(base->mlx, base->win, x, y, 0x00FFFF);
		if (ofst_2 > -delta_y)
		{
			ofst_1 = ofst_1 - delta_y;
			x = x + sign_x;
		}
		if (ofst_2 < delta_x)
		{
			ofst_1 = ofst_1 + delta_x;
			y = y + sign_y;
		}
	}
}

void	ft_iso(t_fdf *base, int i, int j)
{
	int p_x;
	int p_y;
	int p_z;

	p_x = base->x1;
	p_y = base->y1;
	p_z = base->altitude[i][j];
	if (p_z != 0)
		p_z += base->z;
	if (base->iso == 1)
	{
		base->x1 = (p_x - p_y) * cos(0.523599)\
				+ (1100 / 2 - base->go * (base->c / 2));
		base->y1 = -p_z + (p_x + p_y) * sin(0.523599)\
			- (500 / 2 - base->go * (base->l / 2));
	}
	else
	{
		base->y1 = p_y * cos(1.5708) + p_z * sin(-1.5708)
			+ (1000 / 2 - base->go * (base->l / 2));
	}
}

void	ft_render(t_fdf *b)
{
	INT2(i, j);
	INI2(i, -1, j, -1);
	ft_win_settings(b);
	while (++i < b->l)
	{
		while (++j < b->c)
		{
			INI2(b->x1, (b->x_in + b->go * j), b->y1, (b->y_in + b->go * i));
			b->iso > 0 ? ft_iso(b, i, j) : 0;
			j != 0 ? ft_algoritm(b) : 0;
			INI2(b->x0, b->x1, b->y0, b->y1);
			if (i > 0)
			{
				INI3(b->x1, b->all_x[j], b->y0, b->y1, b->y1, b->all_y[j]);
				ft_algoritm(b);
			}
			b->x1 = b->x_in + b->go * j;
			b->y1 = b->y_in + b->go * i;
			if (b->iso == 1 || b->iso == 2)
				ft_iso(b, i, j);
			b->all_x[j] = b->x1;
			b->all_y[j] = b->y1;
		}
		j = -1;
	}
}
