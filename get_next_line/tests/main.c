/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:37:31 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/30 16:22:12 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int n;
	char *l;
	int fd;

	fd = open("file.txt", O_RDONLY);
	system("leaks a.out");
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
