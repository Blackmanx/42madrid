/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 02:58:27 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/30 16:28:04 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *str)
{
	char	*buf;
	int		read_bytes;

	if (ft_strchr(str, '\n'))
		return (str);
	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	read_bytes = 1;
	while (!ft_strchr(str, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*next_line(char *str)
{
	int		i;
	char	*l;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	l = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		l[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		l[i] = '\n';
	return (l);
}

char	*remove_line(char *str)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	aux = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
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
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = read_file(fd, str);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	l = next_line(str);
	str = remove_line(str);
	return (l);
}
