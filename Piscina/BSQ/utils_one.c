/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:01:57 by prodrigo          #+#    #+#             */
/*   Updated: 2019/10/23 22:03:55 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "globals.h"
#include "algorithm.h"

void	printerror(void)
{
	write(1, "map error\n", 10);
}

int		modfile(char *file)
{
	int		fileopen;
	char	size[1];
	int		i;

	i = 0;
	fileopen = open(file, O_RDONLY);
	if (fileopen == -1)
		printerror();
	else
	{
		size[0] = 1;
		while (size[0] != 0)
		{
			size[0] = read(fileopen, size, 1);
			i++;
		}
		close(fileopen);
		if (!(g_map = malloc(sizeof(*g_map) * i)))
			g_map[i] = '\0';
		fileopen = open(file, O_RDONLY);
		if (read(fileopen, g_map, i) == -1)
			printerror();
		close(fileopen);
	}
	return (i);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

void	get_code(void)
{
	int		i;
	int		j;
	int		k;

	i = ft_strlen(g_map);
	j = i - 3;
	k = 0;
	g_code = malloc(sizeof(char) * 4);
	if (g_code != NULL)
	{
		while (j < i)
		{
			g_code[k] = g_map[j];
			j++;
			k++;
		}
		g_code[j] = '\0';
	}
}

int		ft_atoi(char *str)
{
	int		j;

	j = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		j = (j * 10) + (*str - '0');
		++str;
	}
	return (j);
}
