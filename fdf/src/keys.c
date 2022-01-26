/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:57:24 by prodrigo          #+#    #+#             */
/*   Updated: 2022/01/11 18:05:54 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	handle_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_DOWN)
	{
		if (fdf->view.zoom > 0)
			fdf->view.zoom -= ZOOM;
	}
	if (keycode == KEY_UP)
	{
		if (fdf->view.zoom < INT_MAX)
			fdf->view.zoom += ZOOM;
	}
}

void	handle_move(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_W)
		fdf->view.shift[Y] += SHIFT;
	if (keycode == KEY_S)
		fdf->view.shift[Y] -= SHIFT;
	if (keycode == KEY_A)
		fdf->view.shift[X] += SHIFT;
	if (keycode == KEY_D)
		fdf->view.shift[X] -= SHIFT;
}

void	handle_flattening(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PLUS)
	{
		if (fdf->view.flat < 10)
			fdf->view.flat += 0.1;
	}
	if (keycode == KEY_MINUS)
	{
		if (fdf->view.flat > 0)
			fdf->view.flat -= 0.1;
	}
}

void	handle_rot(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_U)
		fdf->view.rot[X] += ROT;
	if (keycode == KEY_J)
		fdf->view.rot[X] -= ROT;
	if (keycode == KEY_I)
		fdf->view.rot[Y] += ROT;
	if (keycode == KEY_K)
		fdf->view.rot[Y] -= ROT;
	if (keycode == KEY_O)
		fdf->view.rot[Z] += ROT;
	if (keycode == KEY_L)
		fdf->view.rot[Z] -= ROT;
}
