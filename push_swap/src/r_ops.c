/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:57:44 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/01 18:51:44 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	r_util(t_stack *stack)
{
	t_stack	*head;
	t_stack	*aux;

	while (stack->prev)
		stack = stack->prev;
	head = stack;
	stack = stack->next;
	aux = stack;
	stack->prev = NULL;
	while (stack->next)
		stack = stack->next;
	stack->next = head;
	head->prev = stack;
	head->next = NULL;
	return (aux);
}

int	ra(t_stack *a)
{
	t_stack	*res;

	res = r_util(a);
	ft_putstr_fd("ra\n", 1);
	return (res);
}

int	rb(t_stack *b)
{
	t_stack	*res;

	res = r_util(b);
	ft_putstr_fd("rb\n", 1);
	return (res);
}

void	rr(t_table *table)
{
	res = ra(table->a);
	res = rb(table->b);
}
