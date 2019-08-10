/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_formulas_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 04:06:21 by mdanylch          #+#    #+#             */
/*   Updated: 2019/07/18 05:11:07 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

double	ft_chameleon(t_type *fractal)
{
	INI2(F->old_im, F->new_im, F->old_re, F->new_re);
	fractal->new_im = -2 * fractal->old_re * fractal->old_im + 0.02;
	fractal->new_re = POW(F->old_re) - POW(F->old_im) + 0.29;
	return (fractal->new_im);
}

double	ft_buffalo(t_type *fractal)
{
	INI2(F->old_im, F->new_im, F->old_re, F->new_re);
	fractal->new_im = 2 * fabs(F->old_re * F->old_im) - F->var_imag;
	fractal->new_re = fabs(POW(F->old_re) - POW(F->old_im)) + F->var_real;
	return (fractal->new_im);
}

double	ft_tricorn(t_type *fractal)
{
	INI2(F->old_im, F->new_im, F->old_re, F->new_re);
	fractal->new_im = -1 * (2 * F->old_re * F->old_im) + F->var_imag;
	fractal->new_re = POW(F->old_re) - POW(F->old_im) + F->var_real;
	return (fractal->new_im);
}

double	ft_lilies(t_type *fractal)
{
	INI2(F->old_im, F->new_im, F->old_re, F->new_re);
	fractal->new_im = -2 * F->old_re * F->old_im - 0.57;
	F->new_re = fabs(F->old_re * F->old_re - F->old_im * F->old_im) + 0.35;
	return (fractal->new_im);
}
