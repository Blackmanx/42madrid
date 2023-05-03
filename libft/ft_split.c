/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 03:54:35 by prodrigo          #+#    #+#             */
/*   Updated: 2023/05/03 01:19:03 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	freeall(char **str, int j)
{
	int	i;

	i = -1;
	while (++i <= j)
		free(str[i]);
	free(str);
}

static char	*alloc_mem(char c, char const *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && c != s[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s[++i] && c != s[i])
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

static int	get_num_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && c == s[i])
			i++;
		if (s[i] && c != s[i])
			count++;
		while (s[i] && c != s[i])
			i++;
	}
	return (count);
}

static char	**check_overflow(char **str, int j)
{
	if (str[j - 1] == NULL)
	{
		freeall(str, j - 1);
		return (NULL);
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = get_num_words(s, c);
	j = 0;
	str = malloc(sizeof(char *) * (i + 1));
	if (!s || !str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		while (s[i] && c == s[i])
			i++;
		if (s[i] && c != s[i])
		{
			str[j++] = alloc_mem(c, &s[i]);
			if (check_overflow(str, j) == NULL)
				return (NULL);
			while (s[i] && c != s[i])
				i++;
		}
	}
	str[j] = 0;
	return (str);
}
