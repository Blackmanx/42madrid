/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:52:45 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 21:20:23 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	get_spr_n(t_cube *c)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	x = 0;
	while (c->map[x])
	{
		y = 0;
		while (c->map[x][y])
		{
			if (c->map[x][y] == OBJECT)
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

static void	check_argc(t_cube *cube, int n, char *str)
{
	if (n < 2 || n > 3)
		exit_program(cube, "Invalid number of arguments\n", 1);
	if (n == 3 && !ft_strncmp(str, "--save", 6) && str[6] <= ' ')
		cube->dt = 1;
	else if (n == 3)
		exit_program(cube, "Invalid save argument\n", 1);
}

int	main(int argc, char *argv[])
{
	t_cube	cube;

	set_struct(&cube);
	check_argc(&cube, argc, argv[2]);
	check_ext(argv[1]);
	read_map(argv[1], &cube);
	refill_map(&cube);
	check_wall(&cube);
	search_player(&cube);
	find_spr(&cube);
	if (cube.dt)
		save_dt(&cube);
	lib_start(&cube);
	mlx_hook(cube.lib.mlx_win, 2, 1, key_press, &cube);
	mlx_hook(cube.lib.mlx_win, 3, 2, key_release, &cube);
	mlx_hook(cube.lib.mlx_win, 33, 0, exit_success, &cube);
	mlx_loop_hook(cube.lib.mlx, set_window, &cube);
	mlx_loop(cube.lib.mlx);
	return (0);
}
