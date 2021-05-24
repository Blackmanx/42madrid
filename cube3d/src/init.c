/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:58:24 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 20:58:25 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	init_file_vble(t_cube *cube)
{
	cube->render.x = 0;
	cube->render.y = 0;
	cube->tex.n = NULL;
	cube->tex.s = NULL;
	cube->tex.w = NULL;
	cube->tex.e = NULL;
	cube->tex.spr = NULL;
	ft_bzero(cube->col.rgb_s, 3);
	ft_bzero(cube->col.rgb_f, 3);
	cube->line = NULL;
	cube->map = NULL;
	cube->spr_p = NULL;
	cube->dt = 0;
	cube->r.b = NULL;
	cube->r.l = NULL;
	cube->r.stc = NULL;
}

static void	init_mov_vble(t_cube *cube)
{
	cube->mov.left = 0;
	cube->mov.right = 0;
	cube->mov.up = 0;
	cube->mov.down = 0;
	cube->mov.pos_x = 0.0;
	cube->mov.pos_y = 0.0;
	cube->mov.dir_x = 0.0;
	cube->mov.dir_y = 0.0;
	cube->mov.plane_x = 0.0;
	cube->mov.plane_y = 0.0;
	cube->mov.map_x = 0;
	cube->mov.map_y = 0;
	cube->view.left = 0;
	cube->view.right = 0;
	cube->view.x = 0.0;
}

void	set_raycast(t_cube *cube)
{
	cube->ray.dir_x = 0.0;
	cube->ray.dir_y = 0.0;
	cube->ray.side_x = 0.0;
	cube->ray.side_y = 0.0;
	cube->ray.delta_x = 0.0;
	cube->ray.delta_y = 0.0;
	cube->ray.perp = 0.0;
	cube->ray.step_x = 0;
	cube->ray.step_y = 0;
	cube->ray.step = 0.0;
	cube->ray.roblox = 0;
	cube->ray.side = 0;
	cube->ray.lh = 0;
	cube->ray.n_tex = 0;
	cube->ray.x = 0;
	cube->ray.y = 0;
	cube->ray.pos = 0.0;
	cube->draw.start = 0;
	cube->draw.end = 0;
	cube->draw.x = 0;
	cube->draw.y = 0;
	cube->mov.map_x = 0;
	cube->mov.map_y = 0;
	cube->view.x = 0.0;
}

static void	init_tex_vble(t_cube *c)
{
	int	x;

	x = 0;
	while (x < 4)
	{
		c->wall[x].img = NULL;
		c->wall[x].data = NULL;
		c->wall[x].w = 0;
		c->wall[x].h = 0;
		c->wall[x].bpp = 0;
		c->wall[x].sz = 0;
		c->wall[x].endian = 0;
		x++;
	}
	set_sprites(c);
}

void	set_struct(t_cube *cube)
{
	init_file_vble(cube);
	init_mov_vble(cube);
	set_raycast(cube);
	init_tex_vble(cube);
	cube->draw.trig = 1;
	cube->lib.mlx = NULL;
	cube->lib.mlx_win = NULL;
	cube->win.img = NULL;
	cube->nrows = 0;
	cube->flag.tex_n = 0;
	cube->flag.tex_s = 0;
	cube->flag.tex_w = 0;
	cube->flag.tex_e = 0;
	cube->flag.tex_spr = 0;
	cube->flag.res = 0;
	cube->flag.floor = 0;
	cube->flag.sky = 0;
	cube->flag.map = 0;
	cube->flag.player = 0;
}
