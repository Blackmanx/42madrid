/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 04:00:59 by prodrigo          #+#    #+#             */
/*   Updated: 2023/05/02 23:38:37 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		digits = 1;
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		module;

	module = 0;
	len = ft_digits(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
		str[0] = '-';
	while (n)
	{
		len--;
		module = ft_abs(n % 10);
		str[len] = module + '0';
		n /= 10;
	}
	return (str);
}
