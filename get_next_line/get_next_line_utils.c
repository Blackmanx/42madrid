/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 02:58:22 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/29 05:02:51 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_bzero(void *mem, size_t n)
{
	char	*aux;
	size_t	i;

	aux = (char *)mem;
	i = 0;
	while (i < n)
	{
		aux[i] = 0;
		i++;
	}
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (mem)
	{
		ft_bzero(mem, count * size);
		return (mem);
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s[i] = s2[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strrchr(char *s, int c)
{
	int		n;
	char	aux;

	aux = (char)c;
	n = ft_strlen(s);
	if (aux == NULL)
		return ((char *)&s[n]);
	while (n >= 0)
	{
		if (s[n] == aux)
			return ((char *)&s[n]);
		n--;
	}
	return (NULL);
}
