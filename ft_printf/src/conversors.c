/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:48:06 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 02:34:56 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				chrstr(char c, char const *str)
{
	if (!c || !str)
		return (0);
	while (*str)
		if (c == *str++)
			return (1);
	return (0);
}

static	int		numi(intmax_t n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0 && ++i)
		n /= base;
	return (i);
}

static int		unumi(uintmax_t n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0 && ++i)
		n /= base;
	return (i);
}

char			*imtoa(intmax_t n, int base, int ucase)
{
	char	*str;
	int		len;

	len = numi(n, base);
	if (!(str = ft_strnew(len--)))
		return (NULL);
	if (n < 0 && (n = -n))
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n)
	{
		if (base > 10 && (n % base >= 10))
			str[len--] = (n % base) - 10 + (ucase ? 'A' : 'a');
		else
			str[len--] = (n % base) + '0';
		n /= base;
	}
	return (str);
}

char			*u_imtoa(uintmax_t n, int base, int ucase)
{
	char	*str;
	int		len;

	len = unumi(n, base);
	if (!(str = ft_strnew(len--)))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		if (base > 10 && (n % base >= 10))
			str[len--] = (n % base) - 10 + (ucase ? 'A' : 'a');
		else
			str[len--] = (n % base) + '0';
		n /= base;
	}
	return (str);
}
