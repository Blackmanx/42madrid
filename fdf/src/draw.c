/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:34:34 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/20 02:55:25 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"


int	set_color(int x, int y, t_fdf *fdf)
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
	char	*dst;

	if (x >= WID_CAM || x < 0 || y >= HEI_CAM || y < 0)
		return ;
	dst = fdf->img.addr + (y * fdf->img.len + x * (fdf->img.bpp / 8));
	*(unsigned int *)dst = color;
}
