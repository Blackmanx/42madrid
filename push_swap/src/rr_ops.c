/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:07:23 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/02 18:32:57 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_stack	*rr_util(t_stack *stack)
{
	t_stack	*tail;

	tail = NULL;
	if (get_stacklen(stack) > 1)
	{
		while (stack && stack->next)
			stack = stack->next;
		tail = stack;
		stack = stack->prev;
		stack->next = NULL;
		while (stack->prev)
			stack = stack->prev;
		stack->prev = tail;
		tail->prev = NULL;
		tail->next = stack;
	}
	return (tail);
}

t_stack	*rra(t_stack *a)
{
	t_stack	*res;

	res = rr_util(a);
	ft_putstr_fd("rra\n", 1);
	return (res);
}

t_stack	*rrb(t_stack *b)
{
	t_stack	*res;

	res = rr_util(b);
	ft_putstr_fd("rrb\n", 1);
	return (res);
}

t_stack	*rrr(t_table *table)
{
	t_stack	*res;

	res = rra(table->a);
	res = rrb(table->b);
	return (res);
}
