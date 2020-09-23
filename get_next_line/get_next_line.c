/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 11:52:43 by prodrigo          #+#    #+#             */
/*   Updated: 2020/09/23 13:36:37 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_buffering(char *sarr, char **line, int bytes)
{
	unsigned int	i;
	char			*aux;

	i = 0;
	while (sarr[i] && sarr[i] != '\n')
		i++;
	if (i < ft_strlen(sarr))
	{
		*line = ft_substr(sarr, 0, i);
		aux = ft_substr(sarr, i + 1, ft_strlen(sarr));
		free(sarr);
		sarr = ft_strdup(aux);
		free(aux);
	}
	else if (bytes == 0)
	{
		*line = sarr;
		sarr = NULL;
	}
	return (sarr);
}

char				*ft_replace(char *buf, char *sarr)
{
	char			*aux;

	if (sarr)
	{
		aux = ft_strjoin(sarr, buf);
		free(sarr);
		sarr = ft_strdup(aux);
		free(aux);
	}
	else
		sarr = ft_strdup(buf);
	return (sarr);
}

int					get_next_line(int fd, char **line)
{
	static char		*sarr[4096];
	char			buf[BUFFER_SIZE + 1];
	int				bytes;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		sarr[fd] = ft_replace(buf, sarr[fd]);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (bytes <= 0 && !sarr[fd])
	{
		*line = ft_strdup("");
		return (bytes);
	}
	sarr[fd] = ft_buffering(sarr[fd], line, bytes);
	if (bytes <= 0 && !sarr[fd])
		return (bytes);
	return (1);
}
