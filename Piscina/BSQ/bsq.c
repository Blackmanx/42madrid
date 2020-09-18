/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQ.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:26:33 by jomartin          #+#    #+#             */
/*   Updated: 2019/10/23 22:09:18 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "globals.h"
#include "algorithm.h"
#include <stdio.h>
#include "utils_one.h"
#include "utils_two.h"

int		*runmap(void)
{
	int		i;
	int		j;
	int		*tab;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	tab = malloc(sizeof(*tab) * (g_row + 1));
	if (tab != NULL)
	{
		while (g_map[i] != '\0')
		{
			if (g_map[i] == '\n')
			{
				tab[j] = k;
				j++;
				k = 0;
			}
			i++;
			k++;
		}
	}
	g_col = tab[1];
	return (tab);
}

char	**cpy_matrix(char **matrix)
{
	int		i;
	int		k;
	int		l;

	i = 0;
	k = 0;
	l = 0;
	while (g_map[i] != '\n')
		i++;
	i++;
	while (k < g_row)
	{
		matrix[k][l] = g_map[i];
		if (g_map[i] == '\n')
		{
			k++;
			l = -1;
		}
		i++;
		l++;
	}
	return (matrix);
}

char	**get_matrix(int lenfline, int lenfile, char **matrix)
{
	int		i;
	int		*tab;

	i = lenfile - lenfline;
	tab = runmap();
	i = 0;
	matrix = (char**)malloc(sizeof(char*) * g_row);
	if (matrix != NULL)
	{
		while (i < g_row)
		{
			matrix[i] = (char*)malloc(sizeof(char) * (tab[i]));
			i++;
		}
	}
	return (cpy_matrix(matrix));
}

void	printmatrix(char **matrix, int rows, int column)
{
	int i;

	i = 0;
	while (i < rows)
	{
		write(1, matrix[i], column);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		originalg[2];
	char	*row;
	char	**matrix;
	char	*file;
	int		lenfile;

	row = NULL;
	matrix = NULL;
	if (argc > 1)
	{
		file = argv[1];
		modfile(file);
		get_code();
		lenfile = get_row(row);
		matrix = get_matrix(lenfile, g_row, matrix);
		originalg[0] = g_row;
		originalg[1] = g_col;
		bsq_modarr(g_row, g_col, matrix);
		printmatrix(matrix, originalg[0], originalg[1]);
	}
	else
		return (0);
	return (1);
}
