/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:25:13 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/02 18:38:47 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*add_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

t_stack	*add_list(t_stack *stack)
{
	t_stack	*new;

	new = add_stack();
	stack->next = new;
	new->prev = stack;
	return (new);
}

t_stack	*get_stack(char **aux, t_stack *stack)
{
	int	i;

	i = 0;
	stack = add_stack();
	while (aux[i])
	{
		stack->elem = ft_atoi(aux[i]);
		if (aux[i + 1] != NULL)
			stack = add_list(stack);
		i++;
	}
	return (stack);
}
