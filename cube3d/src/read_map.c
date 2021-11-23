/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:02:25 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 21:02:27 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	cb_trim(t_cube *c, char **line)
{
	while (**line && ft_isspace(**line))
		*line = *line + 1;
	if (**line != 'R' && **line != 'N' && **line != 'S' && **line != 'E'
		&& **line != 'W' && **line != 'F' && **line != 'C')
	{
		exit_program(c, "Unidentified character\n", 1);
	}
}

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i])
		return (0);
	return (1);
}

void	check_ext(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (ft_strncmp(&filename[len - 4], ".cube", 4) != 0)
		exit_program(NULL, "The file extension must be .cube\n", 1);
}

static void	find_id(t_cube *c)
{
	if (get_tex(c))
		check_open_tex(c);
	if (!empty_line(c->line) && check_ids(c) == TOTAL_INFO)
		exit_str(c, "No information allowed after the map\n", c->r.stc);
	else if (ft_strchr(c->line, 'R'))
		info_res(c->line, c);
	else if (is_texture(c->line))
		info_tex(c->line, c);
	else if (ft_strchr(c->line, 'F') || ft_strchr(c->line, 'C'))
		info_color(c->line, c);
	else if (ft_strchr(c->line, '1') && check_ids(c) == TOTAL_IDS)
	{
		c->r.stc = info_map(c->line, c->r.stc, c);
		c->r.stc = ft_swap(c->r.stc, "\n");
	}
	else if (ft_strchr(c->line, '1') && check_ids(c) < TOTAL_IDS)
		exit_program(c, "Identifiers missing\n", 1);
	else if (empty_line(c->line) && c->r.stc != NULL && !c->flag.map)
	{
		cb_split(&c->r.stc, '\n', c);
		c->flag.map = 1;
	}
	else if (!empty_line(c->line))
		exit_program(c, "Unrecognized identifier\n", 1);
}

void	read_map(char *filename, t_cube *cube)
{
	int			fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_program(cube, "cube file could not be opened\n", 1);
	else
	{
		while (get_next_line(fd, &cube->line, &cube->r.b, &cube->r.l) > 0)
		{
			find_id(cube);
			free(cube->line);
			cube->line = 0;
		}
		if (cube->line != NULL && ft_strchr(cube->line, '1'))
			cube->r.stc = info_map(cube->line, cube->r.stc, cube);
		if (check_bad_end(cube))
			exit_program(cube, "No information allowed after the map\n", 1);
		if (!cube->flag.map)
			cb_split(&cube->r.stc, '\n', cube);
		free(cube->r.stc);
		close (fd);
		if (!cube->map)
			exit_program(cube, "There is no map\n", 1);
		cube->flag.map = 1;
	}
}
