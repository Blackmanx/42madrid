/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 21:28:26 by prodrigo          #+#    #+#             */
/*   Updated: 2023/05/02 23:38:14 by prodrigo         ###   ########.fr       */
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
