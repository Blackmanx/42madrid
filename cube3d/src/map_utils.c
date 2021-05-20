/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:54:03 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/20 20:13:30 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_map(t_cube *cube)
{
	int	i;

	i = cube->rows + 1;
	if (cube->map)
	{
		while (--i >= 0)
		{
			free(cube->map[i]);
			cube->map[i] = NULL;
		}
		free(cube->map);
		cube->map = NULL;
	}
}

int	get_mapdim(t_cube *cube)
{
	int	i;
	int	n;
	int	len;

	n = 0;
	i = 1;
	len = ft_strlen(cube->map[0]);
	while (cube->map[i])
	{
		n = ft_strlen(cube->map[i]);
		if (n > len)
			len = n;
		i++;
	}
	cube->rows = i;
	return (len);
}

void	get_map(t_cube *cube)
{
	int		i;
	int		j;
	int		n;
	char	**map;

	i = -1;
	j = get_mapdim(cube);
	map = (char **)malloc((cube->rows + 1) * sizeof(char *));
	while (cube->map[++i])
	{
		map[i] = (char *)malloc((j + 1) * sizeof(char));
		n = ft_strlen(cube->map[i]);
		ft_memcpy(map[i], cube->map[i], n);
		if (n < j)
			ft_memset(&map[i][n], ' ', j - n);
		map[i][j] = '\0';
	}
	map[i] = NULL;
	free_map(cube);
	cube->map = map;
}
