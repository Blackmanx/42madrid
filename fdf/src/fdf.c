/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:12:53 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/09 22:16:07 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	main_fdf(t_fdf *fdf)
{

}

int	main(int argc, char *argv[])
{
	t_fdf	fdf;
	char	*file_path;

	if (argc != 2)
		fd_error("Error", "Invalid arguments");
	file_path = argv[1];
	fdf.map = initialise_map(file_path);
	alloc_map(fdf.map);
	parse_file(fdf.map, file_path);
	get_min_max_z(fdf.map);
	return (0);
}
