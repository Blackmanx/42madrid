/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:50:26 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/05 17:38:04 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	fill_map(char *line, int *map, t_fdf *fdf)
{
	int		i;

	i = 0;
	ft_split(line, ' ', fdf);
	while (fdf->read.buf[i])
	{
		map[i] = ft_atoi(fdf->read.buf[i]);
		i++;
	}
	free(fdf->read.buf);
}

int	read_map(t_fdf *fdf, char *argv)
{
	int	i;
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_error("Fdf file could not be opened\n", FILE_OPEN);
	fdf->map = (int **)malloc(sizeof(int *) * fdf->rows);
	i = -1;
	while (++i < fdf->rows)
		fdf->map[i] = (int *)malloc(sizeof(int) * fdf->cols);
	i = 0;
	while (get_next_line(fd, &map->line, &map->read.b, &map->read.l) > 0)
	{
		fill_map(fdf->line, fdf->map[i++], fdf);
		free(fdf->line);
		fdf->line = NULL;
	}
	return (0);
}
