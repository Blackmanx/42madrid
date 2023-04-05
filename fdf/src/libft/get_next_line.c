/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:46:09 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/05 11:57:28 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/fdf.h"

static char	*handle_line(char *l)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	while (l[i] && l[i] != '\n')
		i++;
	aux = (char *)malloc(sizeof(char) * (i + 1));
	if (!aux)
		return (NULL);
	j = -1;
	while (++j != i)
		aux[j] = l[j];
	aux[j] = '\0';
	return (aux);
}

static char	*new_l(char *newline, char *l, char **line)
{
	char	*aux;

	aux = ft_strdup(&newline[1]);
	*line = handle_line(l);
	free(l);
	l = NULL;
	l = ft_strdup(aux);
	free(aux);
	aux = NULL;
	return (l);
}

static void	read_bytes(int fd, char *b, char **l)
{
	int		nbytes;
	char	*aux;

	nbytes = read(fd, b, BUFFER_SIZE);
	while (nbytes > 0)
	{
		b[nbytes] = '\0';
		*l = ft_swap(*l, b);
		aux = ft_strchr(*l, '\n');
		if (aux != NULL)
			break ;
		nbytes = read(fd, b, BUFFER_SIZE);
	}
}

int	get_next_line(int fd, char **line, char **b, char **l)
{
	char		*aux;

	if (!*l)
		*l = ft_strdup("");
	*b = malloc(BUFFER_SIZE + 1);
	if (!*b || fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	read_bytes(fd, *b, l);
	free(*b);
	*b = NULL;
	aux = ft_strchr(*l, '\n');
	if (aux != NULL)
	{
		*l = new_l(aux, *l, line);
		if (*l != NULL)
			return (1);
	}
	free(*line);
	*line = ft_strdup(*l);
	free(*l);
	*l = NULL;
	return (0);
}
