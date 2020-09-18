/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:06:09 by prodrigo          #+#    #+#             */
/*   Updated: 2019/10/23 22:10:35 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "globals.h"
#include "algorithm.h"
#include "utils_one.h"

int		get_row(char *row)
{
	int		i;
	int		j;

	i = ft_strlen(g_map);
	j = 0;
	row = malloc(sizeof(char) * (i - 3));
	if (row != NULL)
	{
		while (j < i - 3)
		{
			row[j] = g_map[j];
			j++;
		}
		row[j] = '\0';
	}
	g_row = ft_atoi(row);
	return (i);
}
