/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 02:02:30 by mdanylch          #+#    #+#             */
/*   Updated: 2019/08/07 03:34:04 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/wolf3d.h"

static	void	wolf_rotate(t_base *base)
{
	t_dvect		shift;

	if (ACTIV.keydown_left || ACTIV.keydown_right)
	{
		shift = ACTIV.keydown_right == 1 ? \
		(t_dvect){.y = cos(W3D.rot_speed), .x = sin(W3D.rot_speed)} : \
		(t_dvect){.y = cos(-W3D.rot_speed), .x = sin(-W3D.rot_speed)};
		W3D.old_dir = (t_dvect) {.x = W3D.dir.x, .y = W3D.dir.y};
		W3D.old_plane = (t_dvect) {.x = W3D.plane.x, .y = W3D.plane.y};
		W3D.dir.x = W3D.old_dir.x * shift.y - W3D.old_dir.y * shift.x;
		W3D.dir.y = (W3D.old_dir.x * shift.x) + (W3D.old_dir.y * shift.y);
		W3D.plane.x = W3D.old_plane.x * shift.y - W3D.old_plane.y * shift.x;
		W3D.plane.y = W3D.old_plane.x * shift.x + W3D.old_plane.y * shift.y;
	}
}

static	void	wolf_move(t_base *base)
{
	t_dvect	shift;
	double	a;

	a = 3;
	shift = (t_dvect){.y = 0.04 * W3D.dir.y, .x = 0.04 * W3D.dir.x};
	if (ACTIV.keydown_down == 1)
	{
		if (W3D.wmap[(int)W3D.pos.y][(int)(W3D.pos.x - (shift.x * a))] != WALL)
			W3D.pos.x -= shift.x;
		if (W3D.wmap[(int)(W3D.pos.y - (shift.y * a))][(int)W3D.pos.x] != WALL)
			W3D.pos.y -= shift.y;
	}
	if (ACTIV.keydown_up == 1)
	{
		if (W3D.wmap[(int)W3D.pos.y][(int)(W3D.pos.x + (shift.x * a))] != WALL)
			W3D.pos.x += shift.x;
		if (W3D.wmap[(int)(W3D.pos.y + (shift.y * a))][(int)W3D.pos.x] != WALL)
			W3D.pos.y += shift.y;
	}
}

static	void	poll_event(t_base *base, int key, int flag)
{
	while (SDL_PollEvent(&EVENT))
	{
		key = EVENT.key.keysym.sym;
		if (EVENT.type == SDL_QUIT || \
			(EVENT.type == SDL_KEYDOWN && key == SDLK_ESCAPE))
			base->game_on = 0;
		if (EVENT.type == SDL_KEYDOWN || EVENT.type == SDL_KEYUP)
		{
			flag = (EVENT.type == SDL_KEYDOWN) ? 1 : 0;
			if (key == SDLK_UP)
				ACTIV.keydown_up = flag;
			if (key == SDLK_DOWN)
				ACTIV.keydown_down = flag;
			if (key == SDLK_LEFT)
				ACTIV.keydown_left = flag;
			if (key == SDLK_RIGHT)
				ACTIV.keydown_right = flag;
			if (EVENT.type == SDL_KEYDOWN && key == SDLK_SPACE)
				TXTR.nbr = TXTR.nbr > 7 ? 0 : TXTR.nbr + 4;
		}
	}
	if (ACTIV.keydown_right || ACTIV.keydown_left)
		wolf_rotate(base);
	if (ACTIV.keydown_up || ACTIV.keydown_down)
		wolf_move(base);
}

void			wolf_event(t_base *base)
{
	int	i;

	while (base->game_on)
	{
		W3D.time_old = W3D.time;
		W3D.time = SDL_GetTicks();
		W3D.time_frame = (W3D.time - W3D.time_old) / 1000.0;
		W3D.mov_speed = W3D.time_frame * 5.0;
		W3D.rot_speed = W3D.time_frame * 3.0;
		poll_event(base, 0, 0);
		wolf_raycast(base);
	}
	i = -1;
	while (++i < 8)
		SDL_FreeSurface(BMP[i]);
	SDL_FreeSurface(SURFACE);
	SDL_DestroyWindow(WINDOW);
	SDL_Quit();
}
