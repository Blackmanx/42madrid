/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:40:51 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/02 17:16:58 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				elem;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_table
{
	t_stack			*a;
	t_stack			*b;
	int				*sorted;
	int				s_len;
	int				split_one;
	int				split_two;

}	t_table;

// main.c
// static int	check_argc(int argc, char *argv[]);
void			check_argv(char **aux);
// int			main(int argc, char **argv);

// init.c

void			init_table(int argc, char **argv, t_table *table);

// s_ops.c
int				sa(t_stack *a);
int				sb(t_stack *b);
int				ss(t_table *table);

// p_ops.c
int				pa(t_table *table);
int				pb(t_table *table);

// r_ops.c
int				ra(t_stack *a);
int				rb(t_stack *b);
int				rr(t_table *table);

// rr_ops.c
int				rra(t_stack *a);
int				rrb(t_stack *b);
int				rrr(t_table *table);

// memory.c
void			free_elem(t_stack *stack);
int				get_stacklen(t_stack *stack);
void			choose_sort(t_table *table);
void			free_tab(char **aux);
void			free_stack(t_stack *stack);
void			init_table(int argc, char **argv, t_table *table);
int				find_dup(t_table *table, int *stack, int len);

#endif
