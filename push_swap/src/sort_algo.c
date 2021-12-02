/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:32:12 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/02 22:57:53 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	cases(int f_value, int s_value, int l_value)
{
	if (f_value > s_value && s_value < l_value && l_value > f_value)
		return (1);
	else if (f_value > s_value && s_value > l_value && l_value < f_value)
		return (2);
	else if (f_value > s_value && s_value < l_value && l_value < f_value)
		return (3);
	else if (f_value < s_value && s_value > l_value && l_value > f_value)
		return (4);
	else if (f_value < s_value && s_value > l_value && l_value < f_value)
		return (5);
	return (0);
}

t_stack	*sort_three(t_stack *stack)
{
	int	f_value;
	int	s_value;
	int	l_value;

	stack = get_head(stack);
	f_value = stack->elem;
	s_value = stack->next->elem;
	l_value = stack->next->next->elem;
	if (cases(f_value, s_value, l_value) == 1)
		stack = sa(stack);
	else if (cases(f_value, s_value, l_value) == 2)
	{
		stack = sa(stack);
		stack = rra(stack);
	}
	else if (cases(f_value, s_value, l_value) == 3)
		stack = ra(stack);
	else if (cases(f_value, s_value, l_value) == 4)
	{
		stack = sa(stack);
		stack = ra(stack);
	}
	else if (cases(f_value, s_value, l_value) == 5)
		stack = rra(stack);
	return (stack);
}

static void	under_mid_point(t_table *table, int median)
{
	int	i;

	i = 0;
	while (i < table->s_len)
	{
		if (table->a->elem < median)
			pb(table);
		else
			table->a = ra(table->a);
		i++;
	}
}

static void	sorted_b_to_a(t_table *table)
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
	int		median;

	median = table->sorted[table->s_len / 2];
	while (table->a->prev)
		table->a = table->a->prev;
	under_mid_point(table, median);
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
