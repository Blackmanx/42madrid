/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:15:00 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/28 04:29:37 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./colors.h"
# include "./errors.h"
# include "../mlx/mlx.h"
# include "./keycodes.h"
# include "../src/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <limits.h>
# include "fdf_structs.h"

# define MAX_SIZE				20
# define GRAY					8355711
# define PI						3.14159265359
# define MAX_HEIGHT				5120
# define MAX_WIDTH				2880
# define X						0
# define Y						1
# define Z						2
# define SHIFT					10
# define ROT					0.1
# define ZOOM					3
# define WINDOW_W				1920
# define WINDOW_H				1080
# define ISO					1
# define PLANE					0
# define PERSPECTIVE			0.53
# define ANGLE					0.1
# define OBLIQUE				0
# define TRUE					1
# define FALSE					0
# define BUFFER_SIZE			32

// TODO: Include functions

// map/parser.c
void	parse_map(t_fdf *fdf, int *flag, char *line);

// init.c
void	declare_data(t_fdf *fdf);
void	init_fdf(t_fdf *fdf);

// exit.c
int		close_window(t_fdf *fdf);
void	exit_error(char *error, int errcode);
int		key_press(int key, t_fdf *fdf);

// draw.c
int		set_color(t_fdf *fdf, int x, int y);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);

// key_handling.c
int		key_press(int key, t_fdf *fdf);
int		key_release(int key, t_fdf *fdf);

// line.c
void	vector_descend(t_fdf *fdf, t_coord a1, t_coord a2);
void	vector_ascend(t_fdf *fdf, t_coord a1, t_coord a2);
void	draw_line(t_fdf *fdf, t_coord a1, int x1, int y1);

// parser.c
void	read_map(t_fdf *fdf, char *argv);

// view.c
void	zoom_view(t_fdf *fdf, t_coord *a1, t_coord *a2, int z[2]);
void	position_view(t_fdf *fdf, t_coord *a1, t_coord *a2);
void	view_init(t_fdf *fdf);

#endif
