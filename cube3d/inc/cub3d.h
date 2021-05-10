/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:44:16 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/10 18:35:44 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./inc/libft/libft.h"
# include "./inc/lib/mlx.h"
# include <math.h>
# include <fcntl.h>

# define PI 3.141592654

/*
**	TODO: Rest of paths
*/
typedef struct s_tex
{
	char	*no;
	char	*so;
}	t_tex;

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

/*
**	TODO: Rest of structs.
*/
typedef struct s_cub
{
	int		rows;
	int		bmp;
	char	*line;
	char	**map;
	t_tex	tex;
	t_rgb	rgb;
	t_rend	res;
}	t_cub;

#endif
