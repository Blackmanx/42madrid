/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:58:54 by igomez-p          #+#    #+#             */
/*   Updated: 2021/05/24 19:37:34 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_res(char *num)
{
	int	len;
	int	i;

	i = 0;
	while (num[i])
	{
		if (!(num[i] >= '0' && num[i] <= '9'))
			return (0);
		i++;
	}
	len = ft_strlen(num);
	if (len > MAX_LEN || !len)
		return (0);
	if (len == MAX_LEN && ft_strncmp(num, "214748364", 9) && num[len - 1] > '7')
		return (0);
	return (1);
}

int	check_text(t_cube *c, char *text)
{
	int	len;

	len = ft_strlen(text);
	if (c->tex.n && !ft_strncmp(c->tex.n, text, len))
		return (0);
	if (c->tex.s && !ft_strncmp(c->tex.s, text, len))
		return (0);
	if (c->tex.w && !ft_strncmp(c->tex.w, text, len))
		return (0);
	if (c->tex.e && !ft_strncmp(c->tex.e, text, len))
		return (0);
	if (ft_strncmp(&text[len - 4], ".xpm", 4))
		return (-1);
	return (1);
}

int	check_ids(t_cube *c)
{
	return (c->flag.tex_n + c->flag.tex_s + c->flag.tex_w
		+ c->flag.tex_e + c->flag.tex_spr + c->flag.res
		+ c->flag.floor + c->flag.sky + c->flag.map);
}

static void	player_dir(t_cube *c, int x, int y)
{
	c->mov.dir_y = 0.0;
	c->mov.dir_x = 0.0;
	if (c->map[x][y] == NORTH)
		c->mov.dir_x = -1.0;
	else if (c->map[x][y] == SOUTH)
		c->mov.dir_x = 1.0;
	else if (c->map[x][y] == EAST)
		c->mov.dir_y = 1.0;
	else if (c->map[x][y] == WEST)
		c->mov.dir_y = -1.0;
	c->mov.plane_x = c->mov.dir_y * ((CAM * M_PI) / 180);
	c->mov.plane_y = -c->mov.dir_x * ((CAM * M_PI) / 180);
}

void	search_player(t_cube *c)
{
	int	k;
	int	i;

	k = -1;
	while (c->map[++k])
	{
		i = -1;
		while (c->map[k][++i])
		{
			if (c->map[k][i] == NORTH || c->map[k][i] == SOUTH
			|| c->map[k][i] == WEST || c->map[k][i] == EAST)
			{
				c->mov.pos_x = k + 0.5;
				c->mov.pos_y = i + 0.5;
				player_dir(c, k, i);
				c->map[k][i] = EMPTY;
				c->flag.player++;
			}
		}
	}
	if (!c->flag.player)
		exit_program(c, "Player not found\n", 1);
	if (c->flag.player > 1)
		exit_program(c, "Only one player allowed\n", 1);
}
