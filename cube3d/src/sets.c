/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 21:01:37 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/22 21:09:40 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	set_file(t_cube *cube)
{
	cube->render.x = 0;
	cube->render.y = 0;
	cube->tex.n = NULL;
	cube->tex.s = NULL;
	cube->tex.e = NULL;
	cube->tex.w = NULL;
	cube->tex.spr = NULL;
	cube->map = NULL;
	cube->l = NULL;
	cube->spr_pos = NULL;
	cube->bg = NULL;
	cube->read.b = NULL;
	cube->read.l = NULL;
	cube->read.stc = NULL;
	ft_bzero(cube->colors.rgb_s, 3);
	ft_bzero(cube->colors.rgb_f, 3);
}

static void	set_mov(t_cube *cube)
{
	cube->mov.left = 0;
	cube->mov.right = 0;
	cube->mov.up = 0;
	cube->mov.down = 0;
	cube->mov.map_x = 0;
	cube->mov.map_y = 0;
	cube->mov.x = 0.0;
	cube->mov.y = 0.0;
	cube->mov.plane_x = 0.0;
	cube->mov.plane_y = 0.0;
	cube->mov.dir_x = 0.0;
	cube->mov.dir_y = 0.0;
	cube->view.x = 0.0;
	cube->view.left = 0;
	cube->view.right = 0;
}

void	set_raycast(t_cube *cube)
{
	cube->ray.x = 0;
	cube->ray.y = 0;
	cube->ray.pos = 0.0;
	cube->ray.dir_x = 0.0;
	cube->ray.dir_y = 0.0;
	cube->ray.side_x = 0.0;
	cube->ray.side_y = 0.0;
	cube->ray.delta_x = 0.0;
	cube->ray.delta_y = 0.0;
	cube->ray.len = 0.0;
	cube->ray.step = 0.0;
	cube->ray.step_x = 0;
	cube->ray.step_y = 0;
	cube->ray.col = 0;
	cube->ray.side = 0;
	cube->ray.lh = 0;
	cube->ray.tex = 0;
	cube->draw.x = 0;
	cube->draw.y = 0;
	cube->draw.start = 0;
	cube->draw.end = 0;
	cube->mov.map_x = 0;
	cube->mov.map_y = 0;
	cube->view.x = 0.0;
}

static void	set_textures(t_cube *cube)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		cube->wall[i].img = NULL;
		cube->wall[i].dir = NULL;
		cube->wall[i].width = 0;
		cube->wall[i].height = 0;
		cube->wall[i].sz = 0;
		cube->wall[i].endian = 0;
		cube->wall[i].bpp = 0;
		i++;
	}
	set_sp(cube);
}

void	set_struct(t_cube *cube)
{
	set_file(cube);
	set_mov(cube);
	set_raycast(cube);
	set_textures(cube);
	set_sprites(cube);
	cube->rows = 0;
	cube->draw.draw = 1;
	cube->lib.mlx = NULL;
	cube->lib.mlx_win = NULL;
	cube->win.img = NULL;
	cube->flag.tex_n = 0;
	cube->flag.tex_e = 0;
	cube->flag.tex_s = 0;
	cube->flag.tex_w = 0;
	cube->flag.tex_spr = 0;
	cube->flag.floor = 0;
	cube->flag.roof = 0;
	cube->flag.res = 0;
	cube->flag.map = 0;
	cube->flag.player = 0;
}
