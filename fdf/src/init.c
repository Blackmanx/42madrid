/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:06:23 by prodrigo          #+#    #+#             */
/*   Updated: 2022/01/11 18:14:31 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static	int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	reset_fdf(t_fdf *fdf)
{
	fdf->view.zoom = ft_max((WIDTH / fdf->map->w / 2),
			(HEIGHT / fdf->map->h / 2));
	fdf->view.shift[X] = WIDTH / 2;
	fdf->view.shift[Y] = (HEIGHT - fdf->map->h * fdf->view.zoom) / 2;
	fdf->view.frot = 0.8;
	fdf->view.iso = 1;
	fdf->view.flat = 1;
	fdf->view.rot[X] = 0;
	fdf->view.rot[Y] = 0;
	fdf->view.rot[Z] = 0;
}

int	init_fdf(t_fdf *fdf, t_map *map)
{
	fdf->map = map;
	fdf->img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!fdf->img)
		return (1);
	reset_fdf(fdf);
	return (0);
}

void	init_mlx(t_fdf *fdf)
{
	fdf->lib.mlx = mlx_init();
	fdf->img->img = mlx_new_image(fdf->lib.mlx, WIDTH, HEIGHT);
	fdf->img->data = mlx_get_data_addr(fdf->img->img,
			&fdf->img->bpp, &fdf->img->len, &fdf->img->endian);
	fdf->lib.win = mlx_new_window(fdf->lib.mlx, WIDTH, HEIGHT, "fdf");
}
