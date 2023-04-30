/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:37:31 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/30 12:43:14 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

int	main(void)
{
	int n;
	char *l;

	fd = open("file.txt", O_RDONLY);
	n = 1;
	while ((l = get_next_line(fd)))
	{
		printf("L [%02d]: %s", n, l);
		free(l);
		n++;
	}
	close(fd);
	return (0);
}
