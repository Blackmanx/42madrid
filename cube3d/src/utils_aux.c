/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:02:41 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 21:02:42 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

char	*ft_strchr(const char *s, int c)
{
	char	aux;
	int		pos;

	aux = (char)c;
	pos = 0;
	while (s[pos])
	{
		if (s[pos] == aux)
			return ((char *)&s[pos]);
		pos++;
	}
	if (!s[pos] && aux == '\0')
		return ((char *)&s[pos]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	while (s1[pos] && s2[pos] && s1[pos] == s2[pos] && pos < n)
		pos++;
	if (s1[pos] != s2[pos] && pos < n)
		return (((unsigned char)s1[pos] - (unsigned char)s2[pos]));
	return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l;
	size_t	lend;

	lend = 0;
	if (dstsize < ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	while (dst[lend] && lend < dstsize)
		lend++;
	l = lend;
	while (src[lend - l] && (lend + 1) < dstsize)
	{
		dst[lend] = src[lend - l];
		lend++;
	}
	dst[lend] = '\0';
	return (ft_strlen(src) + l);
}
