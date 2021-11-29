/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:40:22 by prodrigo          #+#    #+#             */
/*   Updated: 2021/11/29 17:12:31 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_argc(int argc, char *argv[])
{
	if (argc > 1)
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
	return (1);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_table	table;
	int		len;

	i = 0;
	if (check_argc(argc, argv) == 1)
	{
		init_table(argc, argv, &table);
		table.s_len = get_stacklen(table.a);
		len = get_stacklen(table.a);
		if (find_dup(&table, table.sorted, len))
			return (fd_error("Found duplicates."));
		if (check_sort(table.a))
			choose_sort(&table);
		free_stack(table.a);
		free(table.sorted);
	}
	return (0);
}
