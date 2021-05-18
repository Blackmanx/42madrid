/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 01:34:28 by prodrigo          #+#    #+#             */
/*   Updated: 2021/04/21 19:27:01 by prodrigo         ###   ########.fr       */
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
