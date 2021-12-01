/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:32:12 by prodrigo          #+#    #+#             */
/*   Updated: 2021/11/30 21:32:57 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_few(t_table *table)
{
	table->a = get_head(table->a);
	if (table->a->elem > table->a->next->elem)
		table->a = sa(table->a);
}
