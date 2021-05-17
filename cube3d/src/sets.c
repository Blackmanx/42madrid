/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 21:01:37 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/17 18:47:52 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static	void	set_file(t_cube *cube)
{
	cube->render.x = 0;
	cube->render.y = 0;
	cube->tex.n = NULL;
	cube->tex.s = NULL;
	cube->tex.e = NULL;
	cube->tex.w = NULL;
	cube->tex.sp = NULL;
	cube->map = NULL;
	cube->l = NULL;
	cube->spr_pos = NULL;
	cube->bg = NULL;
	cube->read.b = NULL;
	cube->read.l = NULL;
	cube->read.stc = NULL;
	ft_bzero(cube->colors.rgb_s, 3);
	ft_bzero(cube->colors.rgb_f, 3);
}

static	void	set_mov(t_cube cube)
