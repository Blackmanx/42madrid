/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 03:54:35 by prodrigo          #+#    #+#             */
/*   Updated: 2021/04/27 18:35:22 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**resmem(char const *s, char c)
{
	char	*tab;
	char	**aux;
	int		i;

	i = 0;
	tab = (char *)s;
	while (*tab)
	{
		while (*tab == c)
			tab++;
		if (*tab != '\0')
			i++;
		while (*tab != c && *tab)
			tab++;
	}
	aux = (char **)malloc((i + 1) * sizeof(char *));
	if (aux == NULL)
		return (NULL);
	aux[i] = NULL;
	return (aux);
}

static char	**copydata(const char *s, char c)
{
	size_t	len;
	char	**aux;
	int		i;

	i = 0;
	len = 0;
	aux = resmem(s, c);
	if (aux == NULL)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			while (s[len] != c && s[len])
				len++;
			aux[i++] = ft_substr(s, 0, len);
			s += len;
		}
		len = 0;
	}
	aux[i] = NULL;
	return (aux);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = copydata(s, c);
	return (res);
}
