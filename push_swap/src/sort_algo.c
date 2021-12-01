/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:32:12 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/02 00:28:24 by prodrigo         ###   ########.fr       */
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

int	sort_hundred(t_table *table)
{
	int	aux_len;
	int	aux_tail;
	int	sum;
	int	i;
	int	j;

	i = 0;
	j = 0;
	aux_len = get_stacklen(table->a) / 13;
	sum = aux_len;
	aux_tail = 0;
	while (i < 13)
	{
		while (j++ < aux_len)
			table = operate_splits(table, aux_tail, aux_len);
		aux_len += sum;
		aux_tail += sum;
		i++;
	}
	table->s_len = get_stacklen(table->a);
	while (table->a)
		pb(table);
	table = operate_dummy(table);
	return (1);
}

void	sort_few(t_table *table)
{
	table->a = get_head(table->a);
	if (table->a->elem > table->a->next->elem)
		table->a = sa(table->a);
}
