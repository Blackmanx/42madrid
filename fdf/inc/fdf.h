/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:15:00 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/09 23:42:27 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./colors.h"
# include "../lib-Linux/mlx.h"
# include "./keycodes.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# define MAX_SIZE			20
# define GRAY				8355711
# define PI					3.14159265359
# define HEIGHT					1920
# define WIDTH					1080
# define X						0
# define Y						1
# define Z						2
# define SHIFT					10
# define ROT					0.1
# define ZOOM					0.5

typedef struct s_pnt {
	int			axis[3];
	int			color;
}				t_pnt;

typedef struct s_rgb {
	float		rgb[3];
}				t_rgb;

typedef struct s_lib {
	void		*mlx;
	void		*win;
}				t_lib;

typedef struct s_img {
	int			*img;
	char		*data;
	int			len;
	int			endian;
	int			bpp;
}				t_img;

typedef struct s_map {
	int			w;
	int			h;
	int			**z;
	int			**col;
	int			col_f;
	int			z_min;
	int			z_max;
}	t_map;

typedef struct s_view {
	int		shift[2];
	int		iso;
	int		rot[3];
	float	zoom;
	float	flat;
}	t_view;

typedef struct s_fdf {
	t_view		view;
	t_map		*map;
	t_pnt		axis;
	t_rgb		rgb;
	t_lib		lib;
	t_img		*img;
}	t_fdf;

// utils.c
void	free_split(char **split);
void	free_fdf(t_fdf *fdf);
void	free_all(t_fdf *fdf);
t_pnt	new_point(int x, int y, t_fdf *fdf);
t_pnt	get_coords(t_fdf *fdf, t_pnt point);

// error.c
void	err_exit(const char *err, const char *msg);
void	perror_exit(const char *str);

// map_utils.c
void	get_min_max_z(t_map *map);
void	free_map(t_fdf *fdf);
void	alloc_map(t_fdf *fdf);
t_map	*initialise_map(char *file);

// handle_args.c
void	handle_args(t_map **map, int ac, char **av);

// mlx_main.c
int		mlx_main(t_map *map);

// mlx_hook.c
int		close_win(t_fdf *fdf);
int		key_hook(int keycode, t_fdf *fdf);

// mlx_loop.c
int		update(t_fdf *fdf);

// mlx_utils.c
void	reset_fdf(t_fdf *fdf);
int		initialise_fdf(t_fdf *fdf, t_map *map);
void	initialise_mlx(t_fdf *fdf);

// draw.c
void	draw(t_fdf *fdf);

// draw_utils.c
void	isometric(t_fdf *fdf, int *x, int *y, int z);
void	rot_x(t_fdf *fdf, int *y, int *z);
void	rot_y(t_fdf *fdf, int *x, int *z);
void	rot_z(t_fdf *fdf, int *x, int *y);
void	img_pixel_put(t_fdf *fdf, int x, int y, int color);

// controls.c
void	handle_zoom(int keycode, t_fdf *fdf);
void	handle_move(int keycode, t_fdf *fdf);
void	handle_rot(int keycode, t_fdf *fdf);
void	handle_flattening(int keycode, t_fdf *fdf);

// color.c
int		get_color(t_pnt current, t_pnt start, t_pnt end, t_pnt delta);
int		get_z_color(t_fdf *fdf, int cur_z);
#endif
