/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:03:14 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 21:03:18 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

int	get_tex(t_cube *c)
{
	return (c->flag.tex_n && c->flag.tex_s && c->flag.tex_w
		&& c->flag.tex_e && c->flag.tex_spr);
}

void	exit_str(t_cube *c, char *txt, char *str)
{
	refill_map(c);
	if (str != NULL)
		free(str);
	exit_program(c, txt, 1);
}

void	check_open_tex(t_cube *c)
{
	int	fd;

	fd = open(c->tex.n, O_RDONLY);
	if (fd < 0)
		exit_program(c, "Fail to open texture\n", 1);
	close(fd);
	fd = open(c->tex.s, O_RDONLY);
	if (fd < 0)
		exit_program(c, "Fail to open texture\n", 1);
	close(fd);
	fd = open(c->tex.w, O_RDONLY);
	if (fd < 0)
		exit_program(c, "Fail to open texture\n", 1);
	close(fd);
	fd = open(c->tex.e, O_RDONLY);
	if (fd < 0)
		exit_program(c, "Fail to open texture\n", 1);
	close(fd);
	fd = open(c->tex.spr, O_RDONLY);
	if (fd < 0)
		exit_program(c, "Fail to open texture\n", 1);
	close(fd);
}

int	check_bad_end(t_cube *c)
{
	int	i;

	i = -1;
	while (c->line[++i])
	{
		if (!is_char_valid(c->line[i]))
			break ;
	}
	if (!empty_line(c->line) && check_ids(c) >= TOTAL_IDS
		&& (c->line[i] && !is_char_valid(c->line[i])))
	{
		return (1);
	}
	return (0);
}
