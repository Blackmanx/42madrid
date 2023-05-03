/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 01:16:51 by prodrigo          #+#    #+#             */
/*   Updated: 2023/05/02 23:38:28 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	aux;
	size_t			i;

	str = (unsigned char *)s;
	aux = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == aux)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
