/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:34:34 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/28 05:03:31 by prodrigo         ###   ########.fr       */
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