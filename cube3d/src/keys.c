/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:13:00 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/22 20:47:36 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	key_press(int key, t_cube *cube)
{
	if (key == (int)KEY_W)
		cube->mov.up = 1;
	else if (key == (int)KEY_A)
		cube->mov.left = 1;
	else if (key == (int)KEY_S)
		cube->mov.down = 1;
	else if (key == (int)KEY_D)
		cube->mov.right = 1;
	else if (key == (int)KEY_RIGHT)
		cube->view.right = 1;
	else if (key == (int)KEY_LEFT)
		cube->view.left = 1;
	else if (key == (int)KEY_ESCAPE)
		exit_handler(cube);
	return (1);
}

int	key_release(int key, t_cube *cube)
{
	if (key == (int)KEY_W)
		cube->mov.up = 0;
	else if (key == (int)KEY_A)
		cube->mov.left = 0;
	else if (key == (int)KEY_S)
		cube->mov.down = 0;
	else if (key == (int)KEY_D)
		cube->mov.right = 0;
	else if (key == (int)KEY_RIGHT)
		cube->view.right = 0;
	else if (key == (int)KEY_LEFT)
		cube->view.left = 0;
	else if (key == (int)KEY_ESCAPE)
		exit_handler(cube);
	return (1);
}
