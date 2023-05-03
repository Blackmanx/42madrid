/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 02:15:09 by prodrigo          #+#    #+#             */
/*   Updated: 2023/05/02 23:38:12 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		n;
	char	aux;

	aux = (char)c;
	n = ft_strlen(s);
	while (n >= 0)
	{
		if (s[n] == aux)
			return ((char *)&s[n]);
		n--;
	}
	return (NULL);
}
