/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 20:16:53 by mdanylch          #+#    #+#             */
/*   Updated: 2019/07/18 06:31:53 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void			fractol_select(t_type *f)
{
	if (f->num == 1)
		f->ft_select = ft_mandelbrot;
	else if (f->num == 2)
		f->ft_select = ft_julia;
	else if (f->num == 3)
		f->ft_select = ft_circle;
	else if (f->num == 4)
		f->ft_select = ft_ship;
	else if (f->num == 5)
		f->ft_select = ft_chameleon;
	else if (f->num == 6)
		f->ft_select = ft_buffalo;
	else if (f->num == 7)
		f->ft_select = ft_tricorn;
	else if (f->num == 8)
		f->ft_select = ft_lilies;
}

void			fractol_count_next(t_base *base, int addr_v2)
{
	int		n;

	n = -1;
	while (++n < B->F.iteration)
	{
		if (POW(B->F.new_re) + POW(B->F.new_im) > 4)
		{
			*(int *)(B->win->addr + addr_v2) = B->F.color * n;
			B->F.isi = 0;
			break ;
		}
		B->F.new_im = B->F.ft_select(&B->F);
	}
}

void			*fractol_count(t_base *base)
{
	int		x;
	int		y_end;
	int		y_start;
	int		addr_v2;

	y_start = (RESOLUTION / B->thread) * B->id - 1;
	y_end = (RESOLUTION / B->thread) * (B->id + 1);
	while (++y_start < y_end)
	{
		B->F.var_imag = B->F.max_im - y_start * B->F.in_fa;
		x = -1;
		while (++x < RESOLUTION)
		{
			addr_v2 = (y_start * RESOLUTION + x) * 4;
			B->fractal.var_real = B->fractal.min_re + x * B->fractal.re_fa;
			B->fractal.new_re = B->fractal.var_real;
			B->F.new_im = B->F.var_imag;
			B->F.isi = 1;
			fractol_count_next(base, addr_v2);
		}
	}
	return (NULL);
}

static	void	fractol_manual(t_base *base)
{
	mlx_string_put(base->win->ptr, base->win->win, \
	170, 30, 0xA9A9A9, "MANUAL:");
	mlx_string_put(base->win->ptr, base->win->win, \
	30, 60, 0xA9A9A9, "Zoom in/out       - [SCROLL]");
	mlx_string_put(base->win->ptr, base->win->win, \
	30, 80, 0xA9A9A9, "Iterations +/-    - [+] or [-]");
	mlx_string_put(base->win->ptr, base->win->win, \
	30, 100, 0xA9A9A9, "Use mouse (Julia) - [M]");
	mlx_string_put(base->win->ptr, base->win->win, \
	30, 120, 0xA9A9A9, "Colorize          - [C]");
	mlx_string_put(base->win->ptr, base->win->win, \
	30, 140, 0xA9A9A9, "Colorize random   - [SPACE]");
	mlx_string_put(base->win->ptr, base->win->win, \
	30, 160, 0xA9A9A9, "Reset             - [R]");
	mlx_string_put(base->win->ptr, base->win->win, \
	30, 200, 0xA9A9A9, "Exit              - [ESC]");
}

void			fractol_thread(t_base base)
{
	pthread_t		thread[base.thread];
	t_base			tmp[base.thread];
	int				i;

	i = -1;
	while (++i < base.thread)
	{
		tmp[i] = base;
		tmp[i].id = i;
		pthread_create(&thread[i], NULL, (void *)fractol_count, &tmp[i]);
	}
	i = -1;
	while (++i < base.thread)
		pthread_join(thread[i], NULL);
	mlx_clear_window(base.win->ptr, base.win->win);
	mlx_put_image_to_window(base.win->ptr, base.win->win, base.win->img, 0, 0);
	if (base.win->first == 0)
		fractol_manual(&base);
	mlx_destroy_image(base.win->ptr, base.win->img);
	base.win->img = mlx_new_image(base.win->ptr, RESOLUTION, RESOLUTION);
}
