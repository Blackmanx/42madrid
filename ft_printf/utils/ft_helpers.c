/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:54:39 by prodrigo          #+#    #+#             */
/*   Updated: 2020/11/25 13:54:39 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	pf_putsp(char *str, int precision)
{
	int i;

	i = 0;
	while (str[i] && i < precision)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}