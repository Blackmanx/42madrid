/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:23:20 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/20 21:45:26 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	set_player_dir(t_cube *cube, int i, int j)
{
	cube->mov.dir_x = 0.0;
	cube->mov.dir_y = 0.0;
	if (cube->map[i][j] == NORTH)
		cube->mov.dir_x == -1.0;
	else if (cube->map[i][j] == SOUTH)
		cube->mov.dir_x = 1.0;
	else if (cube->map[i][j] == WEST)
		cube->mov.dir_y = -1.0;
	else if (cube->map[i][j] == EAST)
		cube->mov.dir_y = 1.0;
	cube->mov.plane_x = cube->mov.dir_y * ((ANGLE * M_PI) / 180);
	cube->mov.plane_y = -cube->mov.dir_x * ((ANGLE * M_PI) / 180);
}

int	check_direction(t_cube *cube, int i, int j)
{
	if (cube->map[i][j] == NORTH || cube->map[i][j] == EAST
		|| cube->map[i][j] == SOUTH || cube->map[i][j] == WEST)
		return (1);
	return (0);
}

void	get_player(t_cube *cube)
{
	int	i;
	int	j;

	i = -1;
	while (cube->map[++i])
	{
		j = -1;
		while (cube->map[i][++j])
		{
			if (check_direction(cube, i, j) == 1)
			{
				cube->mov.x = i + 0.5;
				cube->mov.y = j + 0.5;
				set_player_dir(cube, i, j);
				cube->map[i][j] = EMPTY;
				cube->flag.player++;
			}
		}
	}
	if (!cube->flag.player)
		exit_program(cube, "No player found", -6);
	if (cube->flag.player > 1)
		exit_program(cube, "This is a single player game!", -7);
}
