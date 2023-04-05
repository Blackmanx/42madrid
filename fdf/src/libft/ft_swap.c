/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:04:48 by prodrigo          #+#    #+#             */
/*   Updated: 2023/04/05 12:06:01 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_swap(char *l, char *buf)
{
	char	*aux;

	aux = ft_strjoin(l, buf);
	free(l);
	l = NULL;
	l = ft_strdup(aux);
	free(aux);
	aux = NULL;
	return (l);
}
