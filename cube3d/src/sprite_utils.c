/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:40:34 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/23 00:55:24 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	search_sprites(t_cube *cube)
{
	int	x;
	int	y;
	int	i;

	cube->spr_pos = malloc(sizeof(t_spr) * (get_spr(cube)));
	i = 0;
	x = -1;
	while (cube->map[++x])
	{
		y = -1;
		while (cube->map[x][++y])
		{
			if (cube->map[x][y] == OBJECT)
			{
				cube->spr_pos[i].x = x + 0.5;
				cube->spr_pos[i].y = y + 0.5;
				cube->spr_pos[i].len = ((cube->mov.x - cube->spr_pos[i].x)
						* (cube->mov.x - cube->spr_pos[i].x) + (cube->mov.y
							- cube->spr_pos[i].y) * (cube->mov.y
							- cube->spr_pos[i].y));
				i++;
			}
		}
	}
}

int	get_spr(t_cube *cube)
{
	int	x;
	int	y;
	int	n;

	x = -1;
	n = 0;
	while (cube->map[++x])
	{
		y = -1;
		while (cube->map[x][++y])
			if (cube->map[x][y] == OBJECT)
				n++;
	}
	return (n);
}

void	set_spr(t_cube *cube)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = -1;
	cube->spr_pos = malloc(sizeof(t_spr) * (get_spr(cube)));
	while (cube->map[++x])
	{
		y = -1;
		while (cube->map[x][++y])
		{
			if (cube->map[x][y] == OBJECT)
			{
				cube->spr_pos[i].x = x + 0.5;
				cube->spr_pos[i].y = y + 0.5;
				cube->spr_pos[i].len = ((cube->mov.x - cube->spr_pos[i].x)
						* (cube->mov.x - cube->spr_pos[i].x)
						+ (cube->mov.y - cube->spr_pos[i].y)
						* (cube->mov.y - cube->spr_pos[i].y));
			}
		}
	}
}
