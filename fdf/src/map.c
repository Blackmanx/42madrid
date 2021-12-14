/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 12:58:57 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/14 17:20:47 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	map_error(t_map *map, char *str)
{
	free_map(map);
	fd_error(str);
}

static int	count_file_nbr(t_map *map, char *l)
{
	int		n;
	char	**split;

	split = ft_split(l, ' ');
	if (!split)
		map_error(map, "Error: Malloc did an oopsie.");
	n = 0;
	while (split[n])
		n++;
	free_tab(split);
	return (n);
}

void	maplloc(t_map *map)
{
	int	i;

	map->col = (int **)malloc(sizeof(int *) * map->h);
	map->z = (int **)malloc(sizeof(int *) * map->h);
	if (!map->col || !map->z)
		map_error(map, "Error");
	i = -1;
	while (++i < map->h)
	{
		map->col = (int *)malloc(sizeof(int) * map->w);
		map->z = (int *)malloc(sizeof(int) * map->w);
		if (!map->col || !map->z)
			map_error(map, "Error");
	}
}

t_map	*init_map(char *f_path)
{
	int		fd;
	t_map	*map;
	char	*l;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	fd = open(f_path, O_RDONLY);
	if (fd < 0)
		fd_error_fd("Error while opening file", -42);
	l = get_next_l(fd);
	if (!l)
		map_error(map, "Error: File is empty.");
	map->w = count_file_nbr(map, l);
	while (l)
	{
		map->h += 1;
		free(l);
		l = get_next_line(fd);
	}
	free(l);
	close(fd);
	return (map);
}
