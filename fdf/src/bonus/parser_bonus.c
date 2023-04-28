/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:50:26 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/28 15:35:11 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"


static int	arr_getlen(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (-1);
	while (arr[i])
		i++;
	return (i);
}

static int	free_buf(t_fdf *fdf)
{
	int	i;

	i = fdf->cols - 1;
	if (!fdf->read.buf)
		return (-1);
	while (i >= 0)
	{
		free(fdf->read.buf[i]);
		fdf->read.buf[i] = NULL;
		i--;
	}
	free(fdf->read.buf);
	fdf->read.buf = NULL;
	return (0);
}

static void	fill_map(char *line, int *map, t_fdf *fdf)
{
	int		i;

	i = -1;
	ft_split_fdf(line, ' ', fdf);
	while (fdf->read.buf[++i])
		map[i] = ft_atoi(fdf->read.buf[i]);
	free_buf(fdf);
}

static void	parse_dim(t_fdf *fdf, char *argv)
{
	int		fd;

	fdf->rows = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit_error("Fdf file could not be opened", FILE_OPEN);
	while (get_next_line(fd, &fdf->line, &fdf->read.b, &fdf->read.l))
	{
		ft_split_fdf(fdf->line, ' ', fdf);
		fdf->cols = arr_getlen(fdf->read.buf);
		fdf->rows++;
		free_buf(fdf);
		free(fdf->line);
		fdf->line = NULL;
	}
	free(fdf->line);
	fdf->line = NULL;
	close(fd);
	if (fdf->rows == 0 || fdf->cols == 0)
		exit_error("Fdf file could not be opened", INVALID_MAP);
}

void	read_map(t_fdf *fdf, char *argv)
{
	int	i;
	int	fd;

	parse_dim(fdf, argv);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit_error("Fdf file could not be opened", FILE_OPEN);
	fdf->map = (int **)malloc(sizeof(int *) * fdf->rows);
	i = -1;
	while (++i < fdf->rows)
		fdf->map[i] = (int *)malloc(sizeof(int) * fdf->cols);
	i = 0;
	while (get_next_line(fd, &fdf->line, &fdf->read.b,
			&fdf->read.l) > 0)
	{
		fill_map(fdf->line, fdf->map[i++], fdf);
		free(fdf->line);
		fdf->line = NULL;
	}
	close(fd);
}
