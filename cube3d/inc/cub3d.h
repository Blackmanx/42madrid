/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:44:16 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/17 18:00:34 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./inc/libft/libft.h"
# include "./lib/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/uio.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>

# define EMPTY_SPACE	' '
# define EMPTY	'0'
# define WALL	'1'
# define OBJECT	'2'
# define NORTH	'N'
# define WEST	'W'
# define SOUTH	'S'
# define EAST	'E'
# define BYTE	256

/*
**	Texture paths
*/
typedef struct s_tex
{
	char	*n;
	char	*s;
	char	*w;
	char	*e;
	char	*sp;
}	t_tex;

/*
** Render Coordinates
*/
typedef struct s_rend
{
	int	x;
	int	y;
}	t_rend;

typedef struct s_rgb
{
	int	rgb_s[3];
	int	rgb_f[3];
}	t_rgb;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	int		*dir;
	int		width;
	int		height;
	int		sz;
	int		endian;
	int		bpp;
}	t_img;

typedef struct s_spr
{
	void	*img;
	int		*dir;
	int		width;
	int		height;
	int		sz;
	int		endian;
	int		bpp;
	double	x;
	double	y;
	int		beg_x;
	int		beg_y;
	int		end_x;
	int		end_y;
	int		h;
	int		w;
	int		screen;
	int		rgb;
	double	*buf;

}	t_spr;

typedef struct s_sprpos
{
	double	x;
	double	y;
	int		len;
}	t_sprpos;

typedef struct s_mov
{
	int		map_x;
	int		map_y;
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		up;
	int		down;
	int		left;
	int		right;
}	t_mov;

typedef struct s_view
{
	int		left;
	int		right;
	double	x;
}	t_view;

typedef struct s_draw
{
	double	x;
	double	y;
	int		start;
	int		end;
	int		draw;
}	t_draw;

typedef struct s_flag
{
	int	res;
	int	map;
	int	floor;
	int	roof;
	int	player;
	int	tex_n;
	int	tex_w;
	int	tex_s;
	int	tex_e;
	int	tex_sp;
}	t_flag;

typedef struct s_ray
{
	int		x;
	int		y;
	double	pos;
	double	dir_x;
	double	dir_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	view;
	double	step;
	int		step_x;
	int		step_y;
	int		col;
	int		side;
	int		lh;
	int		tex;
}	t_ray;

typedef struct s_read
{
	char		*b;
	char		*l;
	char		*stc;
}	t_read;

typedef struct s_cube
{
	char		**map;
	char		*l;
	int			rows;
	int			bg;
	t_flag		flag;
	t_rend		render;
	t_tex		tex;
	t_mlx		lib;
	t_rgb		colors;
	t_spr		spr;
	t_sprpos	*spr_pos;
	t_mov		mov;
	t_view		view;
	t_ray		ray;
	t_read		read;
	t_draw		draw;
	t_img		win;
	t_img		wall[4];
}	t_cube;

void	set_struct(t_cube *cube);

#endif
