/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:22:13 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/03 14:07:15 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*get_head(t_stack *stack)
{
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}

t_stack	*get_tail(t_stack *stack)
{
	while (stack->next)
		stack = stack->prev;
	return (stack);
}

int	check_sort(t_stack *stack)
{
	int	len;

	len = get_stacklen(stack);
	while (stack->prev)
		stack = stack->prev;
	while (len > 1)
	{
		if (stack->elem > stack->next->elem)
			return (1);
		stack = stack->next;
		len--;
	}
	return (0);
}

void	choose_sort(t_table *table)
{
	if (table->s_len < 3)
		sort_few(table);
	else if (table->s_len == 3)
		table->a = sort_three(table->a);
	else if (table->s_len > 3 && table->s_len <= 5)
		table->a = sort_five(table);
	else if (table->s_len > 5 && table->s_len <= 100)
		sort_hundred(table);
	else
		sort_fivehundred(table);
}
