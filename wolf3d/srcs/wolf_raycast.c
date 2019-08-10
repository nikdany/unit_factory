/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanylch <mdanylch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 06:46:11 by mdanylch          #+#    #+#             */
/*   Updated: 2019/08/07 03:21:35 by mdanylch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/wolf3d.h"

static	void	ray_drow_texture(t_base *base)
{
	int y;

	y = -1;
	while (++y < W3D.draw_start)
		TXTR.data[(y * WDTH) + W3D.ray] = SKY_COLOR;
	y = W3D.draw_start;
	while (y < W3D.draw_end)
	{
		TXTR.c = y * 256 - HGHT * 128 + W3D.line_height * 128;
		TXTR.y_text = ((TXTR.c * TXTR_SIZE) / W3D.line_height) / 256;
		TXTR.color = TXTR.data_img[TXTR_SIZE * TXTR.y_text + TXTR.x_text];
		TXTR.data[y * WDTH + W3D.ray] = TXTR.color;
		y++;
	}
	y--;
	while (++y < HGHT)
		TXTR.data[(y * WDTH) + W3D.ray] = FLOOR_COLOR;
}

static	void	ray_calc_texture(t_base *base)
{
	W3D.line_height = (int)(HGHT / W3D.perp_wdist);
	W3D.draw_start = (-W3D.line_height >> 1u) + (HALF_HGHT);
	if (W3D.draw_start < 0)
		W3D.draw_start = 0;
	W3D.draw_end = (W3D.line_height >> 1u) + (HALF_HGHT);
	if (W3D.draw_end >= HGHT)
		W3D.draw_end = HGHT - 1;
	if (!W3D.wall_side)
		TXTR.block = W3D.pos.y + W3D.perp_wdist * W3D.ray_dir.y;
	else
		TXTR.block = W3D.pos.x + W3D.perp_wdist * W3D.ray_dir.x;
	TXTR.block -= (int)(TXTR.block);
	TXTR.data = SURFACE->pixels;
	TXTR.x_text = (int)(TXTR.block * (double)TXTR_SIZE);
	TXTR.data_img = BMP[0 + TXTR.nbr]->pixels;
	if (((W3D.ray_dir.x < 0 && W3D.ray_dir.y < 0) || (W3D.ray_dir.x >= 0 \
			&& W3D.ray_dir.y < 0)) && (W3D.wall_side == 1))
		TXTR.data_img = BMP[1 + TXTR.nbr]->pixels;
	if (((W3D.ray_dir.x < 0 && W3D.ray_dir.y >= 0) || (W3D.ray_dir.x >= 0 \
			&& W3D.ray_dir.y >= 0)) && (W3D.wall_side == 1))
		TXTR.data_img = BMP[2 + TXTR.nbr]->pixels;
	if (((W3D.ray_dir.x >= 0 && W3D.ray_dir.y < 0) || (W3D.ray_dir.x >= 0 \
			&& W3D.ray_dir.y >= 0)) && (W3D.wall_side == 0))
		TXTR.data_img = BMP[3 + TXTR.nbr]->pixels;
}

static	void	ray_count_side(t_base *base)
{
	W3D.map.x = (int)W3D.pos.x;
	W3D.map.y = (int)W3D.pos.y;
	if (W3D.ray_dir.x < 0)
	{
		W3D.step.x = -1;
		W3D.side_dist.x = (W3D.pos.x - W3D.map.x) * W3D.delta_dist.x;
	}
	else
	{
		W3D.step.x = 1;
		W3D.side_dist.x = (W3D.map.x + 1.0 - W3D.pos.x) * W3D.delta_dist.x;
	}
	if (W3D.ray_dir.y < 0)
	{
		W3D.step.y = -1;
		W3D.side_dist.y = (W3D.pos.y - W3D.map.y) * W3D.delta_dist.y;
	}
	else
	{
		W3D.step.y = 1;
		W3D.side_dist.y = (W3D.map.y + 1.0 - W3D.pos.y) * W3D.delta_dist.y;
	}
}

static	void	ray_count_len(t_base *base, int hit)
{
	while (hit == 0)
	{
		if (W3D.side_dist.x < W3D.side_dist.y)
		{
			W3D.side_dist.x += W3D.delta_dist.x;
			W3D.map.x += W3D.step.x;
			W3D.wall_side = 0;
		}
		else
		{
			W3D.side_dist.y += W3D.delta_dist.y;
			W3D.map.y += W3D.step.y;
			W3D.wall_side = 1;
		}
		if (W3D.wmap[W3D.map.y][W3D.map.x] == WALL)
			hit = 1;
	}
	if (!W3D.wall_side)
		W3D.perp_wdist = \
		(W3D.map.x - W3D.pos.x + (1.0f - W3D.step.x) / 2) / W3D.ray_dir.x;
	else
		W3D.perp_wdist = \
		(W3D.map.y - W3D.pos.y + (1.0f - W3D.step.y) / 2) / W3D.ray_dir.y;
}

void			wolf_raycast(t_base *base)
{
	W3D.ray = 0;
	while (W3D.ray < WDTH)
	{
		W3D.camera.x = 1 - (2.0 * (double)W3D.ray / WDTH);
		W3D.ray_dir.x = W3D.dir.x + W3D.plane.x * W3D.camera.x;
		W3D.ray_dir.y = W3D.dir.y + W3D.plane.y * W3D.camera.x;
		W3D.delta_dist.x = fabs(1 / W3D.ray_dir.x);
		W3D.delta_dist.y = fabs(1 / W3D.ray_dir.y);
		ray_count_side(base);
		ray_count_len(base, 0);
		ray_calc_texture(base);
		ray_drow_texture(base);
		W3D.ray++;
	}
	if (SDL_UpdateWindowSurface(WINDOW) != 0)
		ft_puterror(ERR_SDL, -42);
}
