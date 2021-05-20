/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:57:06 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/20 21:57:09 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	exit_program(t_cube *cube, char *str, int error)
{
	int	strlen;

	strlen = ft_strlen(str);
	if (error)
		write(1, "Error\n", 6);
	if (!str)
		perror("");
	else
		write(1, str, strlen);
	if (cube != NULL)
	{
		if (cube->lib.mlx_win)
			mlx_destroy_window(cube->lib.mlx, cube->lib.mlx_win);
		if (cube->win.img)
			mlx_destroy_image(cube->lib.mlx, cube->win.img);
		free_textures(cube);
		if (cube->l != NULL)
			free(cube->l);
		if (cube->spr_pos)
			free(cube->spr_pos);
		if (cube->read.l)
			free(cube->read.l);
	}
	exit(error);
}
