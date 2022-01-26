/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:12:53 by prodrigo          #+#    #+#             */
/*   Updated: 2022/01/11 17:32:22 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/* init_map, maplloc -> map.c */
/* parse_file -> parsers.c	  */
/* set_peaks -> data.c 		  */

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;
	char	*file_path;

	if (argc != 2)
		fd_error("Error: Invalid arguments");
	fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	if (!fdf)
		fd_error_fd("Malloc error", -42);
	file_path = argv[1];
	fdf->map = init_map(file_path);
	maplloc(fdf->map);
	parse_file(fdf->map, file_path);
	set_peaks(fdf->map);
	mlib_init(fdf->map);
	return (0);
}
