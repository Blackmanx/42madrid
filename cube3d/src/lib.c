/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:10:26 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/22 19:07:19 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	get_data_image(t_cube *cube)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (cube->wall[i].img)
			exit_program(cube, "Couldn't convert textures into wall", -9);
		else
			cube->wall[i].dir = (int *)mlx_get_data_addr(cube->wall[i].img,
					&cube->wall[i].bpp, &cube->wall[i].sz,
					&cube->wall[i].endian);
	}
	if (!cube->spr.img)
		exit_program(cube, "Coudln't convert textures into sprite", -10);
	else
		cube->spr.dir = (int *)mlx_get_data_addr(cube->spr.img, &cube->spr.bpp,
				&cube->spr.sz, &cube->spr.endian);
}

/*
** SOUTH = 0 NORTH = 1 WEST = 2 EAST = 3
*/
void	set_walls(t_cube *cube)
{
	cube->wall[0].img = mlx_xpm_file_to_image(cube->lib.mlx, cube->tex.s,
			&cube->wall[0].width, &cube->wall[0].height);
	cube->wall[1].img = mlx_xpm_file_to_image(cube->lib.mlx, cube->tex.n,
			&cube->wall[1].width, &cube->wall[1].height);
	cube->wall[2].img = mlx_xpm_file_to_image(cube->lib.mlx, cube->tex.e,
			&cube->wall[2].width, &cube->wall[2].height);
	cube->wall[3].img = mlx_xpm_file_to_image(cube->lib.mlx, cube->tex.w,
			&cube->wall[3].width, &cube->wall[3].height);
	cube->spr.img = mlx_xpm_file_to_image(cube->lib.mlx, cube->tex.spr,
			&cube->spr.width, &cube->spr.height);
	get_data_image(cube);
}

static void	set_window_size(t_cube *cube, int bg)
{
	if (cube->render.x > cube->win.width && bg)
		cube->win.width = cube->render.x;
	else if (cube->render.x <= cube->win.width)
		cube->win.width = cube->render.x;
	if (cube->render.y > cube->win.height && bg)
		cube->win.height = cube->render.y;
	else if (cube->render.y <= cube->win.height)
		cube->win.height = cube->render.y;
}

void	start_lib(t_cube *cube)
{
	cube->lib.mlx = mlx_init();
	if (!cube->lib.mlx)
		exit_program(cube, "Lib is not initialized", -11);
	set_walls(cube);
	mlx_get_screen_size(cube->lib.mlx, &cube->win.width, &cube->win.height);
	set_window_size(cube, cube->bg);
	if (!cube->bg)
	{
		cube->lib.mlx_win = mlx_new_window(cube->lib.mlx, cube->win.width,
				cube->win.height, "Cub3d");
		if (!cube->lib.mlx_win)
			exit_program(cube, "Couldn't open new window", -12);
	}
	cube->win.img = mlx_new_image(cube->lib.mlx,
			cube->win.width, cube->win.height);
	if (!cube->win.img)
		exit_program(cube, "Couldn't create image", -13);
	cube->win.dir = (int *)mlx_get_data_addr(cube->win.img, &cube->win.bpp,
			&cube->win.sz, &cube->win.endian);
	mlx_do_key_autorepeatoff(cube->lib.mlx);
}
