/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 03:43:21 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/28 02:11:02 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

typedef struct s_scr {
	int			x;
	int			y;
}				t_scr;

typedef struct s_view {
	float		perspective;
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

typedef struct s_svg
{
	int			d1;
	int			d2;
	int			len;
}				t_svg;

typedef struct s_coord {
	int			x;
	int			y;
}				t_coord;

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
	t_svg		svg;
	t_lib		lib;
	t_scr		scr;
}				t_fdf;

#endif
