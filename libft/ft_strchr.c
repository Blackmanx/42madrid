/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 01:45:50 by prodrigo          #+#    #+#             */
/*   Updated: 2023/05/02 23:38:18 by prodrigo         ###   ########.fr       */
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
