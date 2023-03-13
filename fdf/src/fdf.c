/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:12:53 by prodrigo          #+#    #+#             */
/*   Updated: 2023/03/13 22:02:12 by prodrigo         ###   ########.fr       */
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
	t_fdf	*fdf;

	if (argc != 2)
		exit_error("Error: Invalid arguments", INVALID_ARGS);
	check_type(argv[1]);
	fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	if (!fdf)
		exit_error("Error: Malloc failed", BAD_ALLOC);
	init_fdf(argv, fdf);
	mlx_loop(fdf->lib.mlx);
	return (0);
}
