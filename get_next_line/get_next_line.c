/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 11:52:43 by prodrigo          #+#    #+#             */
/*   Updated: 2020/09/21 13:04:06 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			ft_strdel(char **del)
{
	if (del && *del)
	{
		free(*del);
		*del = NULL;
	}
}

/*
** * DESCRIPTION
** Description of function
** * @param myParam
** Description of params
** * RETURN VALUE
** Restored string with the static variable.
*/

char			*ft_restore(char *s1, char *s2)
{
	char		*aux;
	size_t		s1_len;
	size_t		s2_len;

	s1_len = 0;
	s2_len = ft_strlen(s2);
	if (s1)
		s1_len = ft_strlen(s1);
	if (!(aux = (char *)malloc((s1_len + s2_len + 1) * sizeof(char))))
		return (NULL);
	if (s1)
	{
		ft_strlcpy(aux, s1, (s1_len + 1));
		ft_strdel(&s1);
	}
	ft_strlcpy(aux + s1_len, s2, s2_len + 1);
}

/*
** * DESCRIPTION
** Determines if we find a new line in the static variable
** * @param myParam
** Description of params
** * RETURN VALUE
** Explain what do you return
*/

int				ft_findline(char **lock, char **line)
{
	char		*newline;
	size_t		pos;
	size_t		len;

	len = 0;
	newline = NULL;
	if ((newline = ft_strchr(*lock, '\n')))
	{
		pos = newline - *lock;
		len = ft_strlen(newline);
		*line = ft_substr(*lock, 0, pos);
		ft_strlcpy(*lock, (newline + 1), (len + 1));
		return (1);
	}
	return (0);
}

/*
** * DESCRIPTION
** Description of function
** * @param myParam
** Description of params
** * RETURN VALUE
** Explain what do you return
*/

int				get_next_line(int fd, char **line)
{
	int			bytes;
	char		buf[BUFFER_SIZE + 1];
	static char	*lock;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (lock && ft_findline(&lock, line) == 1)
		return (1);
	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		if (!(lock = ft_restore(lock, buf)))
			return (-1);
		if (ft_findline(&lock, line) == 1)
			return (1);
	}
	if (lock && *lock)
		*line = ft_strdup(lock);
	else
		*line = ft_strdup("");
	ft_strdel(&lock);
	return (bytes);
}
