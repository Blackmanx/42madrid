/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:14:24 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/12 20:05:12 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	parse_file(t_map *map, char *f_path)
{
	int		fd;

	fd = open(f_path, O_RDONLY);
	if (fd < 0)
		fd_error_fd("Error while parsing file", -42);
	fill_z_col(map, fd);
	close(fd);
}

int	parse_color(t_map *map, char *str)
{
	while (*str && (ft_isdigit(*str) || *str == '-'
			||*str == '+' || *str == ','))
		str++;
	if (*str && *str == 'x')
	{
		map->col_f = 1;
		ft_striter(str + 1, ft_tolower);
		return (ft_atoi_base(str + 1, "0123456789abcdef"));
	}
	else
		return (WHITE);
	return (0);
}
