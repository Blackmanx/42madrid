/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:12:53 by prodrigo          #+#    #+#             */
/*   Updated: 2021/11/23 13:18:51 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	check_argc(t_fdf *fdf, int argc, char *str)
{
	if (argc < 2 || argc > 3)
		exit_program(fdf, "Invalid number of arguments\n", 1);
	if (argc == 3 && !ft_strncmp(str, "--save", 6) && str[6] <= ' ')
		fdf->dt = 1;
	else if (argc == 3)
		exit_program(fdf, "Invalid save argument\n", 1);
}

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	set_struct(&fdf);
	check_argc(&fdf, argc, argv[2]);

	mlx_hook(fdf.lib.mlx_win, 2, 1, key_press, &fdf);
	mlx_hook(fdf.lib.mlx_win, 3, 2, key_release, &fdf);
	mlx_hook(fdf.lib.mlx_win, 33, 0, exit_success, &fdf);
	mlx_loop_hook(fdf.lib.mlx, set_window, &fdf);
	mlx_loop(fdf.lib.mlx);
	return (0);
}
