/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:27:11 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/28 15:35:11 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"


void	iso_view(int *x, int *y, int z, double angle)
{
	int	i;
	int	j;

	i = *x;
	j = *y;
	*x = (i - j) * cos(angle);
	*y = (i + j) * sin(angle) - z;
}

void	vector_descend(t_fdf *fdf, t_coord a1, t_coord a2)
{
	t_vars	desc_line;

	desc_line.dx = a2.x - a1.x;
	desc_line.dy = a2.y - a1.y;
	desc_line.yi = 1;
	if (desc_line.dy < 0)
	{
		desc_line.yi = -1;
		desc_line.dy = -desc_line.dy;
	}
	desc_line.d = (2 * desc_line.dy) - desc_line.dx;
	desc_line.y = a1.y;
	while (a1.x < a2.x)
	{
		my_mlx_pixel_put(fdf, a1.x, desc_line.y, fdf->color);
		if (desc_line.d > 0)
		{
			desc_line.y = desc_line.y + desc_line.yi;
			desc_line.d = desc_line.d + (2 * (desc_line.dy - desc_line.dx));
		}
		else
			desc_line.d = desc_line.d + 2 * desc_line.dy;
		a1.x++;
	}
}

void	vector_ascend(t_fdf *fdf, t_coord a1, t_coord a2)
{
	t_vars	asc_line;

	asc_line.dx = a2.x - a1.x;
	asc_line.dy = a2.y - a1.y;
	asc_line.xi = 1;
	if (asc_line.dx < 0)
	{
		asc_line.xi = -1;
		asc_line.dx = -asc_line.dx;
	}
	asc_line.d = (2 * asc_line.dx) - asc_line.dy;
	asc_line.x = a1.x;
	while (a1.y < a2.y)
	{
		my_mlx_pixel_put(fdf, asc_line.x, a1.y, fdf->color);
		if (asc_line.d > 0)
		{
			asc_line.x = asc_line.x + asc_line.xi;
			asc_line.d = asc_line.d + (2 * (asc_line.dx - asc_line.dy));
		}
		else
			asc_line.d = asc_line.d + 2 * asc_line.dx;
		a1.y++;
	}
}

void	draw_line(t_fdf *fdf, t_coord a1, int x1, int y1)
{
	int		z[2];
	t_coord	a2;

	a2.x = x1;
	a2.y = y1;
	z[0] = fdf->map[(int)a1.y][(int)a1.x];
	z[1] = fdf->map[(int)a2.y][(int)a2.x];
	zoom_view(fdf, &a1, &a2, z);
	iso_view(&a1.x, &a1.y, z[0], fdf->view.perspective);
	iso_view(&a2.x, &a2.y, z[1], fdf->view.perspective);
	position_view(fdf, &a1, &a2);
	if (abs(a2.y - a1.y) < abs(a2.x - a1.x))
	{
		if (a1.x > a2.x)
			vector_descend(fdf, a2, a1);
		else
			vector_descend(fdf, a1, a2);
	}
	else
	{
		if (a1.y > a2.y)
			vector_ascend(fdf, a2, a1);
		else
			vector_ascend(fdf, a1, a2);
	}
}
