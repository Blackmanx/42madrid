/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:16:08 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/28 02:10:50 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	zoom_view(t_fdf *fdf, t_coord *a1, t_coord *a2, int z[2])
{
	a1->x *= fdf->view.zoom;
	a1->y *= fdf->view.zoom;
	a2->x *= fdf->view.zoom;
	a2->y *= fdf->view.zoom;
	z[0] *= fdf->view.zoom / 2;
	z[1] *= fdf->view.zoom / 2;
}

void	position_view(t_fdf *fdf, t_coord *a1, t_coord *a2)
{
	a1->x += fdf->view.x;
	a1->y += fdf->view.y;
	a2->x += fdf->view.x;
	a2->y += fdf->view.y;
}

static int	zoom(int size)
{
	if (size <= 20)
		return (ZOOM);
	else if (size <= 50)
		return (ZOOM / 2);
	else if (size < 150)
		return (ZOOM / 4);
	else
		return (2);
}

static void	create_vector(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	fdf->svg.d2 = __INT_MAX__ * -1;
	fdf->svg.d1 = __INT_MAX__;
	while (y < fdf->rows)
	{
		x = 0;
		while (x < fdf->cols)
		{
			if (fdf->map[y][x] < fdf->svg.d1)
				fdf->svg.d1 = fdf->map[y][x];
			if (fdf->map[y][x] > fdf->svg.d2)
				fdf->svg.d2 = fdf->map[y][x];
			x++;
		}
		y++;
	}
	fdf->svg.len = abs(fdf->svg.d2 - fdf->svg.d1);
}

void	view_init(t_fdf *fdf)
{
	create_vector(fdf);
	fdf->view.angle = ANGLE;
	fdf->view.perspective = PERSPECTIVE;
	fdf->view.iso = ISO;
	fdf->view.plane = PLANE;
	fdf->view.obl = OBLIQUE;
	fdf->view.zoom = zoom(fdf->cols);
	fdf->view.x = WINDOW_W / 3 + 100;
	fdf->view.y = WINDOW_H / 2;
	fdf->view.rot[0] = 0;
	fdf->view.rot[1] = 0;
	fdf->view.rot[2] = 0;
}
