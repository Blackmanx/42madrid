/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:10:26 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/20 21:26:58 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	read_

void	init_mlx(t_cube *cube)
{
	cube->lib.mlx = mlx_init();
	if (!cube->lib.mlx)
		exit_program(cube, -8);
}
