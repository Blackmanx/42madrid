/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:03:18 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/14 17:30:53 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_index(char c, const char *b)
{
	int	n;

	n = 0;
	while (*b && *b != c && ++n)
		b++;
	return (n);
}

static int	strtoint(const char *aux, const char *b, long int pow,
	int len)
{
	int	num;

	num = 0;
	while (*aux)
	{
		num += get_index(*aux, b) * pow;
		pow /= len;
		aux++;
	}
	return (num);
}

static int	get_len(const char *b)
{
	int	len;

	len = 0;
	while (b[len])
	{
		if (ft_strchr(&b[len + 1], b[len]))
			return (0);
		len++;
	}
	return (len);
}

int	ft_atoib(const char *str, const char *b)
{
	char			*aux;
	int				len;
	long int		pow;

	pow = 1;
	len = get_len(b);
	if (len < 2)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '-' && str++)
		pow = -1;
	else if (*str == '+')
		str++;
	aux = (char *)str;
	while (*str && ft_strchr(b, *str))
	{
		pow *= len;
		str++;
	}
	pow /= len;
	return (strtoint(aux, b, pow, len));
}
