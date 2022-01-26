/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:15:00 by prodrigo          #+#    #+#             */
/*   Updated: 2022/01/26 18:17:42 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./colors.h"
# include "../lib-Linux/mlx.h"
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
# define HEIGHT					1920
# define WIDTH					1080
# define X						0
# define Y						1
# define Z						2
# define SHIFT					10
# define ROT					0.1
# define ZOOM					0.5

typedef struct s_ren {
	int			x;
	int			y;
}				t_ren;

typedef struct s_pnt {
	int			x;
	int			y;
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
	char		*addr;
	int			h;
	int			w;
	int			sz;
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
}	t_vars;

typedef struct s_read {
	char		*buf;
	char		*b;
	char		*l;

}	t_read;

typedef struct s_fdf {
	int			rows;
	int			cols;
	char		*line;
	int			**map;
	int			color;
	int			zoom;
	int			mov;
}	t_fdf;

// memory.c
void	free_tab(char **tab);
void	free_fdf(t_fdf *fdf);
void	free_win(t_fdf *fdf);
void	free_map(t_map *map);
void	alloc_map(t_fdf *fdf);

// data.c
void	fill_z_col(t_map *map, int fd);
void	set_peaks(t_map *map);

// error.c

// map.c
// static int	count_file_nbr(t_map *map, char *l)
void	get_min_max_z(t_map *map);
void	maplloc(t_map *map);
t_map	*init_map(char *f_path);
void	map_error(t_map *map, char *str);

// parsers.c
void	parse_file(t_map *map, char *f_path);
int		parse_color(t_map *map, char *str);

#endif
