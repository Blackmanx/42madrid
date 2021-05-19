/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:29:21 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/17 16:25:01 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static	void	check_argc(t_cube *cube, int i, char *str)
{
	int	flag;

	flag = 1;
	if (i < 2)
		clean_exit(cube, "Not enough arguments");
	if (i > 3)
		clean_exit(cube, "Too many arguments");
	if (i == 3 && flag == 0 && str[6] <= EMPTY_SPACE)
		cube->bg = 1;
	else if (i == 3)
		clean_exit(cube, "Invalid save");
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
	search_player(&cube);
	search_spr(&cube);
	if (cube.bg)
		save_bg(&cube);
	init_mlx(&cube);
	mlx_hook(cube.lib.mlx_win, 2, 1, key_press_handler, &cube);
	mlx_hook(cube.lib.mlx_win, 3, 2, key_release_handler, &cube);
	mlx_hook(cube.lib.mlx_win, 17, (1U << 17), exit_handler, &cube);
	mlx_loop_hook();
	mlx_loop(cube.lib.mlx);
}
