/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 23:34:53 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/09 23:42:08 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	alloc_map(t_fdf *fdf)
{
	int	i;

	fdf->map->z = (int **)malloc(sizeof(int *) * fdf->map->h);
	fdf->map->col = (int **)malloc(sizeof(int *) * fdf->map->h);
	if (!fdf->map->z || !fdf->map->col)
		fd_error("Error");
	i = -1;
	while (++i < fdf->map->h)
	{
		fdf->map->z[i] = (int *)malloc(sizeof(int) * fdf->map->w);
		fdf->map->col[i] = (int *)malloc(sizeof(int) * fdf->map->w);
		if (!fdf->map->z[i] || !fdf->map->col[i])
			fd_error("Error");
	}
}

void	free_map(t_fdf *fdf)
{
	int	i;

	if (!fdf->map)
		return ;
	if (fdf->map->z)
	{
		i = -1;
		while (++i < fdf->map->h)
		{
			if (fdf->map->z[i])
				free(fdf->map->z[i]);
		}
		free(fdf->map->z);
	}
	if (fdf->map->col)
	{
		i = -1;
		while (++i < fdf->map->h)
		{
			if (fdf->map->col[i])
				free(fdf->map->col[i]);
		}
		free(fdf->map->col);
	}
	free(fdf->map);
}
