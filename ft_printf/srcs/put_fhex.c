/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 03:56:39 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 04:34:51 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_rec(int val, int count, char *res)
{
	char			*base;
	unsigned int	nval;

	base = "0123456789ABCDEF";
	nval = val;
	if ((nval < 16 && 16 != 10) || (16 == 10 && nval > -10 && nval < 10))
	{
		if (!(res = malloc(sizeof(char) * (count + 2))))
			return (NULL);
		res[count + 1] = '\0';
	}
	else
		res = ft_itoa_rec(nval / 16, count + 1, res);
	res[count] = base[nval % 16];
	return (res);
}

char	*ft_itoa_base(int nval)
{
	char	*res;

	res = NULL;
	if (nval < 0)
		nval = nval + 4294967296;
	res = ft_itoa_rec(nval, 0, res);
	if (res == NULL)
		return (NULL);
	return (str_reverse(res));
}

int		put_hexpoint(char *s, t_flags flags, int l, int type)
{
	int print;

	print = 0;
	if (type == 1)
	{
		while (l++ < flags.prec)
			print += ft_putchar(' ');
		print += ft_putstr(s);
	}
	else
	{
		while (l++ < flags.fpoint)
			print += ft_putchar('0');
		print += ft_putstr(s);
		while (l++ <= flags.prec)
			print += ft_putchar(' ');
	}
	return (print);
}

int		put_hexprec(char *s, t_flags flags, int l, int type)
{
	int print;
	int i;

	i = -1;
	print = 0;
	if (type == 1)
		while (++i < flags.prec)
			print += ft_putchar(' ');
	else if (type == 0)
	{
		while (++i < flags.prec - fptlen(l, flags))
			print += ft_putchar(' ');
		while (l++ < flags.fpoint)
			print += ft_putchar('0');
		print += ft_putstr(s);
	}
	else
	{
		while (l++ < flags.prec)
			print += ft_putchar('0');
		print += ft_putstr(s);
	}
	return (print);
}

int		ft_putstr_hex(char *s, t_flags flags)
{
	int l;
	int print;

	if (!s)
		return (0);
	print = 0;
	l = ft_strlen(s);
	if (flags.fpoint == 0 && ft_strlen(s) == 1 && s[0] == '0')
		print += put_hexprec(s, flags, l, 1);
	else if (flags.fzero && (flags.fpoint == -1 && !flags.fminus))
		print += put_hexprec(s, flags, l, 2);
	else if (!flags.fminus && flags.fpoint == 0 && flags.prec)
		print += put_hexpoint(s, flags, l, 1);
	else if (!flags.fminus && (flags.prec >= 0 || flags.fpoint >= 0))
		print += put_hexprec(s, flags, l, 0);
	else if (flags.fminus)
		print += put_hexpoint(s, flags, l, 0);
	else
		print += ft_putstr(s);
	free(s);
	return (print);
}
