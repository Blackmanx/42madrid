/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 01:45:50 by prodrigo          #+#    #+#             */
/*   Updated: 2020/03/03 03:22:48 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	aux;
	int		n;

	aux = (char)c;
	n = 0;
	while (s[n])
	{
		if (s[n] == aux)
			return ((char *)&s[n]);
		n++;
	}
	if (!s[n] && aux == '\0')
		return ((char *)&s[n]);
	return (NULL);
}
