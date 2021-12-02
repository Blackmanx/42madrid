/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fhundred.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:32:50 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/02 17:58:27 by prodrigo         ###   ########.fr       */
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
	int		hold_first_moves;
	int		hold_second_moves;

	hold_first_moves = scan_top(table, start, end);
	hold_second_moves = scan_bottom(table, start, end);
	if (hold_first_moves <= hold_second_moves)
	{
		while (hold_first_moves-- > 0)
			table->a = ra(table->a);
		pb(table);
	}
	else
	{
		while (hold_second_moves >= 0)
		{
			table->a = rra(table->a);
			hold_second_moves--;
		}
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
