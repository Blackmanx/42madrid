/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 11:52:43 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/17 19:01:34 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_replace(char **str, int i, char **line, char *buf)
{
	char	*aux;

	(*str)[i] = '\0';
	*line = ft_strdup(*str);
	free(buf);
	if (ft_strlen(*str + i + 1) > 0)
	{
		aux = ft_strdup(*str + i + 1);
		free(*str);
		*str = aux;
	}
	else
		ft_bzero(*str, ft_strlen(*str));
	return (1);
}

static int	ft_getnewline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_eof(char **str, char **line)
{
	int		eofi;

	eofi = ft_getnewline(*str);
	if (*str && eofi > -1)
		return (ft_replace(str, eofi, line, NULL));
	else
	{
		*line = *str;
		*str = NULL;
	}
	return (0);
}

static void	ft_joinandfree(char **str, char *buf)
{
	char	*aux;

	aux = ft_strjoin(*str, buf);
	free(*str);
	*str = aux;
}

int	get_next_line(int fd, char **line)
{
	static char		*str[4096];
	char			*buf;
	int				i;
	int				bytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || fd > 4095 || !line || BUFFER_SIZE <= 0 || !buf)
		return (-1);
	bytes = 1;
	while (bytes > 0)
	{
		ft_byteshandler(&str, buf, fd, bytes);
		i = ft_getnewline(str[fd]);
		if (i > -1)
			return (ft_replace(&str[fd], i, line, buf));
	}
	free(buf);
	if (bytes < 0)
		return (-1);
	if (bytes == 0 && str[fd])
		return (ft_eof(&str[fd], line));
	*line = ft_strdup("");
	return (0);
}
