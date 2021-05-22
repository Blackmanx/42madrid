/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:30:22 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/23 00:51:07 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	putpixel(t_cube *cube, int x, int y, int color)
{
	cube->win.dir[x + cube->win.width * y] = color;
}

static int	rgbtoi(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	draw_floor_sky(t_cube *cube)
{
	int	x;
	int	y;
	int	sky_rgb;
	int	floor_rgb;

	sky_rgb = rgbtoi(cube->colors.rgb_s[0],
			cube->colors.rgb_s[1], cube->colors.rgb_s[2]);
	floor_rgb = rgbtoi(cube->colors.rgb_f[0],
			cube->colors.rgb_f[1], cube->colors.rgb_f[2]);
	y = -1;
	while (++y < cube->win.height)
	{
		x = -1;
		while (++x < cube->win.width)
		{
			if (y < cube->win.height / 2)
				putpixel(cube, x, y, sky_rgb);
			else
				putpixel(cube, x, y, floor_rgb);
		}
	}
}

int	img_draw(t_cube *cube)
{
	int	x;

	cube->spr.buf = malloc(sizeof(double) * cube->win.width);
	if (cube->draw.draw)
	{
		x = -1;
		draw_floor_sky(cube);
		while (++x < cube->win.width)
			raycasting(cube, x);
		draw_win_spr(cube);
	}
	if (!cube->bg)
	{
		mlx_put_image_to_window(cube->lib.mlx, cube->lib.mlx_win,
			cube->win.img, 0, 0);
		cube->draw.draw = move(cube, SQUARE_RAD);
		cube->draw.draw |= rotate(cube, RAD);
	}
	free(cube->spr.buf);
	return (1);
}
