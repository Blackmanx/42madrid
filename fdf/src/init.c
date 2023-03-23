/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:24:27 by prodrigo          #+#    #+#             */
/*   Updated: 2023/03/23 18:04:16 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_fdf(char **argv, t_fdf *fdf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	argv = NULL;
	fdf->lib.mlx = mlx_init();
	fdf->lib.win = mlx_new_window(fdf->lib.mlx,
			WINDOW_W, WINDOW_H, "Amog Us 2!");
	fdf->img.img = mlx_new_image(fdf->lib.mlx, WINDOW_W, WINDOW_H);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp,
			&fdf->img.len, &fdf->img.endian);
	while (x < WINDOW_W)
	{
		while (y < WINDOW_H)
		{
			my_mlx_pixel_put(fdf, x, y, WHITE);
			y += rand() % 30;
		}
		x += rand() % 50;
		y = 0;
	}
	mlx_put_image_to_window(fdf->lib.mlx, fdf->lib.win, fdf->img.img, 0, 0);
	mlx_hook(fdf->lib.win, 17, 0L, close_window, &fdf);
}
