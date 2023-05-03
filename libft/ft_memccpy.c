/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 01:07:26 by prodrigo          #+#    #+#             */
/*   Updated: 2023/05/02 23:38:29 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*daux;
	unsigned char	*saux;
	unsigned char	aux;
	size_t			i;

	daux = (unsigned char *)dst;
	saux = (unsigned char *)src;
	aux = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		daux[i] = saux[i];
		if (saux[i] == aux)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
