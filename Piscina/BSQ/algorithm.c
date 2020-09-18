/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:19:26 by prodrigo          #+#    #+#             */
/*   Updated: 2019/10/23 21:56:44 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"
#include <stdlib.h>
#include "algorithm.h"
#include "matrixutils.h"

int		fill(int rows, unsigned int **sizearr, char **arr)
{
	int i;
	int j;

	i = g_row;
	while (i > g_row - g_max)
	{
		j = g_col;
		while (j > g_col - g_max)
		{
			arr[i][j] = g_code[2];
			j--;
		}
		i--;
	}
	i = 0;
	while (i < rows)
	{
		free(sizearr[i]);
		i++;
	}
	free(sizearr);
	return (1);
}

int		findsquare(int rows, int columns, char **arr, unsigned int **sizearr)
{
	int		i;
	int		j;

	resetg(&i);
	while (++i < rows)
	{
		j = -1;
		while (++j < columns - 1)
		{
			if (arr[i][j] != g_code[0] && arr[i][j] != g_code[1])
				return (0);
			if (i == 0 || j == 0)
				sizearr[i][j] = (arr[i][j] == g_code[0]) ? 1 : 0;
			else
				sizearr[i][j] = (arr[i][j] == g_code[0]) ?
					min(sizearr[i - 1][j], sizearr[i][j - 1],
							sizearr[i - 1][j - 1]) + 1 : 0;
			setsrc(i, j, sizearr[i][j]);
		}
	}
	return (fill(rows, sizearr, arr));
}

int		bsq_modarr(int rows, int columns, char **arr)
{
	unsigned int	**sizearr;
	int				i;

	i = 0;
	sizearr = (unsigned int**)malloc(sizeof(unsigned int*) * rows);
	while (i < rows)
	{
		sizearr[i] = (unsigned int*)malloc(sizeof(unsigned int) * columns - 1);
		i++;
	}
	return (findsquare(rows, columns, arr, sizearr));
}
