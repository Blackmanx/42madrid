/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:52:35 by prodrigo          #+#    #+#             */
/*   Updated: 2021/11/30 12:35:16 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack *stack)
{
	int		i;
	int		len;
	t_stack	*tmp;

	i = 0;
	len = get_stacklen(stack);
	while (stack->prev)
		stack = stack->prev;
	while (i < len)
	{
		len = stack;
		if (stack)
			stack = stack->next;
		free(len);
		i++;
	}
}

void	free_tab(char **aux)
{
	int	i;

	i = 0;
	if (aux)
	{
		while (aux[i])
		{
			if (aux[i])
				free(aux[i]);
			i++;
		}
		free(aux);
	}
}
