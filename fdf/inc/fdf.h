/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:15:00 by prodrigo          #+#    #+#             */
/*   Updated: 2021/11/23 13:17:49 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib-Linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

# define EMPTY				'0'
# define WALL				'1'
# define OBJECT				'2'
# define NORTH				'N'
# define SOUTH				'S'
# define WEST				'W'
# define EAST				'E'
# define N					1
# define S					0
# define E					3
# define W					2
# define MAX_LEN			10
# define TOTAL_IDS			8
# define TOTAL_INFO			9
# define CAM			32.5
# define P_SPEED			0.09
# define P_SUM_SP		0.03
# define GRAY				8355711
# define BYTE				256
# define BMP_HEADER_BYTES	54
# define DATA				54
# define BMP_HEADER_SIZE	40
# define H_RES				24

typedef struct s_render {
	int			x;
	int			y;
}				t_render;

typedef struct s_tex {
	char		*n;
	char		*s;
	char		*w;
	char		*e;
	char		*spr;
}				t_tex;

typedef struct s_rgb {
	int			rgb_s[3];
	int			rgb_f[3];
}				t_rgb;

typedef struct s_lib {
	void		*mlx;
	void		*mlx_win;
}				t_minilix;

typedef struct s_img {
	void		*img;
	int			*data;
	int			h;
	int			w;
	int			sz;
	int			endian;
	int			bpp;
}				t_img;

typedef struct s_spr {
	void		*img;
	int			*data;
	int			h;
	int			w;
	int			sz;
	int			endian;
	int			bpp;
	double		pos_x;
	double		pos_y;
	int			start_y;
	int			start_x;
	int			end_y;
	int			end_x;
	int			h2;
	int			w2;
	int			screen;
	double		*buf;
	int			col;
}				t_spr;

typedef struct s_spr_p {
	double		x;
	double		y;
	int			dist;
}				t_spr_p;

typedef struct s_mov {
	int			left;
	int			right;
	int			up;
	int			down;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			map_x;
	int			map_y;
}				t_mov;

typedef struct s_cam {
	int			left;
	int			right;
	double		x;
}				t_cam;

typedef struct s_raycasting {
	double		dir_x;
	double		dir_y;
	double		side_x;
	double		side_y;
	double		delta_x;
	double		delta_y;
	double		perp;
	int			step_x;
	int			step_y;
	double		step;
	int			roblox;
	int			side;
	int			lh;
	int			n_tex;
	int			x;
	int			y;
	double		pos;
}				t_ray;

typedef struct s_draw {
	int			start;
	int			end;
	double		x;
	double		y;
	int			trig;
}				t_draw;

typedef struct s_flag {
	int			res;
	int			tex_n;
	int			tex_s;
	int			tex_w;
	int			tex_e;
	int			tex_spr;
	int			sky;
	int			floor;
	int			map;
	int			player;
}				t_flag;

typedef struct s_read {
	char		*b;
	char		*l;
	char		*stc;
}				t_read;

typedef struct s_fdf {
	int			nrows;
	int			dt;
	char		*line;
	char		**map;
	t_render	render;
	t_tex		tex;
	t_rgb		col;
	t_minilix	lib;
	t_img		win;
	t_img		wall[4];
	t_spr		spr;
	t_spr_p		*spr_p;
	t_mov		mov;
	t_cam		view;
	t_ray		ray;
	t_draw		draw;
	t_flag		flag;
	t_read		r;
}				t_fdf;

void			info_tex(char *line, t_fdf *cube);
void			info_res(char *line, t_fdf *cube);
void			info_color(char *line, t_fdf *cube);
char			*info_map(char *line, char *stc, t_fdf *cube);
void			search_player(t_fdf *c);
void			set_struct(t_fdf *cube);
void			lib_start(t_fdf *c);
void			read_map(char *filename, t_fdf *cube);
int				key_press(int key, t_fdf *c);
int				key_release(int key, t_fdf *c);
int				exit_success(t_fdf *c);
void			exit_program(t_fdf *c, char *str, int error);
int				paint_game(t_fdf *c);
void			step_initial_side(t_fdf *c);
int				move(t_fdf *c, double speed);
int				rotate(t_fdf *c, double speed);
int				raycaster(t_fdf *c, int x);
void			set_sprites(t_fdf *c);
void			set_raycast(t_fdf *cube);
void			free_map(t_fdf *c);
void			refill_map(t_fdf *c);
int				set_window(t_fdf *c);
void			spr_window(t_fdf *c);
void			find_spr(t_fdf *c);
void			my_mlx_pixel_put(t_fdf *c, int x, int y, int col);
int				save_dt(t_fdf *c);
void			check_ext(char *filename);
int				check_res(char *num);
int				check_text(t_fdf *c, char *text);
void			cb_trim(t_fdf *c, char **line);
int				check_ids(t_fdf *c);
int				is_texture(char *line);
int				err_tex(char *line);
int				err_res(char *line);
void			err_rgb(t_fdf *cube, char *s);
void			check_wall(t_fdf *c);
int				get_map_dim(t_fdf *c);
int				get_spr_n(t_fdf *c);
void			cb_split(char **s, char z, t_fdf *c);
int				ft_isspace(char c);
int				get_tex(t_fdf *c);
void			handle_img(t_fdf *c);
void			exit_str(t_fdf *c, char *txt, char *str);
void			check_open_tex(t_fdf *c);
int				is_char_valid(char c);
int				empty_line(char *line);
int				check_bad_end(t_fdf *c);

#endif
