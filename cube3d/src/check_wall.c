/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errflags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 20:44:02 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/19 20:44:02 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	is_space(t_cube *cube, int x, int y)
{
	int c;

	if (x < 0 || y < 0 || x >= cube->rows)
		return (1);
	c = (int)cube->map[x][y];
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == SPACE || !cube->map[x][y]);
}

void	check_walls(t_cube *cube)
{
	int	x;
	int	y;

	x = -1;
	while (cube->map[++x])
	{
		y = -1;
		while (cube->kap[x][++y])
		{
			if (cube->map[x][y] == NORTH || cube->map[x][y] == SOUTH
				|| cube->map[x][y] == WEST || cube->map[x][y] == EAST
				|| cube->map[x][y] == EMPTY || cube->map[x][y] == OBJECT)
			{
				if (is_space())
			}
		}
	}

}
