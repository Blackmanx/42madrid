/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 21:01:37 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/12 21:01:37 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static	void	set_file(t_cube *cube)
{
	cube->res.x = 0;
	cube->res.y = 0;
	cube->tex.n = NULL;
	cube->tex.s = NULL;
	cube->tex.e = NULL;
	cube->tex.w = NULL;
	cube->tex.sp = NULL;
	cube->map = NULL;
	cube->line = NULL;
	cube->spr_pos = NULL;
	cube->bg = NULL;
	cube->r.b = NULL;
	cube->r.l = NULL;
	cube->r.stc = NULL;
	ft_bzero(cube->rgb.rgb_s, 3);
	ft_bzero(cube->rgb.rgb_f, 3);
}

static	void	set_mov(t_cube cube)
