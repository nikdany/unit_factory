/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 19:18:33 by mdanylch          #+#    #+#             */
/*   Updated: 2019/08/07 19:31:49 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

/*
** Headers and libft.
*/
# include "libft/libft.h"
# include <SDL2/SDL.h>
# include "SDL2_image/SDL_image.h"
# include <math.h>
# include <time.h>

/*
** Definitions.
*/
# define WDTH				(1200)
# define HGHT				(800)
# define HALF_HGHT			(400)
# define WIND_POS			(300)
# define TXTR_SIZE			(64)
# define NAME				("wolf3d mdanylch")
# define W3D				base->wolf
# define TXTR				base->texture
# define ACTIV				base->sdl
# define WINDOW				base->sdl.window
# define EVENT				base->sdl.evnts
# define SURFACE			base->sdl.surface
# define BMP				base->sdl.bmp
# define PLYR				'P'
# define WALL				'1'
# define FREE				' '
# define MAP_NAME			"maps/w3d"
# define MAP_2				"maps/w3d_3"
# define MAP_3				"maps/w3d_2"
# define SKY_COLOR			0x2D13B5
# define FLOOR_COLOR		0x252626
# define ERR_USAGE			("Usage: ./wolf3d [maps/w3d.file].")
# define ERR_MALLOC			("Error: malloc problem")
# define ERR_SDL			("Error: SDL problem")
# define ERR_ARGV			("Error: wrong argument")
# define ERR_LENGTH			("Error: wrong lenght of map")
# define ERR_HEIGHT			("Error: wrong height of map")
# define ERR_WALL			("Error: walls are not correct")
# define ERR_FREE			("Error: there is no free place for a player")
# define ERR_SYMBOL			("Error: invalid symbol on the map")
# define ERR_NAME			("Error: invalid name of the map")
# define ERR_MAP	("Error: invalid map\n\tUsage: ./wolf3d [maps/w3d.file].")
# define TRUE				(1)
# define FALSE				(0)

/*
** SDL-window structure & keys status.
*/
typedef struct			s_sdl
{
	SDL_Window			*window;
	SDL_Surface			*surface;
	SDL_Surface			**bmp;
	SDL_Event			evnts;
	int					keydown_a;
	int					keydown_d;
	int					keydown_up;
	int					keydown_down;
	int					keydown_right;
	int					keydown_left;
}						t_sdl;

typedef struct			s_dvect
{
	double				x;
	double				y;
}						t_dvect;

typedef struct			s_ivect
{
	int					x;
	int					y;
}						t_ivect;

/*
** SDL-window structure & keys status.
*/
typedef struct			s_textture
{
	int					*data_img;
	int					*data;
	int					c;
	int					x_text;
	int					y_text;
	int					color;
	double				block;
	int					nbr;
}						t_texture;
/*
** Raycasting structure.
*/
typedef struct			s_raycast
{
	t_ivect				step;
	int					wall_side;
	int					ray;
	t_ivect				map;
	int					line_height;
	int					draw_start;
	int					draw_end;
	t_dvect				pos;
	t_dvect				dir;
	t_dvect				plane;
	t_dvect				old_dir;
	t_dvect				old_plane;
	t_dvect				camera;
	t_dvect				ray_dir;
	t_dvect				side_dist;
	t_dvect				delta_dist;
	double				perp_wdist;
	double				time;
	double				time_old;
	double				time_frame;
	double				mov_speed;
	double				rot_speed;
	t_ivect				size;
	char				**wmap;
	int					player;
}						t_raycast;
/*
** base structure.
*/
typedef struct			s_base
{
	int					fd;
	int					game_on;
	t_raycast			wolf;
	t_sdl				sdl;
	t_texture			texture;
}						t_base;
/*
** Wolf processing functions.
*/
void					ft_puterror(const char *msg, int ret);
void					wolf_validation(char *str, t_base *base, int i);
void					wolf_raycast(t_base *base);
void					wolf_event(t_base *base);

#endif
