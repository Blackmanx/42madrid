/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:02:25 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/20 03:29:07 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_map_getlen(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (-1);
	while (array[i])
		i++;
	return (i);
}

int	ft_getlen(char *array)
{
	int	i;

	i = 0;
	if (!array)
		return (-1);
	while (array[i])
		i++;
	return (i);
}

int	ft_matrix_getlen(int **array)
{
	int	i;

	i = 0;
	if (!array)
		return (-1);
	while (array[i])
		i++;
	return (i);
}

int	ft_num_getlen(int *array)
{
	int	i;

	i = 0;
	if (!array)
		return (-1);
	while (array[i])
		i++;
	return (i);
}
