/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 21:28:26 by prodrigo          #+#    #+#             */
/*   Updated: 2020/03/03 03:23:31 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*aux;
	unsigned int	n;

	if (!s)
		return (NULL);
	aux = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!aux)
		return (NULL);
	n = 0;
	while (s[n])
	{
		aux[n] = f(n, s[n]);
		n++;
	}
	aux[n] = '\0';
	return (aux);
}
