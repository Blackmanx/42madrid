/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:15:00 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/05 11:58:52 by prodrigo         ###   ########.fr       */
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

# define MAX_SIZE			20
# define GRAY				8355711
# define PI					3.14159265359
# define MAX_HEIGHT					2880
# define MAX_WIDTH					5120
# define X						0
# define Y						1
# define Z						2
# define SHIFT					10
# define ROT					0.1
# define ZOOM					3
# define WINDOW_W				1920
# define WINDOW_H				1080
# define TRUE					1
# define FALSE					0
# define BUFFER_SIZE				32

typedef struct s_scr {
	int			x;
	int			y;
}				t_scr;

typedef struct s_view {
	float		pangle;
	float		angle;
	int			x;
	int			y;
	int			zoom;
	int			iso;
	int			obl;
	int			plane;
	int			rot[3];
}				t_view;

typedef struct s_lib {
	void		*mlx;
	void		*win;
}				t_lib;

typedef struct s_img {
	int			*img;
	char		*addr;
	int			h;
	int			w;
	int			sz;
	int			len;
	int			endian;
	int			bpp;
}				t_img;

typedef struct s_vars {
	int				x;
	int				y;
	int				d;
	int				dy;
	int				dx;
	int				xi;
	int				yi;
}				t_vars;

typedef struct s_read {
	char		**buf;
	char		*b;
	char		*l;

}				t_read;

typedef struct s_fdf {
	int			rows;
	int			cols;
	char		*line;
	int			**map;
	int			color;
	int			zoom;
	int			mov;
	t_read		read;
	t_img		img;
	t_view		view;
	t_vars		vars;
	t_lib		lib;
	t_scr		scr;
}				t_fdf;
// TODO: Include functions

// map/parser.c
void	parse_map(t_fdf *fdf, int *flag, char *line);

// init.c
void	init_fdf(t_fdf *fdf);

// exit.c
int		close_window(t_fdf *fdf);
void	exit_error(char *error, int errcode);

// draw.c
void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);

// key_handling.c
int		key_press(int key, t_fdf *fdf);
int		key_release(int key, t_fdf *fdf);

// parser.c
int		read_map(t_fdf *fdf, char *argv);
#endif
