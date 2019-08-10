/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:41:36 by mdanylch          #+#    #+#             */
/*   Updated: 2019/07/18 06:40:42 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int		fractol_usage(void)
{
	ft_putstr("\nUsage: \t\tfractol [Int] - 1 to 8\n");
	ft_putstr("Example: ./fractol 1 or ./fractol 1 2 3 4 5 6 7 8\n\n");
	ft_putstr("[ 1 - mandelbrot | 2 - julia | 3 - circle ] - MANDATORY PART\n");
	ft_putstr("[ 4 - ship | 5 - chameleon | 6 - buffalo | 7 - tricorn |");
	ft_putstr(" 8 - lilies] - BONUS\n");
	ft_putstr("\t ***   All arguments must be correct!   ***\n\n");
	return (0);
}

void	fractol_initiation(t_base *base)
{
	if (B->init == 0)
	{
		B->thread = THREADS;
		B->init = 1;
		B->win->ptr = mlx_init();
		B->win->win = mlx_new_window(B->win->ptr, RESOLUTION, RESOLUTION, NAME);
		B->win->img = mlx_new_image(B->win->ptr, RESOLUTION, RESOLUTION);
		B->win->addr = mlx_get_data_addr(B->win->img, &B->win->bit, \
						&B->win->line_s, &B->win->endia);
	}
	B->F.min_re = -2.15;
	B->F.max_re = 1;
	B->F.min_im = -1.3;
	B->F.max_im = B->F.min_im + (B->F.max_re - B->F.min_re);
	B->F.iteration = 20;
	B->F.mouse_im = 0;
	B->F.mouse_re = 0;
	B->F.color = 004001006;
	B->F.re_fa = (B->F.max_re - B->F.min_re) / (RESOLUTION - 1);
	B->F.in_fa = (B->F.max_im - B->F.min_im) / (RESOLUTION - 1);
	B->win->lock_key = 0;
	B->win->first = 0;
}

int		fractol_validation(int argc, char **argv)
{
	int		i;
	int		nb;
	char	*msg;

	i = 0;
	if (argc < 2)
		return (0);
	while (++i < argc)
	{
		nb = ft_atoi(&argv[i][0]);
		if (!(nb >= 1 && nb <= 8 && argv[i][1] == '\0'))
			return (0);
	}
	msg = malloc(13);
	ft_strcpy(msg, "./fractol 0&");
	i = 1;
	while (++i < argc)
	{
		msg[10] = *argv[i];
		system(msg);
	}
	free(msg);
	return (1);
}

int		main(int argc, char **argv)
{
	t_base	*base;

	if (!fractol_validation(argc, argv))
		return (fractol_usage());
	if (!(base = (t_base*)malloc(sizeof(t_base))))
		return (0);
	if (!(B->win = (t_win*)malloc(sizeof(t_win))))
		return (0);
	B->init = 0;
	fractol_initiation(base);
	base->fractal.num = ft_atoi(argv[1]);
	fractol_select(&base->fractal);
	fractol_thread(*base);
	mlx_hook(base->win->win, 2, 5, ft_controls, base);
	mlx_hook(base->win->win, 4, 5, mouse_scroll, base);
	mlx_hook(base->win->win, 17, 5, close_window, NULL);
	if (base->fractal.num == 2)
		mlx_hook(base->win->win, 6, 5, mouse_move, base);
	mlx_loop(base->win->ptr);
	return (0);
}
