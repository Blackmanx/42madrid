/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:40:51 by prodrigo          #+#    #+#             */
/*   Updated: 2021/10/18 15:51:09 by prodrigo         ###   ########.fr       */
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
	t_elem			*elem;
	t_elem			*head;

}	t_stack;

int		sa(t_elem *a);
int		sb(t_elem *b);
int		ss(t_stack *table);
int		pa(t_stack *table);
int		pb(t_stack *table);
int		ra(t_elem *a);
int		rb(t_elem *b);
int		rr(t_stack *table);
int		rra(t_elem *a);
int		rrb(t_elem *b);
int		rrr(t_stack *table);
void	free_elem(t_elem *elem);
void	quick_sort(int arr[], int low, int high);
void	free_tab(char **tab);
void	free_stack(t_stack *a);
#endif
