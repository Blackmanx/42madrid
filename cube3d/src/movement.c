/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 00:16:06 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/23 00:29:47 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_step_side(t_cube *cube)
{
	if (cube->mov.dir_x < 0)
	{
		cube->ray.step_x = -1;
		cube->ray.side_x = (cube->mov.x - cube->mov.map_x) * cube->ray.delta_x;
	}
	else
	{
		cube->ray.step_x = 1;
		cube->ray.side_x = (cube->mov.map_x
				+ 1.0 - cube->mov.x) * cube->ray.delta_x;
	}
	if (cube->mov.dir_y < 0)
	{
		cube->ray.step_y = -1;
		cube->ray.side_y = (cube->mov.y - cube->mov.map_y) * cube->ray.delta_y;
	}
	else
	{
		cube->ray.step_y = 1;
		cube->ray.side_y = (cube->mov.map_y
				+ 1.0 - cube->mov.y) * cube->ray.delta_y;
	}
}

static void	move_player(t_cube *cube, double speed, int sg, int plane)
{
	double	x;
	double	y;

	x = cube->mov.dir_x;
	y = cube->mov.dir_y;
	if (plane == 1)
	{
		x = cube->mov.plane_x;
		y = cube->mov.plane_y;
	}
	if (cube->map[(int)(cube->mov.x + sg * x * speed)][(int)cube->mov.y]
			== EMPTY)
		cube->mov.x += sg * x * speed;
	if (cube->map[(int)cube->mov.x][(int)(cube->mov.y + sg * y * speed)]
			== EMPTY)
		cube->mov.y += sg * y * speed;
}

int	move(t_cube *cube, double speed)
{
	if (cube->mov.up)
		move_player(cube, speed, 1, 0);
	if (cube->mov.down)
		move_player(cube, speed, -1, 0);
	if (cube->mov.right)
		move_player(cube, speed, 1, 1);
	if (cube->mov.left)
		move_player(cube, speed, -1, 1);
	return (cube->mov.up || cube->mov.down
		|| cube->mov.left || cube->mov.right);
}

static void	rotate(t_cube *cube, double speed)
{
	double	aux_dir;
	double	aux_plane;

	aux_dir = cube->mov.dir_x;
	cube->mov.dir_x = cube->mov.dir_x
		* cos(speed) - cube->mov.dir_y * sin(speed);
	cube->mov.dir_y = aux_dir * sin(speed) + cube->mov.dir_y * cos(speed);
	aux_plane = cube->mov.plane_x;
	cube->mov.plane_x = cube->mov.plane_x
		* cos(speed) - cube->mov.plane_y * sin(speed);
	cube->mov.plane_y = aux_plane * sin(speed) + cube->mov.plane_y * cos(speed);
}

int	rotate_keys(t_cube *cube, double speed)
{
	if (cube->view.right)
		rotate_cam(cube, -speed);
	if (cube->view.left)
		rotate_cam(cube, speed);
	return (cube->view.right || cube->view.left);
}
