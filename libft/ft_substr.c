/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 03:31:05 by prodrigo          #+#    #+#             */
/*   Updated: 2023/05/03 00:45:07 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (len > (s_len - start))
		len = s_len - start;
	if (start > s_len)
		return (ft_strdup(""));
	aux = (char *)ft_calloc((len + 1), sizeof(*s));
	if (!aux)
		return (NULL);
	ft_strlcpy(aux, &((char *)s)[start], (len + 1));
	return (aux);
}
