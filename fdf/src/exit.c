/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:04:22 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/28 15:23:06 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_map(t_fdf *fdf)
{
	int	i;

	i = fdf->rows - 1;
	if (fdf->map)
	{
		while (i >= 0)
		{
			free(fdf->map[i]);
			fdf->map[i] = NULL;
			i--;
		}
		free(fdf->map);
		fdf->map = NULL;
	}
}

/*
** * DESCRIPTION
** Exit the window properly.
** * @param fdf
** fdf: Fdf struct
** * RETURN VALUE
** None
*/

int	close_window(t_fdf *fdf)
{
	if (fdf != NULL)
	{
		if (fdf->img.img)
			mlx_destroy_image(fdf->lib.mlx, fdf->img.img);
		if (fdf->lib.win && fdf->lib.mlx)
			mlx_destroy_window(fdf->lib.mlx, fdf->lib.win);
		if (fdf->map)
			free_map(fdf);
		if (fdf->line)
			free(fdf->line);
		if (fdf->read.l)
			free(fdf->read.l);
		if (fdf->read.b)
			free(fdf->read.b);
	}
	exit(EXIT_SUCCESS);
	return (0);
}

/*
** * DESCRIPTION
** Exit the window properly when pressing ESC.
** * @param int key, t_fdf fdf
** fdf: Fdf struct
** key: int which sends key ID
** * RETURN VALUE
** None
*/

int	key_press(int key, t_fdf *fdf)
{
	if (key == (int)KEY_ESC)
		close_window(fdf);
	return (1);
}

/*
** * DESCRIPTION
** Whenever an error happens, use this function to print out an error and exit
** with an error code.
** * @param myParam
** Description of params
** * RETURN VALUE
** Explain what do you return
*/

void	exit_error(char *error, int errcode)
{
	printf("%s, ERR_CODE: %d \n", error, errcode);
	exit(errcode);
}
