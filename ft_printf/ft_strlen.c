/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 04:00:59 by prodrigo          #+#    #+#             */
/*   Updated: 2020/03/04 16:20:02 by prodrigo         ###   ########.fr       */
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

char			*ft_itoa(int n)
{
	int		aux;
	int		len;
	int		neg;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	aux = n;
	len = 1;
	neg = 0;
	boolneg(&n, &neg);
	while (aux /= 10)
		len++;
	len += neg;
	if ((str = (char*)malloc(sizeof(char) * len + 1)) == NULL)
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
