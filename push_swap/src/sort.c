/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:22:13 by prodrigo          #+#    #+#             */
/*   Updated: 2021/11/23 15:27:12 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	quick_sort(t_table *table)
{
	if (table->s_len == 2 || table->s_len == 1)
	{
		table->a = get_head(table->a);
		if (table->a->elem > table->a->next->elem)
			table->a = ft_sa(table->a);
	}
	else if (table->s_len == 3)
		table->a = sort3element(table->a);
	else if (table->s_len > 3 && table->s_len <= 5)
		table->a = sort5element(table);
	else if (table->s_len > 5 && table->s_len <= 100)
		sort100element(table);
	else
		above_100element(table);