/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:01:07 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 21:01:09 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static char	*path_tex(char *line, t_cube *c, int nchar)
{
	int	i;

	i = nchar;
	while (ft_isspace(line[i]))
		i++;
	line = line + i;
	i = ft_strlen(line) - 1;
	while (ft_isspace(line[i]))
	{
		line[i] = '\0';
		i--;
	}
	if (err_tex(line) == 1)
		exit_program(c, "Too many elements in texture\n", 1);
	if (check_text(c, line) == 1)
		return (ft_strdup(line));
	if (check_text(c, line) < 0)
		exit_program(c, "The texture extension must be .xpm\n", 1);
	exit_program(c, "Repeated texture\n", 1);
	return (NULL);
}

static int	vertical_text(char *line, t_cube *cube)
{
	if (!ft_strncmp(line, "NO", 2) && !cube->flag.tex_n)
	{
		cube->tex.n = path_tex(line, cube, 2);
		if (!ft_isspace(line[2]) || !cube->tex.n)
			exit_program(cube, "Wrong north texture\n", 1);
		cube->flag.tex_n = 1;
		return (1);
	}
	else if (!ft_strncmp(line, "NO", 2) && cube->flag.tex_n)
		exit_program(cube, "Duplicate north texture identifier\n", 1);
	else if (!ft_strncmp(line, "SO", 2) && !cube->flag.tex_s)
	{
		cube->tex.s = path_tex(line, cube, 2);
		if (!ft_isspace(line[2]) || !cube->tex.s)
			exit_program(cube, "Wrong south texture\n", 1);
		cube->flag.tex_s = 1;
		return (1);
	}
	else if (!ft_strncmp(line, "SO", 2) && cube->flag.tex_s)
		exit_program(cube, "Duplicate south texture identifier\n", 1);
	return (0);
}

static int	horizontal_text(char *line, t_cube *cube)
{
	if (!ft_strncmp(line, "WE", 2) && !cube->flag.tex_w)
	{
		cube->tex.w = path_tex(line, cube, 2);
		if (!ft_isspace(line[2]) || !cube->tex.w)
			exit_program(cube, "Wrong west texture\n", 1);
		cube->flag.tex_w = 1;
		return (1);
	}
	else if (!ft_strncmp(line, "WE", 2) && cube->flag.tex_w)
		exit_program(cube, "Duplicate west texture identifier\n", 1);
	else if (!ft_strncmp(line, "EA", 2) && !cube->flag.tex_e)
	{
		cube->tex.e = path_tex(line, cube, 2);
		if (!ft_isspace(line[2]) || !cube->tex.e)
			exit_program(cube, "Wrong east texture\n", 1);
		cube->flag.tex_e = 1;
		return (1);
	}
	else if (!ft_strncmp(line, "EA", 2) && cube->flag.tex_e)
		exit_program(cube, "Duplicate east texture identifier\n", 1);
	return (0);
}

void	info_tex(char *line, t_cube *cube)
{
	int	done;

	cb_trim(cube, &line);
	done = vertical_text(line, cube) || horizontal_text(line, cube);
	if (!done && !ft_strncmp(line, "SO", 1) && !cube->flag.tex_spr)
	{
		cube->tex.spr = path_tex(line, cube, 1);
		if (!ft_isspace(line[1]) || !cube->tex.spr)
			exit_program(cube, "Wrong sprite texture\n", 1);
		cube->flag.tex_spr = 1;
	}
	else if (!done && !ft_strncmp(line, "SO", 1) && cube->flag.tex_spr)
		exit_program(cube, "Duplicate sprite texture identifier\n", 1);
}

int	is_texture(char *line)
{
	char	*aux;

	aux = ft_strchr(line, 'N');
	if (aux && aux[1] == 'O')
		return (1);
	aux = ft_strchr(line, 'S');
	if (aux && aux[1] == 'O')
		return (1);
	aux = ft_strchr(line, 'W');
	if (aux && aux[1] == 'E')
		return (1);
	aux = ft_strchr(line, 'E');
	if (aux && aux[1] == 'A')
		return (1);
	aux = ft_strchr(line, 'S');
	if (aux && ft_isspace(aux[1]))
		return (1);
	return (0);
}
