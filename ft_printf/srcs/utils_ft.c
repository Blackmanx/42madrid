/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 03:53:34 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 13:58:52 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *str)
{
	char	*aux;
	int		i;

	if (!(aux = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		aux[i] = str[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}

int		ft_atoi(const char *str)
{
	int				x;
	long int		neg;
	long int		num;

	x = 0;
	neg = 1;
	num = 0;
	while (str[x] == '\t' || str[x] == '\n' || str[x] == '\v' ||
			str[x] == '\f' || str[x] == '\r' || str[x] == ' ')
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
