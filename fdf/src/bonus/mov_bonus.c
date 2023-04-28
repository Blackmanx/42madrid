/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_bonus.fdf                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:34:36 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/28 15:36:13 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

void	cam_mov(t_fdf *fdf, int key)
{
	if (key == KEY_LEFT)
		fdf->view.rot[0] = 1;
	if (key == KEY_RIGHT)
		fdf->view.rot[1] = 1;
	if (key == KEY_UP)
		fdf->view.rot[2] = 1;
	if (key == KEY_DOWN)
	{
		fdf->view.rot[0] = 0;
		fdf->view.rot[1] = 0;
		fdf->view.rot[2] = 0;
		fdf->view.angle = 0;
	}
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP)
		fdf->view.angle += ANGLE;
	if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_UP || key == KEY_DOWN)
		fdf->mov = 1;
}

int	zoom_bonus(t_fdf *fdf, int key, int x, int y)
{
	x++;
	y++;
	if (key == M_SCR_U && fdf->view.zoom)
		fdf->view.zoom += 1;
	if (key == M_SCR_D && fdf->view.zoom)
		fdf->view.zoom -= 1;
	if (!fdf->view.zoom)
		fdf->view.zoom = 1;
	if ((key == M_SCR_U || key == M_SCR_D) && fdf->view.zoom)
		regen_img(fdf);
	return (0);
}

void	hooks_perspective(t_fdf *fdf, int key)
{
	if (key == KEY_I)
	{
		fdf->view.iso = ISO;
		fdf->view.plane = PLANE;
		fdf->view.obl = OBLIQUE;
		fdf->view.angle = PERSPECTIVE;
	}
	if (key == KEY_P)
	{
		fdf->view.plane = PLANE_ALT;
		fdf->view.iso = ISO0;
		fdf->view.obl = OBLIQUE;
	}
	if (key == KEY_O)
	{
		fdf->view.plane = PLANE;
		fdf->view.iso = ISO0;
		fdf->view.obl = OBLIQUE1;
		fdf->view.angle = PERSPECTIVE_ALT;
	}
	if (key == KEY_P || key == KEY_O || key == KEY_I)
		fdf->mov = 1;
}

static void	rotation(int *a1, int *b1, double angle, int plane)
{
	int	a0;
	int	b0;

	a0 = *a1;
	b0 = *b1;
	if (plane == Z)
	{
		*a1 = a0 * cos(angle) - b0 * sin(angle);
		*b1 = -a0 * sin(angle) + b0 * cos(angle);
	}
	else
	{
		*a1 = a0 * cos(angle) + b0 * sin(angle);
		*b1 = a0 * sin(angle) + b0 * cos(angle);
	}
}

void	rotate(int *x, int *y, int *z, t_fdf *fdf)
{
	if (fdf->view.rot[0])
		rotation(y, z, fdf->view.angle, X);
	if (fdf->view.rot[1])
		rotation(x, z, fdf->view.angle, Y);
	if (fdf->view.rot[2])
		rotation(x, y, fdf->view.angle, Z);
}
