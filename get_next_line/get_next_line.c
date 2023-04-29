/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 02:58:27 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/29 05:01:30 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_file(int fd, char *str)
{
	char	*buf;
	int		bytes;

	if (ft_strchr(str, NEW_LINE))
		return (str);
	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	bytes = 1;
	while (!(ft_strchr(str, NEW_LINE)) && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

static char	*next_line(char *str)
{
	char	*l;
	int		i;

	i = 0;
	if (str[i])
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
	char	*aux;
	int		i;
	int		j;
	int		new_len;

	i = 0;
	while (str[i] && str[i] != NEW_LINE)
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_len = ft_strlen(str) - i + 1;
	aux = ft_calloc(new_len, sizeof(char));
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
		return (NULL);
	str = read_file(fd, str);
	if (!str)
		return (NULL);
	l = next_line(str);
	str = remove_line(str);
	return (NULL);
}
