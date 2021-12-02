/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:40:22 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/02 22:56:52 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	check_argc(int argc)
{
	if (argc < 2)
		fd_error("Not enough args.");
	return (1);
}

void	check_argv(char **aux)
{
	int	i;
	int	j;

	i = 0;
	while (aux[i])
	{
		j = 0;
		while (j < aux[i][j])
		{
			if (ft_isdigit(aux[i][j] == 0))
			{
				if ((aux[i][j] == '-' || aux[i][j] == '+') && j == 0)
				{
					free_tab(aux);
					fd_error("Error in argvs format.");
				}
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_table	table;
	int		len;

	if (check_argc(argc) == 1)
	{
		init_table(argc, argv, &table);
		table.s_len = get_stacklen(table.a);
		len = get_stacklen(table.a);
		if (find_dup(&table, table.sorted, len))
			fd_error("Found duplicates.");
		if (check_sort(table.a))
			choose_sort(&table);
		free_stack(table.a);
		free(table.sorted);
	}
	return (0);
}
