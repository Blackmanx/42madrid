/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 03:31:05 by prodrigo          #+#    #+#             */
/*   Updated: 2021/04/21 19:29:37 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux;

	if (!s)
		return (NULL);
	aux = (char *)malloc(sizeof(char) * ((int)len + 1));
	if (!aux)
		return (NULL);
	ft_bzero(aux, len);
	if (start <= (unsigned int)ft_strlen(s))
		ft_strlcpy(aux, s + start, len + 1);
	return (aux);
}
