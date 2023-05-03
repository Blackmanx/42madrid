/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 03:45:49 by prodrigo          #+#    #+#             */
/*   Updated: 2023/05/02 23:38:11 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	getword(char c, const char *set)
{
	int	x;
	int	len;

	x = 0;
	len = ft_strlen(set);
	while (x < len)
	{
		if (c == set[x])
			return (1);
		x++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*dst;

	i = 0;
	j = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	while (getword(s1[i], set))
		i++;
	while (len > 0 && getword(s1[len - 1], set))
		len--;
	if (len < i)
		len = i;
	dst = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!dst)
		return (NULL);
	while (i < len)
		dst[j++] = (char)s1[i++];
	dst[j] = '\0';
	return (dst);
}
