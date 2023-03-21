/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:16:43 by prodrigo          #+#    #+#             */
/*   Updated: 2023/03/21 19:33:15 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	key_press(int key, t_fdf *fdf)
{
	if (key == (int)KEY_W)
		fdf->mov.up = 1;
	else if (key == (int)KEY_A)
		fdf->mov.left = 1;
	else if (key == (int)KEY_S)
		fdf->mov.down = 1;
	else if (key == (int)KEY_D)
		fdf->mov.right = 1;
	else if (key == (int)KEY_RIGHT)
		fdf->view.right = 1;
	else if (key == (int)KEY_LEFT)
		fdf->view.left = 1;
	else if (key == (int)KEY_ESCAPE)
		exit_success(fdf);
	return (1);
}

int	key_release(int key, t_fdf *fdf)
{
	if (key == (int)KEY_W)
		fdf->mov.up = 0;
	else if (key == (int)KEY_A)
		fdf->mov.left = 0;
	else if (key == (int)KEY_S)
		fdf->mov.down = 0;
	else if (key == (int)KEY_D)
		fdf->mov.right = 0;
	else if (key == (int)KEY_RIGHT)
		fdf->view.right = 0;
	else if (key == (int)KEY_LEFT)
		fdf->view.left = 0;
	else if (key == (int)KEY_ESCAPE)
		close_window(fdf);
	return (1);
}
