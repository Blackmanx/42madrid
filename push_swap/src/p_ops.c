/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:57:42 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/02 18:21:52 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_stack	*move_stack_b(t_table *table, t_stack *stack)
{
	stack = NULL;
	if (table->b)
	{
		table->b = get_head(table->b);
		stack = table->b;
		table->b = table->b->next;
		table->b->prev = NULL;
		stack->next = NULL;
		table->a = stack;
	}
	return (stack);
}

void	pa(t_table *table)
{
	t_stack	*stack;

	stack = NULL;
	if (table->a != NULL)
	{
		table->a = get_head(table->a);
		if (table->b)
		{
			table->b = get_head(table->b);
			stack = table->b;
			table->b = table->b->next;
			if (table->b)
				table->b->prev = NULL;
			table->a->prev = stack;
			stack->next = table->a;
		}
	}
	else
		stack = move_stack_b(table, stack);
	ft_putstr_fd("pa\n", 1);
}

static t_stack	*move_stack_a(t_table *table, t_stack *stack)
{
	table->a = get_head(table->a);
	stack = table->a;
	table->a = table->a->next;
	table->a->prev = NULL;
	stack->next = NULL;
	table->b = stack;
	return (stack);
}

void	pb(t_table *table)
{
	t_stack	*stack;

	stack = NULL;
	if (table->b != NULL)
	{
		table->b = get_head(table->b);
		if (table->a)
		{
			table->a = get_head(table->a);
			stack = table->a;
			table->a = table->a->next;
			if (table->a)
				table->a->prev = NULL;
			table->b->prev = stack;
			stack->next = table->b;
		}
	}
	else
		stack = move_stack_a(table, stack);
	ft_putstr_fd("pb\n", 1);
}
