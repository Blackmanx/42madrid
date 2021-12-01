/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:23:03 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/02 00:28:25 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	under_mid_point(t_table	*table, int middle_point)
{
	int	i;

	i = 0;
	while (i < table->s_len)
	{
		if (table->a->elem < middle_point)
			pb(table);
		else
			table->a = ra(table->a);
		i++;
	}
}

static void	sorted_b_to_a(t_table	*table)
{
	if (table->s_len == 3)
	{
		table->b = sort_three(table->b);
		pa(table);
		pa(table);
		pa(table);
	}
	else if (table->s_len == 2)
	{
		while (table->b->prev)
			table->b = table->b->prev;
		if (table->b->elem < table->b->next->elem)
			table->b = sb(table->b);
		pa(table);
		pa(table);
	}
}

t_stack	*sort_five(t_table *table)
{
	int		middle_point;
	t_stack	*tmp;

	middle_point = table->sorted[table->s_len / 2];
	while (table->a->prev)
		table->a = table->a->prev;
	tmp = table->a;
	under_mid_point(table, middle_point);
	table->s_len = get_stacklen(table->a);
	if (table->s_len == 3)
	{
		table->a = sort_three(table->a);
	}
	else
	{
		table->a = get_head(table->a);
		if (table->a->elem > table->a->next->elem)
			table->a = sa(table->a);
	}
	table->s_len = get_stacklen(table->b);
	sorted_b_to_a(table);
	return (table->a);
}
