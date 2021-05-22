/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:59:38 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/23 00:27:28 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	set_ray_dir(t_cube *cube, int x)
{
	cube->view.x = 2 * x / (double)cube->win.width - 1;
	cube->ray.dir_x = cube->mov.dir_x + cube->mov.plane_x * cube->view.x;
	cube->ray.dir_y = cube->mov.dir_y + cube->mov.plane_y * cube->view.x;
	cube->mov.map_x = (int)cube->mov.x;
	cube->mov.map_y = (int)cube->mov.y;
	cube->ray.delta_x = fabs(1 / cube->ray.dir_x);
	cube->ray.delta_y = fabs(1 / cube->ray.dir_y);
}

static void	set_ray_len(t_cube *cube)
{
	while (cube->ray.col == 0)
	{
		if (cube->ray.side_x < cube->ray.side_y)
		{
			cube->ray.side_x += cube->ray.delta_x;
			cube->mov.map_x += cube->ray.step_x;
			cube->ray.side = 0 + (cube->ray.dir_x < 0);
		}
		else
		{
			cube->ray.side_y += cube->ray.delta_y;
			cube->mov.map_y += cube->ray.step_y;
			cube->ray.side = 2 + (cube->ray.dir_y > 0);
		}
		if (cube->map[cube->mov.map_x][cube->mov.map_y] == WALL)
			cube->ray.col = 1;
	}
	if (cube->ray.side <= 1)
		cube->ray.len = (cube->mov.map_x - cube->mov.x
				+ (1 - cube->ray.step_x) / 2)
			/ cube->ray.dir_x;
	else
		cube->ray.len = (cube->mov.map_y
				- cube->mov.y + (1 - cube->ray.step_y) / 2)
			/ cube->ray.dir_y;
}

static void	draw_math(t_cube *cube)
{
	cube->ray.lh = (int)((double)cube->win.height / cube->ray.len);
	cube->draw.start = (-cube->ray.lh / 2) + (cube->win.height / 2);
	if (cube->draw.start < 0)
		cube->draw.start = 0;
	cube->draw.end = (cube->ray.lh / 2) + (cube->win.height / 2);
	if (cube->draw.end >= cube->win.height)
		cube->draw.end = cube->win.height - 1;
	if (cube->draw.end < 0)
		cube->draw.end = 0;
	if (cube->ray.side <= 1)
		cube->draw.x = cube->mov.y + cube->ray.len * cube->ray.dir_y;
	else
		cube->draw.x = cube->mov.x + cube->ray.len * cube->ray.dir_x;
	cube->draw.x -= floor(cube->draw.x);
	cube->ray.x = (int)(cube->draw.x * (double)
			(cube->wall[cube->ray.side].width));
	if ((cube->ray.side <= 1 && cube->ray.dir_x > 0) || (cube->ray.side >= 2
			&& cube->ray.dir_y > 0))
	{
		cube->ray.x = cube->wall[cube->ray.side].width - cube->ray.x - 1;
	}
}

static void	draw_textures(t_cube *cube, int x)
{
	int	i;
	int	color;

	i = cube->draw.start;
	cube->ray.step = 1.0 * cube->wall[cube->ray.side].height / cube->ray.lh;
	cube->ray.pos = (cube->draw.start - cube->win.height / 2 + cube->ray.lh / 2)
		* cube->ray.step;
	while (i < cube->draw.end)
	{
		cube->ray.y = (int)cube->ray.pos
			& (cube->wall[cube->ray.side].height - 1);
		cube->ray.pos += cube->ray.step;
		color = cube->wall[cube->ray.side].dir[cube->wall[cube->ray.side].width
			* cube->ray.y + cube->ray.x];
		if (cube->ray.side % 2)
			color = (color >> 1) & GREY;
		putpixel(cube, x, i, color);
		i++;
	}
	cube->spr.buf[x] = cube->ray.len;
}

int	raycasting(t_cube *cube, int x)
{
	set_raycast(cube);
	set_ray_dir(cube, x);
	set_step_side(cube);
	set_ray_len(cube);
	draw_math(cube);
	draw_textures(cube, x);
	return (1);
}
