/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:58:42 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 20:58:44 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ray_pos_dir(t_cube *c, int x)
{
	c->view.x = 2 * x / (double)c->win.w - 1;
	c->ray.dir_x = c->mov.dir_x + c->mov.plane_x * c->view.x;
	c->ray.dir_y = c->mov.dir_y + c->mov.plane_y * c->view.x;
	c->mov.map_x = (int)c->mov.pos_x;
	c->mov.map_y = (int)c->mov.pos_y;
	c->ray.delta_x = fabs(1 / c->ray.dir_x);
	c->ray.delta_y = fabs(1 / c->ray.dir_y);
}

static void	dda(t_cube *c)
{
	while (c->ray.roblox == 0)
	{
		if (c->ray.side_x < c->ray.side_y)
		{
			c->ray.side_x += c->ray.delta_x;
			c->mov.map_x += c->ray.step_x;
			c->ray.side = 0 + (c->ray.dir_x < 0);
		}
		else
		{
			c->ray.side_y += c->ray.delta_y;
			c->mov.map_y += c->ray.step_y;
			c->ray.side = 2 + (c->ray.dir_y > 0);
		}
		if (c->map[c->mov.map_x][c->mov.map_y] == WALL)
			c->ray.roblox = 1;
	}
	if (c->ray.side <= 1)
		c->ray.perp = (c->mov.map_x - c->mov.pos_x + (1 - c->ray.step_x) / 2)
			/ c->ray.dir_x;
	else
		c->ray.perp = (c->mov.map_y - c->mov.pos_y + (1 - c->ray.step_y) / 2)
			/ c->ray.dir_y;
}

static void	draw_calculus(t_cube *c)
{
	c->ray.lh = (int)((double)c->win.h / c->ray.perp);
	c->draw.start = (-c->ray.lh / 2) + (c->win.h / 2);
	if (c->draw.start < 0)
		c->draw.start = 0;
	c->draw.end = (c->ray.lh / 2) + (c->win.h / 2);
	if (c->draw.end >= c->win.h)
		c->draw.end = c->win.h - 1;
	if (c->draw.end < 0)
		c->draw.end = 0;
	if (c->ray.side <= 1)
		c->draw.x = c->mov.pos_y + c->ray.perp * c->ray.dir_y;
	else
		c->draw.x = c->mov.pos_x + c->ray.perp * c->ray.dir_x;
	c->draw.x -= floor(c->draw.x);
	c->ray.x = (int)(c->draw.x * (double)(c->wall[c->ray.side].w));
	if ((c->ray.side <= 1 && c->ray.dir_x > 0) || (c->ray.side >= 2
			&& c->ray.dir_y > 0))
	{
		c->ray.x = c->wall[c->ray.side].w - c->ray.x - 1;
	}
}

static void	draw_textures(t_cube *c, int x)
{
	int	i;
	int	col;

	i = c->draw.start;
	c->ray.step = 1.0 * c->wall[c->ray.side].h / c->ray.lh;
	c->ray.pos = (c->draw.start - c->win.h / 2 + c->ray.lh / 2)
		* c->ray.step;
	while (i < c->draw.end)
	{
		c->ray.y = (int)c->ray.pos & (c->wall[c->ray.side].h - 1);
		c->ray.pos += c->ray.step;
		col = c->wall[c->ray.side].data[c->wall[c->ray.side].w
			* c->ray.y + c->ray.x];
		if (c->ray.side % 2)
			col = (col >> 1) & GRAY
;
		my_mlx_pixel_put(c, x, i, col);
		i++;
	}
	c->spr.buf[x] = c->ray.perp;
}

int	raycaster(t_cube *c, int x)
{
	set_raycast(c);
	ray_pos_dir(c, x);
	step_initial_side(c);
	dda(c);
	draw_calculus(c);
	draw_textures(c, x);
	return (1);
}
