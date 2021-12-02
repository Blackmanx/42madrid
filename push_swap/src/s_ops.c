/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:57:30 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/02 18:35:13 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static t_stack	*s_util(t_stack *stack)
{
	int	aux;

	while (stack->prev)
		stack = stack->prev;
	aux = stack->next->elem;
	stack->next->elem = stack->elem;
	stack->elem = aux;
	return (stack);
}

t_stack	*sa(t_stack *a)
{
	a = s_util(a);
	ft_putstr_fd("sa\n", 1);
	return (a);
}

t_stack	*sb(t_stack *b)
{
	b = s_util(b);
	ft_putstr_fd("sb\n", 1);
	return (b);
}

t_stack	*ss(t_table *table)
{
	t_stack	*res;

	res = sa(table->a);
	res = sb(table->b);
	return (res);
}
