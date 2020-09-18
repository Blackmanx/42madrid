/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 01:01:47 by prodrigo          #+#    #+#             */
/*   Updated: 2020/03/04 16:24:48 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
