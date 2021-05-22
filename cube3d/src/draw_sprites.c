/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 00:37:27 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/23 01:00:45 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	sort_spr(t_cube *cube)
{
	int			i;
	int			z;
	int			n_spr;
	t_sprpos	aux;

	n_spr = get_spr(cube);
	i = -1;
	while (++i < n_spr)
	{
		z = -1;
		while (++z < n_spr)
		{
			if (cube->spr_pos[i].len > cube->spr_pos[z].len)
			{
				aux = cube->spr_pos[i];
				cube->spr_pos[i] = cube->spr_pos[z];
				cube->spr_pos[z] = aux;
			}
		}
	}
}

static void	aux_dws(t_cube *cube, double tx, double ty, double idet)
{
	cube->spr.screen = (int)((cube->win.width / 2) * (1 + tx / ty));
	cube->spr.h = abs((int)(cube->win.height / ty));
	cube->spr.w = abs((int)(cube->win.height / ty));
}

static void	spr_draw(t_cube *cube)
{
	cube->spr.beg_y = -cube->spr.h / 2 + cube->win.height / 2;
	if (cube->spr.beg_y < 0)
		cube->spr.beg_y = 0;
	cube->spr.end_y = cube->spr.h / 2 + cube->win.height / 2;
	if (cube->spr.end_y >= cube->win.height)
		cube->spr.end_y = cube->win.height - 1;
	cube->spr.beg_x = -cube->spr.w / 2 + cube->spr.screen;
	if (cube->spr.beg_x < 0)
		cube->spr.beg_x = 0;
	cube->spr.end_x = cube->spr.w / 2 + cube->spr.screen;
	if (cube->spr.end_x >= cube->win.width)
		cube->spr.end_x = cube->win.width - 1;
}

static void	sprite_loop(t_cube *cube, double ty)
{
	int	x;
	int	y;
	int	tex_x;
	int	tex_y;
	int	d;

	x = cube->spr.beg_x - 1;
	while (++x < cube->spr.end_x)
	{
		tex_x = (int)(BYTE * (x - (-cube->spr.w / 2 + cube->spr.screen))
				* cube->spr.width / cube->spr.w) / BYTE;
		if (ty >= 0 && x >= 0 && x <= cube->win.width && ty < cube->spr.buf[x])
		{
			y = cube->spr.beg_y - 1;
			while (++y < cube->spr.end_y)
			{
				d = y * BYTE - cube->win.height
					* (BYTE / 2) + cube->spr.h * (BYTE / 2);
				tex_y = abs(((d * cube->spr.height) / cube->spr.h) / BYTE);
				cube->spr.rgb = cube->spr.dir[cube->spr.width * tex_y + tex_x];
				if ((cube->spr.rgb & 0x00FFFFFF) != 0)
					putpixel(cube, x, y, cube->spr.rgb);
			}
		}
	}
}

void	draw_win_spr(t_cube *cube)
{
	double	idet;
	double	tx;
	double	ty;
	int		i;
	int		n_spr;

	n_spr = get_spr(cube);
	i = -1;
	free(cube->spr_pos);
	search_sprites(cube);
	sort_spr(cube);
	while (++i < n_spr)
	{
		cube->spr.x = (double)cube->spr_pos[i].x - cube->mov.x;
		cube->spr.y = (double)cube->spr_pos[i].y - cube->mov.y;
		idet = 1.0 / (cube->mov.plane_x * cube->mov.dir_y - cube->mov.dir_x
				* cube->mov.plane_y);
		tx = idet * (cube->mov.dir_y * cube->spr.x
				- cube->mov.dir_x * cube->spr.y);
		ty = idet * (-cube->mov.plane_y * cube->spr.x
				+ cube->mov.plane_x * cube->spr.y);
		aux_dws(cube, tx, ty, idet);
		spr_draw(cube);
		sprite_loop(cube, ty);
	}
}
