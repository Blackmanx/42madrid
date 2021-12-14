/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:18:10 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/14 17:39:47 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_peaks(t_map *map)
{
	int	x;
	int	y;

	x = -1;
	while (++y < map->h)
	{
		y = -1;
		while (++x < map->w)
		{
			if (map->z[x][y] < map->z_min)
				map->z_min = map->z[x][y];
			else if (map->z[y][x] > map->z_max)
				map->z_max = map->z[y][x];
		}
	}
}

void	fill_z_col(t_map *map, int fd)
{
	int		x;
	int		y;
	char	*line;
	char	**split;

	x = -1;
	while (++y < map->h)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		if (!split)
			map_error(map, "Malloc did an oopsie!");
		y = -1;
		while (++y < map->w)
		{
			map->z[x][y] = ft_atoi(split[y]);
			map->col[x][y] = parse_color(map, split[y]);
		}
		free_tab(split);
		free(line);
	}
}
