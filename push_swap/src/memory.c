/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:52:35 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/02 18:20:05 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack *stack)
{
	int		i;
	int		len;
	t_stack	*aux;

	i = 0;
	len = get_stacklen(stack);
	while (stack->prev)
		stack = stack->prev;
	while (i < len)
	{
		aux = stack;
		if (stack)
			stack = stack->next;
		free(aux);
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
