/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:34:34 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/28 15:06:30 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	set_color(t_fdf *fdf, int x, int y)
{
	int		z;
	float	i;

	z = fdf->map[y][x];
	i = (float)fdf->svg.len / 6;
	if (z <= fdf->svg.d1 + i)
		return (COLOR_1);
	else if (z <= (fdf->svg.d1 + 2 * i))
		return (COLOR_2);
	else if (z <= (fdf->svg.d1 + 3 * i))
		return (COLOR_3);
	else if (z <= (fdf->svg.d1 + 4 * i))
		return (COLOR_4);
	else if (z <= (fdf->svg.d1 + 5 * i))
		return (COLOR_5);
	else if (z <= (fdf->svg.d1 + 6 * i))
		return (WHITE);
	return (0);
}

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	if (x >= WINDOW_W || x < 0 || y >= WINDOW_H || y < 0)
		return ;
	fdf->img.addr[fdf->img.w * y + x] = color;
}


int	create_img(t_fdf *fdf)
{
	t_coord	spot;

	spot.y = 0;
	while (spot.y < fdf->rows)
	{
		spot.x = 0;
		while (spot.x < fdf->cols)
		{
			fdf->color = set_color(fdf, spot.x, spot.y);
			if (spot.x < fdf->cols - 1)
				draw_line(fdf, spot, spot.x + 1, spot.y);
			if (spot.y < fdf->rows - 1)
				draw_line(fdf, spot, spot.x, spot.y + 1);
			spot.x++;
		}
		spot.y++;
	}
	mlx_put_image_to_window(fdf->lib.mlx, fdf->lib.win, fdf->img.img, 0, 0);
	return (1);
}
