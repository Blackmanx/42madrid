/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:37:33 by prodrigo          #+#    #+#             */
/*   Updated: 2019/10/09 16:45:44 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stduni.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int tmp_size;
	int tmp_value;
	int n;

	n = 0;
	tmp_size = size;
	while (n < ((tmp_size / 2) - 1))
	{
		tmp_value = tab[n];
		tab[n] = tab[tmp_size];
		tab[tmp_size] = tmp_value;
		n++;
		tmp_size--;
	}
}
