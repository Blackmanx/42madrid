/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 03:47:53 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 04:45:29 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putnbr(int n)
{
	long	num;
	int		i;
	int		aux;
	char	arr[10];

	num = n;
	if (num == 0)
		return (ft_putchar('0'));
	if (num < 0)
		num = -num;
	i = 0;
	while (num > 0)
	{
		arr[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	aux = i;
	while (--i >= 0)
		ft_putchar(arr[i]);
	return (aux);
}

int		ft_putnbr_u(int n)
{
	unsigned int	num;
	int				i;
	int				aux;
	char			arr[10];

	num = n;
	if (num == 0)
		return (ft_putchar('0'));
	i = 0;
	while (num > 0)
	{
		arr[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	aux = i;
	while (--i >= 0)
		ft_putchar(arr[i]);
	return (aux);
}

int		ft_putstr(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		ft_putchar(s[i]);
	return (i);
}
