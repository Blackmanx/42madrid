/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:12:53 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/27 20:37:18 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	create_img(t_fdf *fdf)
{
	t_coord	spot;

	spot.y = 0;
	while (spot.y < fdf->rows)
	{
		spot.x = 0;
		while (spot.x < fdf->cols)
		{
			fdf->color = set_color(fdf, spot.x, spot.y);
			if (spot.x < fdf->cols - 1)
				draw_line(fdf, spot, spot.x + 1, spot.y);
			if (spot.y < fdf->rows - 1)
				draw_line(fdf, spot, spot.x, spot.y + 1);
			spot.x++;
		}
		spot.y++;
	}
	mlx_put_image_to_window(fdf->lib.mlx, fdf->lib.win, fdf->img.img, 0, 0);
	return (1);
}

/*
** * DESCRIPTION
** Checks if name of file submitted complies with our rules.
** * @param char *filename
** filename: First argument of main program. Name of file submitted.
** * RETURN VALUE
** None. Can exit program with error if extension isn't valid.
*/

void	check_type(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (ft_strncmp(&filename[len - 4], ".fdf", 4) != 0)
		exit_error("Error: Wrong file extension", BAD_FILE);
}

/*
** * DESCRIPTION
** Main function
** * @param myParam
** argc : Number of args
** argv : args themselves as string.
** * RETURN VALUE
** Exit code (int)
*/

int	main(int argc, char *argv[])
{
	t_fdf	fdf;

	if (argc != 2)
		exit_error("Error: Invalid arguments", INVALID_ARGS);
	check_type(argv[1]);
	declare_data(&fdf);
	read_map(&fdf, argv[1]);
	view_init(&fdf);
	init_fdf(&fdf);
	mlx_hook(fdf.lib.win, 2, 1, key_press, &fdf);
	mlx_hook(fdf.lib.win, 17, (1U << 17), close_window, &fdf);
	create_img(&fdf);
	mlx_loop(fdf.lib.mlx);
	return (0);
}
