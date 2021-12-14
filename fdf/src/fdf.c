/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:12:53 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/14 17:42:38 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char *argv[])
{
	t_fdf	fdf;
	char	*file_path;

	if (argc != 2)
		fd_error("Error: Invalid arguments");
	file_path = argv[1];
	fdf.map = init_map(file_path);
	maplloc(fdf.map);
	parse_file(fdf.map, file_path);
	set_peaks(fdf.map);
	mlx_main(fdf.map);
	return (0);
}
