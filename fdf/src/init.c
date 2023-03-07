/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:24:27 by prodrigo          #+#    #+#             */
/*   Updated: 2022/09/28 17:33:25 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	close_window(t_lib *lib)
{
	exit(1);
	lib = NULL;
}

void	init_fdf(char **argv, t_lib *lib)
{
	argv = NULL;
	lib->mlx = mlx_init();
	lib->win = mlx_new_window(lib->mlx, 1920, 1080, "Amog Us 2!");
	mlx_hook(lib->win, 17, 0L, close_window, &lib);
}
