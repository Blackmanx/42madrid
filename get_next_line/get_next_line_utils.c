/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:43:56 by prodrigo          #+#    #+#             */
/*   Updated: 2020/09/21 14:05:32 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strdup(const char *s1)
{
	char	*aux;
	int		i;

	if (!(aux = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		aux[i] = s1[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

size_t		ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux;
	size_t	max_len;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	max_len = ft_strlen(s);
	if (start >= max_len)
		return (ft_strdup(""));
	if (!(aux = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i] != '\0')
	{
		aux[j] = s[i];
		j++;
		i++;
	}
	aux[j] = '\0';
	return (aux);
}

char		*ft_strchr(const char *s, int c)
{
	char	aux;
	int		n;

	aux = (char)c;
	n = 0;
	while (s[n])
	{
		if (s[n] == aux)
			return ((char *)&s[n]);
		n++;
	}
	if (!s[n] && aux == '\0')
		return ((char *)&s[n]);
	return (NULL);
}

char		*ft_strjoin(char const *s1, char const *s2)
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
