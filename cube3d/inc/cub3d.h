/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:39:21 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 19:58:58 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib-Linux/mlx.h"
# include "keycodes.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "utils.h"

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

typedef struct s_cub {
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
}				t_cube;

void			info_tex(char *line, t_cube *cube);
void			info_res(char *line, t_cube *cube);
void			info_color(char *line, t_cube *cube);
char			*info_map(char *line, char *stc, t_cube *cube);
void			search_player(t_cube *c);
void			set_struct(t_cube *cube);
void			lib_start(t_cube *c);
void			read_map(char *filename, t_cube *cube);
int				key_press(int key, t_cube *c);
int				key_release(int key, t_cube *c);
int				exit_success(t_cube *c);
void			exit_program(t_cube *c, char *str, int error);
int				paint_game(t_cube *c);
void			step_initial_side(t_cube *c);
int				move(t_cube *c, double speed);
int				rotate(t_cube *c, double speed);
int				raycaster(t_cube *c, int x);
void			set_sprites(t_cube *c);
void			set_raycast(t_cube *cube);
void			free_map(t_cube *c);
void			refill_map(t_cube *c);
int				set_window(t_cube *c);
void			spr_window(t_cube *c);
void			find_spr(t_cube *c);
void			my_mlx_pixel_put(t_cube *c, int x, int y, int col);
int				save_dt(t_cube *c);
void			check_ext(char *filename);
int				check_res(char *num);
int				check_text(t_cube *c, char *text);
void			cb_trim(t_cube *c, char **line);
int				check_ids(t_cube *c);
int				is_texture(char *line);
int				err_tex(char *line);
int				err_res(char *line);
void			err_rgb(t_cube *cube, char *s);
void			check_wall(t_cube *c);
int				get_map_dim(t_cube *c);
int				get_spr_n(t_cube *c);
void			cb_split(char **s, char z, t_cube *c);
int				ft_isspace(char c);
int				get_tex(t_cube *c);
void			handle_img(t_cube *c);
void			exit_str(t_cube *c, char *txt, char *str);
void			check_open_tex(t_cube *c);
int				is_char_valid(char c);
int				empty_line(char *line);
int				check_bad_end(t_cube *c);

#endif
