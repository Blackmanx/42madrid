/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:40:22 by prodrigo          #+#    #+#             */
/*   Updated: 2021/09/06 18:37:23 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_program(t_stack *stack, char *str, int error)
{
	int	len;

	len = ft_strlen(str);
	if (error)
		write(1, "Error\n", 6);
	if (!str)
		perror("");
	else
		write(1, str, len);
	exit(1);
}

static void	check_argc(t_stack *stack, int n, char *str)
{
	int		i;

	if (n < 1)
		exit_program(stack, "Invalid number of arguments\n", 1);
	i = 0;
	while (!str[i])
	{
		if (!ft_isdigit(str[i]) || !ft_isspace(str[i]))
		{
			exit_program(stack, "Invalid argument\n", 1);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_stack	stack;

	check_argc(&stack, argc, argv[2]);
}
