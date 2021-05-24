/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 21:02:46 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/24 21:02:47 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b2;
	size_t			i;

	i = 0;
	b2 = (unsigned char *)b;
	while (i < len)
	{
		b2[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
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

char	*ft_swap(char *l, char *buf)
{
	char	*temp;

	temp = ft_strjoin(l, buf);
	free(l);
	l = NULL;
	l = ft_strdup(temp);
	free(temp);
	temp = NULL;
	return (l);
}
