/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_formulas_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 22:11:19 by mdanylch          #+#    #+#             */
/*   Updated: 2019/07/18 05:11:31 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

double	ft_mandelbrot(t_type *fractal)
{
	F->old_im = F->new_im;
	F->old_re = F->new_re;
	fractal->new_im = 2 * F->old_re * F->old_im + fractal->var_imag;
	fractal->new_re = POW(F->old_re) - POW(F->old_im) + fractal->var_real;
	return (fractal->new_im);
}

double	ft_julia(t_type *fractal)
{
	INI2(F->old_im, F->new_im, F->old_re, F->new_re);
	F->new_im = 2 * F->new_re * F->new_im + F->mouse_im / RESOLUTION;
	F->new_re = POW(F->old_re) - POW(F->old_im) + F->mouse_re / RESOLUTION;
	return (fractal->new_im);
}

double	ft_circle(t_type *fractal)
{
	fractal->new_im = 2.0 * (F->new_im + (F->var_real - 50 * F->var_imag));
	fractal->new_re = 2.0 * (F->new_re + (50 * F->var_real - F->var_imag));
	return (fractal->new_im);
}

double	ft_ship(t_type *fractal)
{
	INI2(F->old_im, F->new_im, F->old_re, F->new_re);
	fractal->new_im = fabs(2 * fractal->new_re * F->new_im) - fractal->var_imag;
	fractal->new_re = fabs(POW(F->old_re) - POW(F->old_im) + fractal->var_real);
	return (fractal->new_im);
}
