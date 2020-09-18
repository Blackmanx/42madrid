/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:11:47 by prodrigo          #+#    #+#             */
/*   Updated: 2019/10/24 14:20:43 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int		ft_strlen(char *src);

unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int		c;

	c = 0;
	if (size != 0)
	{
		while (c < size - 1 && src[c] != '\0')
		{
			dest[c] = src[c];
			c++;
		}
		while (ft_strlen(src) > c)
		{
			dest[c] = '\0';
			c++;
		}
	}
	dest[c] = '\0';
	return (ft_strlen(src));
}

unsigned int		ft_strlen(char *src)
{
	unsigned int		n;

	n = 0;
	while (src[n] != '\0')
	{
		n++;
	}
	return (n);
}
