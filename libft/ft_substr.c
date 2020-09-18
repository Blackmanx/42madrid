/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 03:31:05 by prodrigo          #+#    #+#             */
/*   Updated: 2020/03/03 03:34:26 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux;

	if (!s)
		return (NULL);
	if (!(aux = (char *)malloc(sizeof(char) * ((int)len + 1))))
		return (NULL);
	ft_bzero(aux, len);
	if (start <= (unsigned int)ft_strlen(s))
		ft_strlcpy(aux, s + start, len + 1);
	return (aux);
}
