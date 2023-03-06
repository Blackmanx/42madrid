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

void	init_fdf(char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;

	argv = NULL;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 600, 300, "My first window!");
	write(1, "amogus", 7);
	mlx_clear_window(mlx_ptr, win_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	free(mlx_ptr);
}
