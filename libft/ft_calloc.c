/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:59:00 by prodrigo          #+#    #+#             */
/*   Updated: 2023/05/03 00:30:30 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*new;
	size_t			i;
	unsigned int	new_size;

	i = 0;
	new_size = count * size;
	new = malloc(new_size);
	if (!new)
	{
		free(new);
		return (NULL);
	}
	while (new_size > 0)
	{
		new[i] = 0;
		new_size--;
		i++;
	}
	return ((void *)new);
}
