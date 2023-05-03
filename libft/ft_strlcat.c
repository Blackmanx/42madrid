/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 01:34:28 by prodrigo          #+#    #+#             */
/*   Updated: 2023/05/02 23:38:17 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	n;
	size_t	m;

	n = 0;
	if (dstsize < ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	while (dst[n] && n < dstsize)
		n++;
	m = n;
	while (src[n - m] && (n + 1) < dstsize)
	{
		dst[n] = src[n - m];
		n++;
	}
	dst[n] = '\0';
	return (ft_strlen(src) + m);
}
