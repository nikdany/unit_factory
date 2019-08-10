/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 19:46:33 by mdanylch          #+#    #+#             */
/*   Updated: 2019/08/10 15:19:13 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** Headers and libft.
*/
# include "./libft/libft.h"
# include "keys.h"

/*
** Libraries.
*/
# include <mlx.h>
# include <math.h>
# include <time.h>
# include <pthread.h>

/*
** Definitions.
*/
# define RESOLUTION			(850)
# define NAME				("Fractol mdanylch")
# define WHITE				(0xFFFFFF)
# define THREADS			(8)
# define F					fractal
# define B					base
# define C					count
# define SHIFT				14200000
# define POW(a)				((a) * (a))
# define INI2(a,av,b,bv) 	a=av;b=bv;

/*
** MLX-window structure.
*/
typedef struct	s_win
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*addr;
	int			bit;
	int			line_s;
	int			endia;
	int			lock_key;
	int			first;
}				t_win;
/*
** Fractal structure.
*/
typedef struct	s_type
{
	int			color;
	double		mouse_re;
	double		mouse_im;
	double		var_real;
	double		var_imag;
	double		new_re;
	double		new_im;
	double		old_re;
	double		old_im;
	double		max_re;
	double		min_re;
	double		max_im;
	double		min_im;
	double		re_fa;
	double		in_fa;
	double		iteration;
	int			num;
	int			isi;
	double		(*ft_select) (struct s_type *f);
}				t_type;
/*
** Base structure.
*/
typedef struct	s_base
{
	t_type		fractal;
	t_win		*win;
	int			thread;
	int			id;
	int			init;
}				t_base;
/*
** Controls functions.
*/
int				ft_controls(int key, t_base *base);
void			ft_colorize(t_base *base);
int				mouse_scroll(int button, int x, int y, t_base *base);
int				mouse_move(int x, int y, t_base *base);
int				close_window(void *param);
/*
** Fractal processing functions.
*/
void			fractol_select(t_type *fractal);
void			fractol_thread(t_base base);
void			*fractol_count(t_base *base);
void			fractol_initiation(t_base *base);
/*
** Fractal formulas functions.
*/
double			ft_mandelbrot(t_type *fractal);
double			ft_julia(t_type *fractal);
double			ft_ship(t_type *fractal);
double			ft_buffalo(t_type *fractal);
double			ft_tricorn(t_type *fractal);
double			ft_circle(t_type *fractal);
double			ft_chameleon(t_type *fractal);
double			ft_lilies(t_type *fractal);

#endif
