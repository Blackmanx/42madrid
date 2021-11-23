/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:02:53 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 21:02:54 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	rgb2int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	my_mlx_pixel_put(t_cube *c, int x, int y, int col)
{
	c->win.data[c->win.w * y + x] = col;
}

void	free_map(t_cube *c)
{
	int	i;

	i = c->nrows;
	if (c->map)
	{
		while (i >= 0)
		{
			free(c->map[i]);
			c->map[i] = NULL;
			i--;
		}
		free(c->map);
		c->map = NULL;
	}
}

void	paint_sky_floor(t_cube *c)
{
	int	x;
	int	y;
	int	sky_color;
	int	floor_color;

	sky_color = rgb2int(c->col.rgb_s[0], c->col.rgb_s[1], c->col.rgb_s[2]);
	floor_color = rgb2int(c->col.rgb_f[0], c->col.rgb_f[1], c->col.rgb_f[2]);
	y = -1;
	while (++y < c->win.h)
	{
		x = -1;
		while (++x < c->win.w)
		{
			if (y < c->win.h / 2)
				my_mlx_pixel_put(c, x, y, sky_color);
			else
				my_mlx_pixel_put(c, x, y, floor_color);
		}
	}
}

int	set_window(t_cube *c)
{
	int	x;

	c->spr.buf = malloc(sizeof(double) * c->win.w);
	if (c->draw.trig)
	{
		x = -1;
		paint_sky_floor(c);
		while (++x < c->win.w)
			raycaster(c, x);
		spr_window(c);
	}
	if (!c->dt)
	{
		mlx_put_image_to_window(c->lib.mlx, c->lib.mlx_win, c->win.img, 0, 0);
		c->draw.trig = move(c, P_SPEED);
		c->draw.trig |= rotate(c, P_SUM_SP);
	}
	free(c->spr.buf);
	return (1);
}
