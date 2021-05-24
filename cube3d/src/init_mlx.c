/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:58:17 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 20:58:19 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_sprites(t_cube *c)
{
	c->spr.img = NULL;
	c->spr.data = NULL;
	c->spr.w = 0;
	c->spr.h = 0;
	c->spr.bpp = 0;
	c->spr.sz = 0;
	c->spr.endian = 0;
	c->spr.pos_x = 0.0;
	c->spr.pos_y = 0.0;
	c->spr.start_x = 0;
	c->spr.start_y = 0;
	c->spr.end_x = 0;
	c->spr.end_y = 0;
	c->spr.h2 = 0;
	c->spr.w2 = 0;
	c->spr.screen = 0;
	c->spr.col = 0;
	c->spr.buf = NULL;
}

static void	check_xpm(t_cube *c)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		if (!c->wall[x].img)
			exit_program(c, "Fail to convert the texture of a wall\n", 1);
		else
			c->wall[x].data = (int *)mlx_get_data_addr(c->wall[x].img,
					&c->wall[x].bpp, &c->wall[x].sz, &c->wall[x].endian);
		x++;
	}
	if (!c->spr.img)
		exit_program(c, "Fail to convert the texture of the sprite\n", 1);
	else
		c->spr.data = (int *)mlx_get_data_addr(c->spr.img, &c->spr.bpp,
				&c->spr.sz, &c->spr.endian);
}

void	handle_img(t_cube *c)
{
	c->wall[N].img = mlx_xpm_file_to_image(c->lib.mlx, c->tex.n,
			&c->wall[N].w, &c->wall[N].h);
	c->wall[S].img = mlx_xpm_file_to_image(c->lib.mlx, c->tex.s,
			&c->wall[S].w, &c->wall[S].h);
	c->wall[E].img = mlx_xpm_file_to_image(c->lib.mlx, c->tex.e,
			&c->wall[E].w, &c->wall[E].h);
	c->wall[W].img = mlx_xpm_file_to_image(c->lib.mlx, c->tex.w,
			&c->wall[W].w, &c->wall[W].h);
	c->spr.img = mlx_xpm_file_to_image(c->lib.mlx, c->tex.spr,
			&c->spr.w, &c->spr.h);
	check_xpm(c);
}

static void	resize_window(t_cube *c, int bmp)
{
	if (c->render.x > c->win.w && bmp)
		c->win.w = c->render.x;
	else if (c->render.x <= c->win.w)
		c->win.w = c->render.x;
	if (c->render.y > c->win.h && bmp)
		c->win.h = c->render.y;
	else if (c->render.y <= c->win.h)
		c->win.h = c->render.y;
}

void	lib_start(t_cube *c)
{
	c->lib.mlx = mlx_init();
	if (!c->lib.mlx)
		exit_program(c, "MLX was not initialized\n", 1);
	handle_img(c);
	mlx_get_screen_size(c->lib.mlx, &c->win.w, &c->win.h);
	resize_window(c, c->dt);
	if (!c->dt)
	{
		c->lib.mlx_win = mlx_new_window(c->lib.mlx, c->win.w,
				c->win.h, "Cub3D");
		if (!c->lib.mlx_win)
			exit_program(c, "When opening a new window\n", 1);
	}
	c->win.img = mlx_new_image(c->lib.mlx, c->win.w, c->win.h);
	if (!c->win.img)
		exit_program(c, "When creating a new image\n", 1);
	c->win.data = (int *)mlx_get_data_addr(c->win.img, &c->win.bpp, &c->win.sz,
			&c->win.endian);
	mlx_do_key_autorepeatoff(c->lib.mlx);
}
