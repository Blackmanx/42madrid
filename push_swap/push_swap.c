/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:40:22 by prodrigo          #+#    #+#             */
/*   Updated: 2021/06/08 19:14:21 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_program(t_game *game, char *str, int error)
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

static void	check_argc(t_game *game, int n, char *str)
{
	if (n < 2 || n > 3)
		exit_program(game, "Invalid number of arguments\n", 1);
	else if (n == 3)
		exit_program(game, "Invalid save argument\n", 1);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	check_argc(&game, argc, argv[2]);
}
