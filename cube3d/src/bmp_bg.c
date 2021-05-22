/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_bg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:10:49 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/22 20:04:48 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	write_data(t_cube *cube, int fd, int bytes)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					y;
	int					x;
	int					color;

	y = cube->win.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < cube->win.width)
		{
			color = cube->win.dir[cube->win.width * y + x];
			if (write(fd, &color, 3) < 0)
				return (0);
			if (bytes > 0 && write(fd, &zero, bytes) < 0)
				return (0);
			x++;
		}
		y--;
	}
	return (1);
}

/*
** Web archive this for more info on bmp files:
** http://www.fortunecity.com/skyscraper/windows/364/bmpffrmt.html
** Holy bollocks how can anyone enjoy this file format.
*/
static int	write_header(t_cube *cube, int fd, int filesize)
{
	int				i;
	unsigned char	bmpfileheader[54];

	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	ft_memcpy(bmpfileheader, "BM", 2);
	bmpfileheader[2] = filesize % BYTE;
	bmpfileheader[3] = (filesize >> 8) % BYTE;
	bmpfileheader[4] = (filesize >> 16) % BYTE;
	bmpfileheader[5] = (filesize >> 24) % BYTE;
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	bmpfileheader[18] = cube->render.x % BYTE;
	bmpfileheader[19] = (cube->render.x >> 8) % BYTE;
	bmpfileheader[20] = (cube->render.x >> 16) % BYTE;
	bmpfileheader[21] = (cube->render.x >> 24) % BYTE;
	bmpfileheader[22] = cube->render.y % BYTE;
	bmpfileheader[23] = (cube->render.y >> 8) % BYTE;
	bmpfileheader[24] = (cube->render.y >> 16) % BYTE;
	bmpfileheader[25] = (cube->render.y >> 24) % BYTE;
	bmpfileheader[26] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

static int	write_file(t_cube *cube, int fd, int filesize, int bytes)
{
	if (!write_header(cube, fd, filesize))
	{
		close(fd);
		exit_program(cube, "Couldn't create BMP header", -15);
		return (0);
	}
	if (!write_data(cube, fd, bytes))
	{
		close(fd);
		exit_program(cube, "Couldn't write BMP data", -16);
		return (0);
	}
	return (1);
}

/*
** So apparently we need 54 bytes to do the bmp fd header.
*/
int	save_bg(t_cube *cube)
{
	int	filesize;
	int	fd;
	int	bytes;
	int	flags;

	cube->bg = 1;
	flags = O_CREAT | O_WRONLY | O_TRUNC | O_APPEND;
	init_mlx_func(cube);
	draw(cube);
	bytes = (4 - (cube->win.width * 3) % 4) % 4;
	filesize = 54 + (3 * (cube->win.width + bytes) * cube->win.height);
	fd = open("screenshot.bmp", flags, 0644);
	if (fd < 0)
	{
		exit_program(cube, "Screenshot could not be opened\n", -14);
		return (0);
	}
	write_file(cube, fd, filesize, bytes);
	close(fd);
	exit_success(cube);
	return (1);
}
