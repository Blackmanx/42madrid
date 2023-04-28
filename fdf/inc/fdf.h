/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:15:00 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/28 18:19:00 by prodrigo         ###   ########.fr       */
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
# define X						0
# define Y						1
# define Z						2
# define SHIFT					10
# define ROT					0.1
# define ZOOM					8
# define WINDOW_W				1920
# define WINDOW_H				1080
# define ISO					1
# define ISO0					0
# define PLANE					0
# define PLANE_ALT				1
# define PERSPECTIVE			0.53
# define PERSPECTIVE_ALT		0.2
# define ANGLE					0.1
# define OBLIQUE				0
# define OBLIQUE1				1
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
void	regen_img(t_fdf *fdf);
int		set_color(t_fdf *fdf, int x, int y);
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
int		create_img(t_fdf *fdf);

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

// bonus
void	rotate(int *x, int *y, int *z, t_fdf *fdf);
void	hooks_perspective(t_fdf *fdf, int key);
int		zoom_bonus(t_fdf *fdf, int key, int x, int y);
void	cam_mov(t_fdf *fdf, int key);

#endif
