/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:29:21 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/22 20:24:38 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static	void	check_argc(t_cube *cube, int i, char *str)
{
	int	flag;

	flag = 1;
	if (i < 2)
		clean_exit(cube, -1);
	if (i > 3)
		clean_exit(cube, -2);
	if (i == 3 && flag == 0 && str[6] <= EMPTY_SPACE)
		cube->bg = 1;
	else if (i == 3)
		clean_exit(cube, -3);
}

int	main(int argc, char *argv[])
{
	t_cube	cube;

	init_struct(&cube);
	check_argc(&cube, argc, argv[2]);
	check_extension(argv[1]);
	get_map(&cube, argv[1]);
	fill_map(&cube);
	check_walls(&cube);
	get_player(&cube);
	set_spr(&cube);
	if (cube.bg)
		save_bg(&cube);
	start_lib(&cube);
	mlx_hook(cube.lib.mlx_win, 2, 1, key_press, &cube);
	mlx_hook(cube.lib.mlx_win, 3, 2, key_release, &cube);
	mlx_hook(cube.lib.mlx_win, 17, (1U << 17), exit_success, &cube);
	mlx_loop_hook(cube.lib.mlx, img_draw, &cube);
	mlx_loop(cube.lib.mlx);
}
