/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 04:00:59 by prodrigo          #+#    #+#             */
/*   Updated: 2021/04/27 18:51:49 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	boolneg(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

void	assign_vars(int *aux, int *len, int *neg, int *n)
{
	*aux = *n;
	*len = 1;
	*neg = 0;
}

void	aux_handler(int *aux, int *len)
{
	while (aux > 0)
	{
		*aux /= 10;
		*len += 1;
	}
}

char	*ft_itoa(int n)
{
	int		aux;
	int		len;
	int		neg;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	assign_vars(&aux, &len, &neg, &n);
	boolneg(&n, &neg);
	aux_handler(&aux, &len);
	len += neg;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
