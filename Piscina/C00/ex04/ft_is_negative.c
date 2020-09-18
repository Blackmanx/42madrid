/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:34:04 by prodrigo          #+#    #+#             */
/*   Updated: 2019/10/10 21:18:54 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char n);

void	ft_is_negative(int n)
{
	char c;

	if (n < 0)
	{
		c = 'N';
	}
	else
	{
		c = 'P';
	}
	ft_putchar(c);
}

void	ft_putchar(char n)
{
	write(1, &n, 1);
}
