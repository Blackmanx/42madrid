/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:12:53 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/28 15:06:49 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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
