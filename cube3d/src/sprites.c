/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:01:33 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 21:01:34 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	sort_spr(t_cube *c)
{
	int			s;
	int			z;
	int			total;
	t_spr_p	tmp;

	total = get_spr_n(c);
	s = -1;
	while (++s < total)
	{
		z = -1;
		while (++z < total)
		{
			if (c->spr_p[s].dist > c->spr_p[z].dist)
			{
				tmp = c->spr_p[s];
				c->spr_p[s] = c->spr_p[z];
				c->spr_p[z] = tmp;
			}
		}
	}
}

void	find_spr(t_cube *c)
{
	int	x;
	int	y;
	int	s;

	c->spr_p = malloc(sizeof(t_spr) * (get_spr_n(c)));
	s = 0;
	x = -1;
	while (c->map[++x])
	{
		y = -1;
		while (c->map[x][++y])
		{
			if (c->map[x][y] == OBJECT)
			{
				c->spr_p[s].x = x + 0.5;
				c->spr_p[s].y = y + 0.5;
				c->spr_p[s].dist = ((c->mov.pos_x - c->spr_p[s].x)
						* (c->mov.pos_x - c->spr_p[s].x) + (c->mov.pos_y
							- c->spr_p[s].y) * (c->mov.pos_y
							- c->spr_p[s].y));
				s++;
			}
		}
	}
}

static void	sp_draw(t_cube *c)
{
	c->spr.start_y = -c->spr.h2 / 2 + c->win.h / 2;
	if (c->spr.start_y < 0)
		c->spr.start_y = 0;
	c->spr.end_y = c->spr.h2 / 2 + c->win.h / 2;
	if (c->spr.end_y >= c->win.h)
		c->spr.end_y = c->win.h - 1;
	c->spr.start_x = -c->spr.w2 / 2 + c->spr.screen;
	if (c->spr.start_x < 0)
		c->spr.start_x = 0;
	c->spr.end_x = c->spr.w2 / 2 + c->spr.screen;
	if (c->spr.end_x >= c->win.w)
		c->spr.end_x = c->win.w - 1;
}

static void	sprite_loop(t_cube *c, double ty)
{
	int	x;
	int	y;
	int	texx;
	int	texy;
	int	d;

	x = c->spr.start_x - 1;
	while (++x < c->spr.end_x)
	{
		texx = (int)(BYTE * (x - (-c->spr.w2 / 2 + c->spr.screen))
				* c->spr.w / c->spr.w2) / BYTE;
		if (ty >= 0 && x >= 0 && x <= c->win.w && ty < c->spr.buf[x])
		{
			y = c->spr.start_y - 1;
			while (++y < c->spr.end_y)
			{
				d = y * BYTE - c->win.h * (BYTE / 2) + c->spr.h2 * (BYTE / 2);
				texy = abs(((d * c->spr.h) / c->spr.h2) / BYTE);
				c->spr.col = c->spr.data[c->spr.w * texy + texx];
				if ((c->spr.col & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(c, x, y, c->spr.col);
			}
		}
	}
}

void	spr_window(t_cube *c)
{
	double	idet;
	double	tx;
	double	ty;
	int		s;
	int		total;

	total = get_spr_n(c);
	s = -1;
	free(c->spr_p);
	find_spr(c);
	sort_spr(c);
	while (++s < total)
	{
		c->spr.pos_x = (double)c->spr_p[s].x - c->mov.pos_x;
		c->spr.pos_y = (double)c->spr_p[s].y - c->mov.pos_y;
		idet = 1.0 / (c->mov.plane_x * c->mov.dir_y - c->mov.dir_x
				* c->mov.plane_y);
		tx = idet * (c->mov.dir_y * c->spr.pos_x - c->mov.dir_x * c->spr.pos_y);
		ty = idet * (-c->mov.plane_y * c->spr.pos_x + c->mov.plane_x * c->spr.pos_y);
		c->spr.screen = (int)((c->win.w / 2) * (1 + tx / ty));
		c->spr.h2 = abs((int)(c->win.h / ty));
		c->spr.w2 = abs((int)(c->win.h / ty));
		sp_draw(c);
		sprite_loop(c, ty);
	}
}
