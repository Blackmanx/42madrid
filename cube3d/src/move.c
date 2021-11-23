/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:58:35 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 20:58:37 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	step_initial_side(t_cube *c)
{
	if (c->ray.dir_x < 0)
	{
		c->ray.step_x = -1;
		c->ray.side_x = (c->mov.pos_x - c->mov.map_x) * c->ray.delta_x;
	}
	else
	{
		c->ray.step_x = 1;
		c->ray.side_x = (c->mov.map_x + 1.0 - c->mov.pos_x) * c->ray.delta_x;
	}
	if (c->ray.dir_y < 0)
	{
		c->ray.step_y = -1;
		c->ray.side_y = (c->mov.pos_y - c->mov.map_y) * c->ray.delta_y;
	}
	else
	{
		c->ray.step_y = 1;
		c->ray.side_y = (c->mov.map_y + 1.0 - c->mov.pos_y) * c->ray.delta_y;
	}
}

static void	move_player(t_cube *c, double speed, int sg, int plane)
{
	double	dx;
	double	dy;

	dx = c->mov.dir_x;
	dy = c->mov.dir_y;
	if (plane == 1)
	{
		dx = c->mov.plane_x;
		dy = c->mov.plane_y;
	}
	if (c->map[(int)(c->mov.pos_x + sg * dx * speed)][(int)c->mov.pos_y] == EMPTY)
		c->mov.pos_x += sg * dx * speed;
	if (c->map[(int)c->mov.pos_x][(int)(c->mov.pos_y + sg * dy * speed)] == EMPTY)
		c->mov.pos_y += sg * dy * speed;
}

int	move(t_cube *c, double speed)
{
	if (c->mov.up)
		move_player(c, speed, 1, 0);
	if (c->mov.down)
		move_player(c, speed, -1, 0);
	if (c->mov.right)
		move_player(c, speed, 1, 1);
	if (c->mov.left)
		move_player(c, speed, -1, 1);
	return (c->mov.up || c->mov.down || c->mov.left || c->mov.right);
}

static void	rotate_view(t_cube *c, double speed)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = c->mov.dir_x;
	c->mov.dir_x = c->mov.dir_x * cos(speed) - c->mov.dir_y * sin(speed);
	c->mov.dir_y = oldDirX * sin(speed) + c->mov.dir_y * cos(speed);
	oldPlaneX = c->mov.plane_x;
	c->mov.plane_x = c->mov.plane_x * cos(speed) - c->mov.plane_y * sin(speed);
	c->mov.plane_y = oldPlaneX * sin(speed) + c->mov.plane_y * cos(speed);
}

int	rotate(t_cube *c, double speed)
{
	if (c->view.right)
		rotate_view(c, -speed);
	if (c->view.left)
		rotate_view(c, speed);
	return (c->view.right || c->view.left);
}
