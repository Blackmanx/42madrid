/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:30:24 by prodrigo          #+#    #+#             */
/*   Updated: 2019/10/23 20:34:02 by jomartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"
#include "matrixutils.h"

void	setsrc(int rows, int columns, int n)
{
	if (n > g_max)
	{
		g_max = n;
		g_row = rows;
		g_col = columns;
	}
}

void	resetg(int *a)
{
	*a = -1;
	g_row = 0;
	g_col = 0;
	g_max = -1;
}

int		min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}
