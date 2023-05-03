/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 00:55:07 by prodrigo          #+#    #+#             */
/*   Updated: 2023/05/02 23:38:26 by prodrigo         ###   ########.fr       */
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
