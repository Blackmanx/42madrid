/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:03:12 by prodrigo          #+#    #+#             */
/*   Updated: 2019/10/10 16:04:32 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_insert_sort(int *arr, int n);

void	ft_sort_int_tab(int *tab, int size)
{
	ft_insert_sort(tab, size);
}

void	ft_insert_sort(int *arr, int n)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = i + 1;
	while (i < n - 1)
	{
		while (j < n)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
