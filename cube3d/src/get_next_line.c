/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:58:09 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 20:58:11 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/cub3d.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s;
	int		p;
	int		p2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s == NULL)
		return (NULL);
	p = 0;
	while (s1[p])
	{
		s[p] = s1[p];
		p++;
	}
	p2 = 0;
	while (s2[p2])
	{
		s[p] = s2[p2];
		p++;
		p2++;
	}
	s[p] = '\0';
	return (s);
}

static char	*ft_temp(char *l)
{
	int		p;
	int		k;
	char	*temp;

	p = 0;
	while (l[p] && l[p] != '\n')
		p++;
	temp = (char *)malloc(sizeof(char) * (p + 1));
	if (!temp)
		return (NULL);
	k = 0;
	while (k != p)
	{
		temp[k] = l[k];
		k++;
	}
	temp[k] = '\0';
	return (temp);
}

static char	*ft_newstatic(char *aux, char *l, char **line)
{
	char	*aux2;

	aux2 = ft_strdup(&aux[1]);
	*line = ft_temp(l);
	free(l);
	l = NULL;
	l = ft_strdup(aux2);
	free(aux2);
	aux2 = NULL;
	return (l);
}

static void	auxiliar(int fd, char *b, char **stc)
{
	int		nbytes;
	char	*aux;

	nbytes = read(fd, b, BUFFER_SIZE);
	while (nbytes > 0)
	{
		b[nbytes] = '\0';
		*stc = ft_swap(*stc, b);
		aux = ft_strchr(*stc, '\n');
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
	auxiliar(fd, *b, l);
	free(*b);
	aux = ft_strchr(*l, '\n');
	if (aux != NULL)
	{
		*l = ft_newstatic(aux, *l, line);
		if (*l != NULL)
			return (1);
	}
	free(*line);
	*line = ft_strdup(*l);
	free(*l);
	*l = NULL;
	return (0);
}
