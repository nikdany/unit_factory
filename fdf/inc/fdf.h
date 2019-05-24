/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 02:02:00 by mdanylch          #+#    #+#             */
/*   Updated: 2019/05/01 03:36:42 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "./libft/libft.h"

# define INT2(a,b) int a,b;
# define INT3(a,b,c) int a,b,c;
# define INT8(a,b,c,d,e,f,g,h) int a,b,c,d,e,f,g,h;
# define INI2(a,av,b,bv) a=av;b=bv;
# define INI3(a,av,b,bv,c,cv) a=av;b=bv;c=cv;

typedef	struct	s_fdf
{
	int		l;
	int		c;
	int		**altitude;
	void	*mlx;
	void	*win;
	int		go;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	int		x_in;
	int		y_in;
	int		*all_x;
	int		*all_y;
	int		iso;
	int		z;
}				t_fdf;

void			ft_render(t_fdf *base);
int				ft_key_in(int key, t_fdf *base);
int				ft_close(void *param);

#endif
