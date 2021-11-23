/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:57:40 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 20:57:45 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	err_tex(char *line)
{
	int	i;
	int	k;
	int	count;

	count = 0;
	k = -1;
	i = 0;
	while (line[++k])
	{
		while (line[i] && line[i] != ' ' && line[i] != '\t')
			i++;
		if (line[i])
			count++;
		while (line[i] && (int)line[i] > 32 && (int)line[i] <= 126)
			i++;
	}
	if (count > 1)
		return (1);
	return (0);
}

int	err_res(char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'R')
		i++;
	while (line[i] && (ft_isdigit(line[i]) || ft_isspace(line[i])))
		i++;
	if (line[i])
		return (1);
	return (0);
}

void	err_rgb(t_cube *cube, char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (s[i] == 'F' || s[i] == 'C')
		i++;
	while (s[i] && (ft_isdigit(s[i]) || ft_isspace(s[i]) || s[i] == ','))
	{
		if (s[i] == ',' && (!ft_isdigit(s[i + 1]) && !ft_isspace(s[i + 1])))
			exit_program(cube, "Invalid RGB format\n", 1);
		if (s[i] == ',')
			count++;
		i++;
	}
	if (s[i] || count != 2)
	{
		if (s[0] == 'F')
			exit_program(cube, "Invalid RGB format in floor col\n", 1);
		else if (s[0] == 'C')
			exit_program(cube, "Invalid RGB format in ceiling col\n", 1);
	}
}

static int	is_empty(t_cube *c, int x, int y)
{
	if (x < 0 || y < 0 || x >= c->nrows)
		return (1);
	return (((int)c->map[x][y] >= 9 && (int)c->map[x][y] <= 13)
		|| c->map[x][y] == ' ' || !c->map[x][y]);
}

void	check_wall(t_cube *c)
{
	int	x;
	int	y;

	x = -1;
	while (c->map[++x])
	{
		y = -1;
		while (c->map[x][++y])
		{
			if (c->map[x][y] == EMPTY || c->map[x][y] == OBJECT
				|| c->map[x][y] == NORTH || c->map[x][y] == SOUTH
				|| c->map[x][y] == WEST || c->map[x][y] == EAST)
			{
				if (is_empty(c, x - 1, y - 1) || is_empty(c, x - 1, y)
					|| is_empty(c, x - 1, y + 1) || is_empty(c, x, y - 1)
					|| is_empty(c, x, y + 1) || is_empty(c, x + 1, y - 1)
					|| is_empty(c, x + 1, y) || is_empty(c, x, y + 1))
				{
					if (c->map[x][y] == EMPTY || c->map[x][y] == OBJECT)
						exit_program(c, "Map must be surrounded by walls\n", 1);
					exit_program(c, "The player must be inside the map\n", 1);
				}
			}
		}
	}
}
