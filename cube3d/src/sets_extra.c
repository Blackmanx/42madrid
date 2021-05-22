/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:57:46 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/22 19:07:24 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	set_sprites(t_cube *cube)
{
	cube->spr.img = NULL;
	cube->spr.dir = NULL;
	cube->spr.width = 0;
	cube->spr.height = 0;
	cube->spr.bpp = 0;
	cube->spr.sz = 0;
	cube->spr.endian = 0;
	cube->spr.x = 0.0;
	cube->spr.y = 0.0;
	cube->spr.beg_x = 0;
	cube->spr.beg_y = 0;
	cube->spr.end_x = 0;
	cube->spr.end_y = 0;
	cube->spr.h = 0;
	cube->spr.w = 0;
	cube->spr.screen = 0;
	cube->spr.rgb = 0;
	cube->spr.buf = NULL;
}
