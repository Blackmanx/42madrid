/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:43:56 by prodrigo          #+#    #+#             */
/*   Updated: 2020/09/21 13:04:37 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
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

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux;

	if (!s)
		return (NULL);
	if (!(aux = (char *)malloc(sizeof(char) * ((int)len + 1))))
		return (NULL);
	ft_bzero(aux, len);
	if (start <= (unsigned int)ft_strlen(s))
		ft_strlcpy(aux, s + start, len + 1);
	return (aux);
}

char	*ft_strchr(const char *s, int c)
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
