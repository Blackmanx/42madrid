/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 02:58:27 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/30 15:39:46 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *str)
{
	char	*buffer;
	int		read_bytes;

	if (ft_strchr(str, '\n'))
		return (str);
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	read_bytes = 1;
	while (!ft_strchr(str, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
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
		return (NULL);
	l = next_line(str);
	str = remove_line(str);
	return (l);
}

