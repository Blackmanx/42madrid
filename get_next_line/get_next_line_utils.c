/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:43:56 by prodrigo          #+#    #+#             */
/*   Updated: 2020/09/28 13:41:22 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strdup(const char *s1)
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

size_t			ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void			ft_bzero(void *s, size_t n)
{
	char	*aux;
	size_t	i;

	aux = (char *)s;
	i = 0;
	while (i < n)
	{
		aux[i] = 0;
		i++;
	}
}

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*daux;
	unsigned char	*saux;
	size_t			i;

	daux = (unsigned char *)dst;
	saux = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		daux[i] = saux[i];
		i++;
	}
	return (dst);
}

char			*ft_strjoin(char const *s1, char const *s2)
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
