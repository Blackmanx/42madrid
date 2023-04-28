/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:34:34 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/28 19:51:43 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	regen_img(t_fdf *fdf)
{
	mlx_destroy_image(fdf->lib.mlx, fdf->img.img);
	fdf->img.img = mlx_new_image(fdf->lib.mlx, fdf->img.w, fdf->img.h);
	if (!fdf->img.img)
		exit_error("Error: Failed to create image", NO_IMG);
	fdf->img.addr = (int *)mlx_get_data_addr(fdf->img.img, &fdf->img.bpp,
			&fdf->img.sz, &fdf->img.endian);
	create_img(fdf);
}


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
		return (WHITE);
	else if (z <= (fdf->svg.d1 + 4 * i))
		return (COLOR_4);
	else if (z <= (fdf->svg.d1 + 5 * i))
		return (COLOR_5);
	else if (z <= (fdf->svg.d1 + 6 * i))
		return (WHITE);
	return (0);
}

static void	put_controls(void *mlx, void *window)
{
	int	x;

	x = 200 / 4;
	mlx_string_put(mlx, window, x, 40, WHITE, "CONTROLS");
	mlx_string_put(mlx, window, x, 45, COLOR_1, "________");
	mlx_string_put(mlx, window, x, 70, COLOR_5, "Zoom: Scroll");
	mlx_string_put(mlx, window, x, 100, COLOR_5, "Move");
	mlx_string_put(mlx, window, x, 105, COLOR_1, "____");
	mlx_string_put(mlx, window, x, 130, WHITE, "W -> Up");
	mlx_string_put(mlx, window, x, 150, WHITE, "S -> Down");
	mlx_string_put(mlx, window, x, 170, WHITE, "A -> Left");
	mlx_string_put(mlx, window, x, 190, WHITE, "D -> Right");
	mlx_string_put(mlx, window, x, 220, COLOR_5, "Projection");
	mlx_string_put(mlx, window, x, 225, COLOR_1, "__________");
	mlx_string_put(mlx, window, x, 250, WHITE, "I -> Isometric");
	mlx_string_put(mlx, window, x, 270, WHITE, "P -> Plane");
	mlx_string_put(mlx, window, x, 290, WHITE, "O -> Oblique");
	mlx_string_put(mlx, window, x, 320, COLOR_5, "Rotation: Arrows");
	mlx_string_put(mlx, window, x, 325, COLOR_1, "________________");
	mlx_string_put(mlx, window, x, 350, WHITE, "Left -> X Axis");
	mlx_string_put(mlx, window, x, 370, WHITE, "Right -> Y Axis");
	mlx_string_put(mlx, window, x, 390, WHITE, "Up -> Z Axis");
	mlx_string_put(mlx, window, x, 410, WHITE, "Down -> Reset");
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
	put_controls(fdf->lib.mlx, fdf->lib.win);
	mlx_mouse_hook(fdf->lib.win, zoom_bonus, fdf);
	return (1);
}
