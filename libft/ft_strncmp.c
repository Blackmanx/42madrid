/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 02:34:58 by prodrigo          #+#    #+#             */
/*   Updated: 2023/05/02 23:38:13 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		*aux;
	unsigned char		*aux2;

	i = 0;
	aux = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	while (aux[i] && aux2[i] && (i < n - 1) && aux[i] == aux2[i])
		i++;
	if (!(n <= 0))
		return (aux[i] - aux2[i]);
	else
		return (0);
}
