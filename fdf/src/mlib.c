/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlib.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:26:01 by prodrigo          #+#    #+#             */
/*   Updated: 2022/01/11 17:51:58 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	close_win(t_fdf *fdf)
{
	free_all(fdf);
	exit (EXIT_SUCCESS);
	return (0);
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		close_win(fdf);
	if (keycode == KEY_R)
		reset_fdf(fdf);
	if (keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D)
		handle_move(keycode, fdf);
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		handle_zoom(keycode, fdf);
	if (keycode == KEY_U || keycode == KEY_J || keycode == KEY_I
		|| keycode == KEY_K || keycode == KEY_O || keycode == KEY_L)
		handle_rot(keycode, fdf);
	if (keycode == KEY_MINUS || keycode == KEY_PLUS)
		handle_flattening(keycode, fdf);
	if (keycode == KEY_P)
	{
		if (fdf->view.iso)
			fdf->view.iso = 0;
		else
			fdf->view.iso = 1;
	}
	draw(fdf);
	return (0);
}

int	mlib_init(t_map *map, t_fdf *fdf)
{
	if (init_fdf(fdf, map))
	{
		free_all(fdf);
		fd_error_fd("Error while initiating fdf", -42);
	}
	init_mlx(fdf);
	mlx_hook(fdf->lib.win, 2, 1L << 0, key_hook, fdf);
	mlx_hook(fdf->lib.win, 17, 1L << 17, close_win, fdf);
	draw(fdf);
	mlx_loop(fdf->lib.mlx);
	free_all(fdf);
	return (EXIT_SUCCESS);
}
