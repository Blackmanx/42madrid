/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:01:20 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 21:01:21 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	save_int(char **line)
{
	char	*num;
	char	caracter[2];
	int		n;

	n = -1;
	num = ft_strdup("");
	while (!ft_isdigit((int)**line) && **line)
		*line = *line + 1;
	while (ft_isdigit((int)**line) && **line)
	{
		caracter[0] = **line;
		caracter[1] = '\0';
		num = ft_swap(num, caracter);
		*line = *line + 1;
	}
	if (check_res(num))
		n = ft_atoi(num);
	free(num);
	return (n);
}

void	info_res(char *line, t_cube *cube)
{
	cb_trim(cube, &line);
	if (!ft_strncmp(line, "R", 1) && !cube->flag.res)
	{
		if (line[1] != ' ')
			exit_program(cube, "Wrong screen resolution\n", 1);
		if (err_res(line))
			exit_program(cube, "Characters not allowed in resolution\n", 1);
		cube->render.x = save_int(&line);
		cube->render.y = save_int(&line);
		if (save_int(&line) >= 0)
			exit_program(cube, "Too many elements in resolution\n", 1);
		if (cube->render.x <= 0 || cube->render.y <= 0)
			exit_program(cube, "Wrong screen resolution\n", 1);
		if (cube->render.x < 30 || cube->render.y < 30)
			exit_program(cube, "Screen resolution too small\n", 1);
		cube->flag.res = 1;
	}
	else if (!ft_strncmp(line, "R", 1) && cube->flag.res)
		exit_program(cube, "Repeated resolution identifier\n", 1);
}

static void	info_color_sky(char *line, t_cube *cube)
{
	if (!ft_strncmp(line, "C", 1) && !cube->flag.sky)
	{
		if (line[1] != ' ')
			exit_program(cube, "Wrong ceiling col\n", 1);
		cube->col.rgb_s[0] = save_int(&line);
		if (!(cube->col.rgb_s[0] >= 0 && cube->col.rgb_s[0] <= 255))
			exit_program(cube, "Wrong R ceiling value\n", 1);
		cube->col.rgb_s[1] = save_int(&line);
		if (!(cube->col.rgb_s[1] >= 0 && cube->col.rgb_s[1] <= 255))
			exit_program(cube, "Wrong G ceiling value\n", 1);
		cube->col.rgb_s[2] = save_int(&line);
		if (!(cube->col.rgb_s[2] >= 0 && cube->col.rgb_s[2] <= 255))
			exit_program(cube, "Wrong B ceiling value\n", 1);
		if (save_int(&line) >= 0)
			exit_program(cube, "Too many elements in ceiling col\n", 1);
		cube->flag.sky = 1;
	}
	else if (!ft_strncmp(line, "C", 1) && cube->flag.sky)
		exit_program(cube, "Repeated ceiling col identifier\n", 1);
}

void	info_color(char *line, t_cube *cube)
{
	cb_trim(cube, &line);
	err_rgb(cube, line);
	if (!ft_strncmp(line, "F", 1) && !cube->flag.floor)
	{
		if (line[1] != ' ')
			exit_program(cube, "Wrong floor col\n", 1);
		cube->col.rgb_f[0] = save_int(&line);
		if (!(cube->col.rgb_f[0] >= 0 && cube->col.rgb_f[0] <= 255))
			exit_program(cube, "Wrong R floor value\n", 1);
		cube->col.rgb_f[1] = save_int(&line);
		if (!(cube->col.rgb_f[1] >= 0 && cube->col.rgb_f[1] <= 255))
			exit_program(cube, "Wrong G floor value\n", 1);
		cube->col.rgb_f[2] = save_int(&line);
		if (!(cube->col.rgb_f[2] >= 0 && cube->col.rgb_f[2] <= 255))
			exit_program(cube, "Wrong B floor value\n", 1);
		if (save_int(&line) >= 0)
			exit_program(cube, "Too many elements in floor col\n", 1);
		cube->flag.floor = 1;
	}
	else if (!ft_strncmp(line, "F", 1) && cube->flag.floor)
		exit_program(cube, "Repeated floor col identifier\n", 1);
	info_color_sky(line, cube);
}

void	refill_map(t_cube *c)
{
	int		w;
	char	**map;
	int		k;
	int		len;

	w = get_map_dim(c);
	map = (char **)malloc((c->nrows + 1) * sizeof(char *));
	k = -1;
	while (c->map[++k])
	{
		map[k] = (char *)malloc((w + 1) * sizeof(char));
		len = ft_strlen(c->map[k]);
		ft_memcpy(map[k], c->map[k], len);
		if (len < w)
			ft_memset(&map[k][len], ' ', w - len);
		map[k][w] = '\0';
	}
	map[k] = NULL;
	free_map(c);
	c->map = map;
}
