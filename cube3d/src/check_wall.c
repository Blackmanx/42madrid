/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:44:02 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/20 21:48:28 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	is_space(t_cube *cube, int x, int y)
{
	int	c;

	if (x < 0 || y < 0 || x >= cube->rows)
		return (1);
	c = (int)cube->map[x][y];
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == EMPTY_SPACE || !cube->map[x][y]);
}

int	check_surroundings(t_cube *cube, int x, int y)
{
	if (is_space(cube, x - 1, y) || is_space(cube, x - 1, y - 1 )
		|| is_space(cube, x - 1, y + 1)
		|| is_space(cube, x, y - 1) || is_space(cube, x, y + 1)
		|| is_space(cube, x + 1, y - 1)
		|| is_space(cube, x + 1, y) || is_space(cube, x + 1, y + 1))
		return (1);
	return (0);
}

void	check_walls(t_cube *cube)
{
	int	x;
	int	y;

	x = -1;
	while (cube->map[++x])
	{
		y = -1;
		while (cube->map[x][++y])
		{
			if (check_direction([cube, x, y) == 1 || cube->map[x][y] == EMPTY
			|| cube->map[x][y] == OBJECT)
			{
				if (check_surroundings(cube, x, y) == 1)
				{
					if (cube->map[x][y] == EMPTY || cube->map[x][y] == OBJECT)
						exit_program(cube,
							"The map has no limits, put some walls", -4);
					else
						exit_program(cube,
							"Player clipping through the map", -5);
				}
			}
		}
	}
}
