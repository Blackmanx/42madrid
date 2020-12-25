/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <sfournio@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:22:54 by sfournio          #+#    #+#             */
/*   Updated: 2020/12/17 12:59:56 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_recursive(int val, int count, char *result)
{
	char			*base;
	unsigned int	value;

	base = "0123456789ABCDEF";
	value = val;
	if ((value < 16 && 16 != 10) || (16 == 10 && value > -10 && value < 10))
	{
		if (!(result = malloc(sizeof(char) * (count + 2))))
			return (NULL);
		result[count + 1] = '\0';
	}
	else
		result = ft_itoa_recursive(value / 16, count + 1, result);
	result[count] = base[value % 16];
	return (result);
}

char	*ft_itoa_base(int value)
{
	char	*result;

	result = NULL;
	if (value < 0)
		value = value + 4294967296;
	result = ft_itoa_recursive(value, 0, result);
	if (result == NULL)
		return (NULL);
	return (ft_strrev(result));
}

int		put_hex_2(char *s, t_global infos, int l, int type)
{
	int print;

	print = 0;
	if (type == 1)
	{
		while (l++ < infos.precision)
			print += ft_putchar(' ');
		print += ft_putstr(s);
	}
	else
	{
		while (l++ < infos.flagp)
			print += ft_putchar('0');
		print += ft_putstr(s);
		while (l++ <= infos.precision)
			print += ft_putchar(' ');
	}
	return (print);
}

int		put_hex_1(char *s, t_global infos, int l, int type)
{
	int print;
	int i;

	i = -1;
	print = 0;
	if (type == 1)
		while (++i < infos.precision)
			print += ft_putchar(' ');
	else if (type == 0)
	{
		while (++i < infos.precision - pointlen(l, infos))
			print += ft_putchar(' ');
		while (l++ < infos.flagp)
			print += ft_putchar('0');
		print += ft_putstr(s);
	}
	else
	{
		while (l++ < infos.precision)
			print += ft_putchar('0');
		print += ft_putstr(s);
	}
	return (print);
}

int		ft_putstr_hex(char *s, t_global infos)
{
	int l;
	int print;

	if (!s)
		return (0);
	print = 0;
	l = ft_strlen(s);
	if (infos.flagp == 0 && ft_strlen(s) == 1 && s[0] == '0')
		print += put_hex_1(s, infos, l, 1);
	else if (infos.flagz && (infos.flagp == -1 && !infos.flagm))
		print += put_hex_1(s, infos, l, 2);
	else if (!infos.flagm && infos.flagp == 0 && infos.precision)
		print += put_hex_2(s, infos, l, 1);
	else if (!infos.flagm && (infos.precision >= 0 || infos.flagp >= 0))
		print += put_hex_1(s, infos, l, 0);
	else if (infos.flagm)
		print += put_hex_2(s, infos, l, 0);
	else
		print += ft_putstr(s);
	free(s);
	return (print);
}
