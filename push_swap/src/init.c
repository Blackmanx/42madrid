/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:55:39 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/02 17:38:19 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	get_tablelen(char **argv, int argc)
{
	int		j;
	int		i;
	char	**tab;
	int		count;

	count = 0;
	argc = 0;
	j = 1;
	while (argv[j])
	{
		i = 0;
		count = 0;
		if (ft_strchr(argv[j], ' '))
		{
			tab = ft_split(argv[j], ' ');
			while (tab[count++])
				argc++;
			free_tab(tab);
		}
		else if (argv[j][0])
			argc++;
		j++;
	}
	return (argc);
}

static int	*sort_table(int	*table, int len)
{
	int	aux;
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (table[i] > table[i + 1])
		{
			aux = table[i];
			table[i] = table[i + 1];
			table[i + 1] = aux;
			i = -1;
		}
		i++;
	}
	return (table);
}

static char	**split_table(int argc, char **argv, char **aux)
{
	char	**spaced_argv;
	int		i;
	int		j;
	int		x;

	x = 0;
	i = 1;
	j = 0;
	aux = (char **)malloc(sizeof(char *) * argc + 1);
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' ') && argv[i][0])
		{
			x = 0;
			spaced_argv = ft_split(argv[i], ' ');
			while (spaced_argv[x])
				aux[j++] = ft_strdup(spaced_argv[x++]);
			free_tab(spaced_argv);
		}
		else if (argv[i][0])
			aux[j++] = ft_strdup(argv[i]);
		i++;
	}
	aux[j] = NULL;
	return (aux);
}

void	init_table(int argc, char **argv, t_table *table)
{
	char	**aux;
	int		flag;
	int		i;
	int		j;

	i = 0;
	j = 0;
	flag = 0;
	aux = NULL;
	argc = get_tablelen(argv, argc);
	i = 0;
	aux = split_table(argc, argv, aux);
	check_argv(aux);
	table->sorted = malloc(sizeof(int) * argc);
	while (aux[i])
	{
		table->sorted[i] = ft_atoi(aux[i]);
		if (table->sorted[i] == -1 || table->sorted[i] == 0)
			fd_error("Invalid number in args.");
		i++;
	}
	table->a = get_stack(aux, table->a);
	free_tab(aux);
	table->sorted = sort_table(table->sorted, argc);
}
