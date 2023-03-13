/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:24:27 by prodrigo          #+#    #+#             */
/*   Updated: 2023/03/13 21:58:31 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_fdf(char **argv, t_fdf *fdf)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	argv = NULL;
	fdf->lib.mlx = mlx_init();
	fdf->lib.win = mlx_new_window(fdf->lib.mlx, 1920, 1080, "Amog Us 2!");
	fdf->img.img = mlx_new_image(fdf->lib.mlx, 1920, 1080);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp,
			&fdf->img.len, &fdf->img.endian);
	while (++x < 1920)
	{
		while (++y < 1080)
			my_mlx_pixel_put(fdf, x, y, 0x00FF0000);
		y = 0;
	}
	mlx_put_image_to_window(fdf->lib.mlx, fdf->lib.win, fdf->img.img, 0, 0);
	mlx_hook(fdf->lib.win, 17, 0L, close_window, &fdf);
}
