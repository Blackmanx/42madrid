/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:24:27 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/27 20:36:07 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	handle_size(t_fdf *fdf)
{
	if (fdf->img.w >= fdf->scr.x)
		fdf->img.w = fdf->scr.x;
	if (fdf->img.h >= fdf->scr.y)
		fdf->img.h = fdf->scr.y;
}

static void	init_imgview(t_fdf *fdf)
{
	fdf->img.img = NULL;
	fdf->img.addr = NULL;
	fdf->img.h = WINDOW_H;
	fdf->img.w = WINDOW_W;
	fdf->img.sz = 0;
	fdf->img.len = 0;
	fdf->img.endian = 0;
	fdf->img.bpp = 0;
	fdf->view.perspective = 0.0;
	fdf->view.angle = 0.0;
	fdf->view.x = 0;
	fdf->view.y = 0;
	fdf->view.zoom = 0;
	fdf->view.iso = 0;
	fdf->view.tan = 0;
	fdf->view.plane = 0;
	fdf->view.rot[0] = 0;
	fdf->view.rot[1] = 0;
	fdf->view.rot[2] = 0;
}

static void	init_structs(t_fdf *fdf)
{
	init_imgview(fdf);
	fdf->read.buf = NULL;
	fdf->read.b = NULL;
	fdf->read.l = NULL;
	fdf->lib.mlx = NULL;
	fdf->lib.win = NULL;
	fdf->scr.x = MAX_HEIGHT;
	fdf->scr.y = MAX_WIDTH;
}

void	declare_data(t_fdf *fdf)
{
	init_structs(fdf);
	fdf->rows = 0;
	fdf->cols = 0;
	fdf->line = NULL;
	fdf->map = NULL;
	fdf->color = 0;
	fdf->zoom = 0;
	fdf->mov = 0;
}

void	init_fdf(t_fdf *fdf)
{
	declare_data(fdf);
	fdf->lib.mlx = mlx_init();
	if (!fdf->lib.mlx)
		exit_error("Error: MLX was not initialized", NO_MLX);
	handle_size(fdf);
	fdf->lib.win = mlx_new_window(fdf->lib.mlx, fdf->img.w,
			fdf->img.h, "Amogus");
	if (!fdf->lib.win)
		exit_error("Error: Failed to create window", NO_WINDOW);
	fdf->img.img = mlx_new_image(fdf->lib.mlx, fdf->img.w,
			fdf->img.h);
	if (!fdf->img.img)
		exit_error("Error: Failed to create image", NO_IMG);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp,
			&fdf->img.sz, &fdf->img.endian);
	mlx_do_key_autorepeatoff(fdf->lib.mlx);
}
