/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 01:11:38 by prodrigo          #+#    #+#             */
/*   Updated: 2020/03/04 16:25:51 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*daux;
	unsigned char	*saux;

	daux = (unsigned char *)dst;
	saux = (unsigned char *)src;
	if ((!dst && !src) || len < 1)
		return (dst);
	if (saux < daux)
	{
		while (len != 0)
		{
			len--;
			daux[len] = saux[len];
		}
	}
	else
		ft_memcpy(daux, saux, len);
	return (dst);
}
