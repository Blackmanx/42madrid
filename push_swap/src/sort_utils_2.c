/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:50:25 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/02 00:28:26 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_table	*operate_splits(t_table *table, int start, int end)
{
	int		hold_first_moves;
	int		hold_second_moves;

	hold_first_moves = ft_scan_from_top(table, start, end);
	hold_second_moves = ft_scan_from_bottom(table, start, end);
	if (hold_first_moves <= hold_second_moves)
	{
		while (hold_first_moves-- > 0)
			table->a = ra(table->a);
		pb(table);
	}
	else
	{
		while (hold_second_moves >= 0)
		{
			table->a = rra(table->a);
			hold_second_moves--;
		}
		pb(table);
	}
	return (table);
}
