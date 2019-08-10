/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_controls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 20:59:26 by mdanylch          #+#    #+#             */
/*   Updated: 2019/07/18 16:18:37 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		ft_controls(int key, t_base *base)
{
	if (key == KEY_M && base->win->lock_key == 0)
		base->win->lock_key = 1;
	else if (key == KEY_M)
		base->win->lock_key = 0;
	else if (key == KEY_ESCAPE)
		exit(0);
	else if (key == KEY_R)
		fractol_initiation(base);
	else if (key == KEY_SPACE)
		base->fractal.color = rand() % SHIFT;
	else if (key == KEY_C)
		ft_colorize(base);
	else if ((key == KEY_EQUALS || key == KEY_KEYPADPLUS) \
								&& base->fractal.iteration < 500)
		base->fractal.iteration++;
	else if ((key == KEY_MINUS || key == KEY_KEYPADMINUS) \
								&& base->fractal.iteration > 5)
		base->fractal.iteration--;
	fractol_thread(*base);
	return (0);
}

void	ft_colorize(t_base *base)
{
	static int i = 0;

	if (i == 0)
		base->fractal.color = 000003000;
	else if (i == 1)
		base->fractal.color = 000000014;
	else if (i == 2)
		base->fractal.color = 002400000;
	else if (i == 3)
		base->fractal.color = 004001006;
	if (++i > 3)
		i = 0;
}

int		mouse_scroll(int key, int x, int y, t_base *base)
{
	double mouse_re;
	double mouse_im;
	double ratio;

	if ((key == MOUSE_SUP && B->F.max_re < 25) || key == MOUSE_SDOWN)
	{
		ratio = (key == MOUSE_SDOWN ? 1.1 : 0.9);
		if (key == MOUSE_SUP && B->F.iteration > 5)
			B->F.iteration--;
		else if (key == MOUSE_SDOWN && B->F.iteration < 500 && B->F.max_re < 5)
			B->F.iteration++;
		y = RESOLUTION - y;
		mouse_re = (double)x / (RESOLUTION / (B->F.max_re - \
					B->F.min_re)) + B->F.min_re;
		mouse_im = (double)y / (RESOLUTION /
			(B->F.max_im - B->F.min_im)) + B->F.min_im;
		B->F.min_re = mouse_re + ((B->F.min_re - mouse_re) * (1 / ratio));
		B->F.min_im = mouse_im + ((B->F.min_im - mouse_im) * (1 / ratio));
		B->F.max_re = mouse_re + ((B->F.max_re - mouse_re) * (1 / ratio));
		B->F.max_im = mouse_im + ((B->F.max_im - mouse_im) * (1 / ratio));
		B->F.re_fa = (B->F.max_re - B->F.min_re) / (RESOLUTION - 1);
		B->F.in_fa = (B->F.max_im - B->F.min_im) / (RESOLUTION - 1);
		fractol_thread(*B);
	}
	return (0);
}

int		mouse_move(int x, int y, t_base *base)
{
	if (base->win->lock_key == 1)
	{
		base->fractal.mouse_re = (x * 2);
		base->fractal.mouse_im = (y * 2 - 1000);
		fractol_thread(*base);
	}
	return (0);
}

int		close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
