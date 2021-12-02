/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:51:23 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/02 15:52:39 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	check_split(t_table *table, int start, int end, int elem)
{
	while (start < end)
		if (elem == table->sorted[start++])
			return (1);
	return (0);
}

int	scan_top(t_table *table, int start, int end)
{
	int		moves;

	moves = 0;
	while (table->a->prev)
		table->a = table->a->prev;
	while (table->a->next)
	{
		if (check_split(table, start, end, table->a->elem))
		{
			table->split_one = table->a->elem;
			return (moves);
		}
		table->a = table->a->next;
		moves++;
	}
	return (moves);
}

int	scan_bottom(t_table *table, int start, int end)
{
	int		moves;

	moves = 0;
	while (table->a->next)
		table->a = table->a->next;
	while (table->a->prev)
	{
		if (check_split(table, start, end, table->a->elem))
		{
			table->split_two = table->a->elem;
			return (moves);
		}
		table->a = table->a->prev;
		moves++;
	}
	return (moves);
}

int	get_largest(t_table table)
{
	int		var_to_push;
	int		inc;
	int		pos;

	inc = 0;
	pos = 0;
	while (table.b->prev)
		table.b = table.b->prev;
	var_to_push = table.b->elem;
	while (table.b)
	{
		if (var_to_push <= table.b->elem)
		{
			var_to_push = table.b->elem;
			pos = inc;
		}
		inc++;
		table.b = table.b->next;
	}
	return (pos);
}

void	sort_few(t_table *table)
{
	table->a = get_head(table->a);
	if (table->a->elem > table->a->next->elem)
		table->a = sa(table->a);
}
