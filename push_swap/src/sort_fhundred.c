/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fhundred.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:32:50 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/03 14:41:46 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_table	*operate_push(t_table *table)
{
	while (table->b)
		move_top(table);
	return (table);
}

t_table	*operate_blocks(t_table *table, int start, int end)
{
	int		chunk_one_moves;
	int		chunk_two_moves;

	chunk_one_moves = scan_top(table, start, end);
	chunk_two_moves = scan_bottom(table, start, end) + 1;
	if (chunk_one_moves <= chunk_two_moves)
	{
		while (chunk_one_moves-- > 0)
			table->a = ra(table->a);
		pb(table);
	}
	else
	{
		while (--chunk_two_moves >= 0)
			table->a = rra(table->a);
		pb(table);
	}
	return (table);
}

int	sort_fivehundred(t_table *table)
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
			table = operate_blocks(table, aux_tail, aux_len);
		aux_len += sum;
		aux_tail += sum;
		i++;
	}
	table->s_len = get_stacklen(table->a);
	while (table->a)
		pb(table);
	table = operate_push(table);
	return (1);
}
