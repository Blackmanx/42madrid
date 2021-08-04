/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:40:51 by prodrigo          #+#    #+#             */
/*   Updated: 2021/08/04 19:15:38 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_table
{
	int			*sorted;
	int			len;
	int			aux;
	int			temp;
	t_stack		*stack_a;
	t_stack		*stack_b;
}	t_table;

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
