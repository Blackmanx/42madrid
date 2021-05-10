/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 02:23:23 by prodrigo          #+#    #+#             */
/*   Updated: 2020/03/03 04:46:54 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t l)
{
	size_t	len;
	size_t	n;

	n = 0;
	len = ft_strlen(needle);
	if (ft_strlen(haystack) < len)
		return (NULL);
	if (!needle[0])
		return ((char *)haystack);
	while ((n + len) <= l && *haystack)
	{
		if (ft_strncmp(haystack, needle, len) == 0)
			return ((char *)haystack);
		haystack++;
		n++;
	}
	return (NULL);
}
