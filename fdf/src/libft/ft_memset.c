/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 00:55:07 by prodrigo          #+#    #+#             */
/*   Updated: 2020/03/04 16:25:23 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*baux;
	size_t			i;

	i = 0;
	baux = (unsigned char *)b;
	while (i < len)
	{
		baux[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
