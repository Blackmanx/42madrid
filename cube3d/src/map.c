/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:58:33 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/20 20:13:27 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	check_chars(char s)
{
	return (s == NORTH || s == EAST || s == SOUTH || s == WEST || s == WALL
		|| s == EMPTY_SPACE || s == '\t' || s == EMPTY || s == WALL
		|| s == OBJECT);
}

static int	get_line_len(char *l)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (l[++i])
	{
		if (check_chars(l[i]))
			n++;
		else
			return (-1);
	}
	return (n);
}

static char	*fill_map(char *l)
{
	char	*aux;
	int		i;
	int		j;
	int		len;

	len = (int)ft_strlen(l);
	i = get_line_len(l);
	aux = NULL;
	if (i == -1)
		return (NULL);
	if (len == i)
		return (ft_strdup(l));
	else
		aux = (char *)malloc(sizeof(char) * (i + 1));
	i = -1;
	j = -1;
	while (l[++j])
		if (l[j])
			aux[++i] = l[j];
	aux[i + 1] = '\0';
	return (aux);
}
