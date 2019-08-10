/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:00:54 by mdanylch          #+#    #+#             */
/*   Updated: 2019/08/10 15:40:51 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/wolf3d.h"

static	void	load_textures(t_base *base, int i)
{
	BMP[0] = IMG_Load("./img/1.png");
	BMP[1] = IMG_Load("./img/2.png");
	BMP[2] = IMG_Load("./img/3.png");
	BMP[3] = IMG_Load("./img/4.png");
	BMP[4] = IMG_Load("./img/1.bmp");
	BMP[5] = IMG_Load("./img/2.bmp");
	BMP[6] = IMG_Load("./img/3.bmp");
	BMP[7] = IMG_Load("./img/4.bmp");
	BMP[8] = IMG_Load("./img/5.png");
	BMP[9] = IMG_Load("./img/6.png");
	BMP[10] = IMG_Load("./img/7.png");
	BMP[11] = IMG_Load("./img/8.png");
	while (++i < 12)
		if (!(BMP[i]))
			ft_puterror("Error: problems with textures", base->fd);
}

static	void	base_initiation(t_base *base, char *str)
{
	W3D.dir.x = -1;
	W3D.plane.y = 0.60;
	base->game_on = 1;
	if (strcmp(str, MAP_2) == 0)
		TXTR.nbr = 4;
	if (strcmp(str, MAP_3) == 0)
		TXTR.nbr = 8;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ft_puterror(ERR_SDL, base->fd);
	WINDOW = SDL_CreateWindow(NAME, 150, 150, WDTH, HGHT, \
			SDL_WINDOW_ALLOW_HIGHDPI);
	if (!WINDOW)
		ft_puterror(ERR_SDL, base->fd);
	SURFACE = SDL_GetWindowSurface(WINDOW);
	if (!SURFACE)
		ft_puterror(ERR_SDL, base->fd);
	BMP = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 12);
	if (!BMP)
		ft_puterror(ERR_MALLOC, base->fd);
	load_textures(base, -1);
}

int				main(int argc, char **argv)
{
	t_base	*base;

	if (argc != 2)
		ft_puterror(ERR_USAGE, -1);
	if (ft_strncmp(argv[1], MAP_NAME, 7) != 0)
		ft_puterror(ERR_NAME, -1);
	base = (t_base *)malloc(sizeof(t_base));
	if (!base)
		ft_puterror(ERR_MALLOC, -42);
	ft_bzero(base, sizeof(t_base));
	wolf_validation(argv[1], base, -1);
	base_initiation(base, argv[1]);
	wolf_raycast(base);
	wolf_event(base);
	return (0);
}
