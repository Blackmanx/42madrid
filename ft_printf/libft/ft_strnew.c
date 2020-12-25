/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 02:00:48 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 02:49:47 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memalloc(size_t size)
{
	void *str;

	if (!(str = (void *)malloc(sizeof(*str) * size)))
		return (NULL);
	ft_bzero(str, size);
	return (str);
}

char		*ft_strnew(size_t size)
{
	char *str;

	if (!(str = (char *)ft_memalloc(size + 1)))
		return (NULL);
	str[size] = '\0';
	return (str);
}
