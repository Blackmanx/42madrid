/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 02:58:27 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/30 17:14:31 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_file(int fd, char *str)
{
	char	*buf;
	int		read_bytes;

	if (ft_strchr(str, NEW_LINE))
		return (str);
	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	read_bytes = 1;
	while (!ft_strchr(str, NEW_LINE) && read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(str);
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

static char	*next_line(char *str)
{
	int		i;
	char	*l;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != NEW_LINE)
		i++;
	l = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (str[i] && str[i] != NEW_LINE)
	{
		l[i] = str[i];
		i++;
	}
	if (str[i] == NEW_LINE)
		l[i] = NEW_LINE;
	return (l);
}

static char	*remove_line(char *str)
{
	int		i;
	int		j;
	char	*aux;
	size_t	new_size;

	i = 0;
	while (str[i] && str[i] != NEW_LINE)
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_size = ft_strlen(str) - i + 1;
	aux = ft_calloc((new_size), sizeof(char));
	i++;
	j = 0;
	while (str[i])
		aux[j++] = str[i++];
	free(str);
	return (aux);
}

char	*get_next_line(int fd)
{
	char		*l;
	static char	*str[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	str[fd] = read_file(fd, str[fd]);
	if (!str[fd])
	{
		free(str[fd]);
		return (NULL);
	}
	l = next_line(str[fd]);
	str[fd] = remove_line(str[fd]);
	return (l);
}
