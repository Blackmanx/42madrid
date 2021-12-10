/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:50:25 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/03 14:45:32 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	move_top(t_table *table)
{
	int	largest;
	int	median;

	largest = get_largest(*table);
	median = get_stacklen(table->b) / 2;
	if (largest < median)
	{
		while (largest-- > 0)
			rb((*table).b);
		pa(table);
	}
	else
	{
		largest = get_stacklen(table->b) - largest;
		while (largest-- > 0)
			rrb((*table).b);
		pa(table);
	}
	return (1);
}

static t_table	*move_block(t_table *table, int len, int start)
{
	int	i;
	int	j;
	int	sum;

	i = 0;
	j = 0;
	len = get_stacklen(table->a) / 5;
	sum = len;
	while (i < 5)
	{
		while (j < len)
		{
			table = operate_blocks(table, start, len);
			j++;
		}
		start += sum;
		len += sum;
		i++;
	}
	return (table);
}

int	sort_hundred(t_table *table)
{
	table = move_block(table, 0, 0);
	table->s_len = get_stacklen(table->a);
	if (table->s_len == 3)
		table->a = sort_three(table->a);
	else if (table->s_len == 2)
		if (table->a->elem > table->a->next->elem)
			table->a = sa(table->a);
	table = operate_push(table);
	return (1);
}
