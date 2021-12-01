/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:32:12 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/01 18:53:28 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	sort_hundred(t_table *table)
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
			table = operate_splits(table, aux_tail, aux_len);
		aux_len += sum;
		aux_tail += sum;
		i++;
	}
	table->s_len = get_stacklen(a);
	while (table->a)
		pb(table);
	table = operate_dummy(table);
	return (1);
}

void	sort_few(t_table *table)
{
	table->a = get_head(table->a);
	if (table->a->elem > table->a->next->elem)
		table->a = sa(table->a);
}
