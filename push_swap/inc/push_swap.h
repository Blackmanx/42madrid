/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:40:51 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/03 14:22:48 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "../src/libft/libft.h"

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

// push_swap.c
// static int	check_argc(int argc, char *argv[]);
void			check_argv(char **aux);
// int			main(int argc, char **argv);

// init.c
void			init_table(int argc, char **argv, t_table *table);
// static char	**split_table(int argc, char **argv, char **aux)
// static int	*sort_table(int	*table, int len)
// static int	get_tablelen(char **argv, int argc)

// memory.c
void			free_tab(char **aux);
void			free_stack(t_stack *stack);

// s_ops.c
// static int	s_util(t_stack *stack)
t_stack			*sa(t_stack *a);
t_stack			*sb(t_stack *b);
t_stack			*ss(t_table *table);

// p_ops.c
// static t_stack	*move_stack_b(t_table *table, t_stack *stack)
// static t_stack	*move_stack_a(t_table *table, t_stack *stack)
void			pa(t_table *table);
void			pb(t_table *table);

// r_ops.c
t_stack			*ra(t_stack *a);
t_stack			*rb(t_stack *b);
t_stack			*rr(t_table *table);
//static int	r_util(t_stack *stack)

// rr_ops.c
t_stack			*rra(t_stack *a);
t_stack			*rrb(t_stack *b);
t_stack			*rrr(t_table *table);
// static int	rr_util(t_stack *stack)

// sort_algo.c
// static int	cases(int f_value, int s_value, int l_value)
t_stack			*sort_three(t_stack *stack);
// static void	sorted_b_to_a(t_table	*table);
// static void	under_mid_point(t_table	*table, int median);
t_stack			*sort_five(t_table *table);

// sort_fhundred.c
t_table			*operate_blocks(t_table *table, int start, int end);
int				sort_fivehundred(t_table *table);
t_table			*operate_push(t_table *table);

// sort_hundred.c
int				move_top(t_table *table);
// static t_table	*move_block(t_table *table, int len, int start)
int				sort_hundred(t_table *table);

// sort_utils.c
// static int	check_split(t_table *table, int start, int end, int elem)
int				scan_top(t_table *table, int start, int end);
int				scan_bottom(t_table *table, int start, int end);
int				get_largest(t_table table);
void			sort_few(t_table *table);

// sort.c
t_stack			*get_head(t_stack *stack);
t_stack			*get_tail(t_stack *stack);
int				check_sort(t_stack *stack);
void			choose_sort(t_table *table);

// stack_utils.c
t_stack			*add_stack(void);
t_stack			*add_list(t_stack *stack);
t_stack			*get_stack(char **aux, t_stack *stack);

// utils.c
int				get_stacklen(t_stack *stack);
int				find_dup(t_table *table, int *stack, int len);

#endif
