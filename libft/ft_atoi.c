/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 19:40:10 by prodrigo          #+#    #+#             */
/*   Updated: 2021/04/21 19:30:01 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				x;
	long int		neg;
	long int		num;

	x = 0;
	neg = 1;
	num = 0;
	while (str[x] == '\t' || str[x] == '\n' || str[x] == '\v'
		|| str[x] == '\f' || str[x] == '\r' || str[x] == ' ')
		x++;
	if (str[x] == '-' && str[x + 1] >= '0' && str[x + 1] <= '9')
		neg = -1;
	if (str[x] == '+' || str[x] == '-')
		x++;
	while (str[x] && str[x] >= '0' && str[x] <= '9')
	{
		num = num * 10 + (int)(str[x] - '0');
		if (num * neg > 2147483647)
			return (-1);
		if (num * neg < -2147483648)
			return (0);
		x++;
	}
	return (num * neg);
}
