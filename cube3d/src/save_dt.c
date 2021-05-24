/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_dt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:01:13 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 21:01:14 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	write_bmp_header(t_cube *c, int fd, int filesize)
{
	int				i;
	unsigned char	bmpfileheader[BMP_HEADER_BYTES];

	i = 0;
	while (i < BMP_HEADER_BYTES)
		bmpfileheader[i++] = (unsigned char)(0);
	ft_memcpy(bmpfileheader, "BM", 2);
	bmpfileheader[2] = filesize % BYTE;
	bmpfileheader[3] = (filesize >> 8) % BYTE;
	bmpfileheader[4] = (filesize >> 16) % BYTE;
	bmpfileheader[5] = (filesize >> 24) % BYTE;
	bmpfileheader[10] = (unsigned char)(DATA);
	bmpfileheader[14] = (unsigned char)(BMP_HEADER_SIZE);
	bmpfileheader[18] = c->render.x % BYTE;
	bmpfileheader[19] = (c->render.x >> 8) % BYTE;
	bmpfileheader[20] = (c->render.x >> 16) % BYTE;
	bmpfileheader[21] = (c->render.x >> 24) % BYTE;
	bmpfileheader[22] = c->render.y % BYTE;
	bmpfileheader[23] = (c->render.y >> 8) % BYTE;
	bmpfileheader[24] = (c->render.y >> 16) % BYTE;
	bmpfileheader[25] = (c->render.y >> 24) % BYTE;
	bmpfileheader[26] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(H_RES);
	return (!(write(fd, bmpfileheader, BMP_HEADER_BYTES) < 0));
}

static int	write_bmp_data(t_cube *c, int file, int pad)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					y;
	int					x;
	int					col;

	y = c->win.h - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < c->win.w)
		{
			col = c->win.data[c->win.w * y + x];
			if (write(file, &col, 3) < 0)
				return (0);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (0);
			x++;
		}
		y--;
	}
	return (1);
}

static int	write_bmp(t_cube *c, int fd, int filesize, int pad)
{
	if (!write_bmp_header(c, fd, filesize))
	{
		close(fd);
		exit_program(c, "The BMP header could not be create\n", 1);
		return (0);
	}
	if (!write_bmp_data(c, fd, pad))
	{
		close(fd);
		exit_program(c, "The BMP data could not be written\n", 1);
		return (0);
	}
	return (1);
}

int	save_dt(t_cube *c)
{
	int	filesize;
	int	file;
	int	pad;
	int	flags;

	c->dt = 1;
	flags = O_CREAT | O_WRONLY | O_TRUNC | O_APPEND;
	lib_start(c);
	set_window(c);
	pad = (4 - (c->win.w * 3) % 4) % 4;
	filesize = BMP_HEADER_BYTES + (3 * (c->win.w + pad) * c->win.h);
	file = open("screenshot.bmp", flags, 0644);
	if (file < 0)
	{
		exit_program(c, "Screenshot could not be opened\n", 1);
		return (0);
	}
	write_bmp(c, file, filesize, pad);
	close(file);
	exit_success(c);
	return (1);
}
