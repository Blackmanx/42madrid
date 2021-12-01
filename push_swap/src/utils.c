/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:59:36 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/01 18:51:41 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_stacklen(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack && stack->prev)
		stack = stack->prev;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	find_dup(t_table *table, int *stack, int len)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (i < len - 1)
	{
		if (i < len)
		{
			if (stack[i] == stack[i + 1])
			{
				free_stack(table->a);
				free(table->sorted);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
