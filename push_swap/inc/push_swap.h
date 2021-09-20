/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:40:51 by prodrigo          #+#    #+#             */
/*   Updated: 2021/09/20 12:49:04 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_elem
{
	int				data;
	ssize_t			index;
	struct s_elem	*next;
	struct s_elem	*prev;
}	t_elem;

typedef struct s_stack
{
	t_elem			*head;
	size_t			size;

}	t_stack;

int		sa(t_stack *a);
int		sb(t_stack *b);
int		ss(t_table *table);
int		pa(t_table *table);
int		pb(t_table *table);
int		ra(t_stack *a);
int		rb(t_stack *b);
int		rr(t_table *table);
int		rra(t_stack *a);
int		rrb(t_stack *b);
int		rrr(t_table *table);

#endif
