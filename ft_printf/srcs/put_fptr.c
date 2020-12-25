/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 03:53:07 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 13:58:49 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_adress(unsigned long long nval, int count, char *res)
{
	char			*base;

	base = "0123456789ABCDEF";
	if ((nval < 16 && 16 != 10) || (16 == 10 && nval > -10 && nval < 10))
	{
		if (!(res = malloc(sizeof(char) * (count + 4))))
			return (NULL);
		res[count + 1] = 'x';
		res[count + 2] = '0';
		res[count + 3] = '\0';
	}
	else
		res = ft_itoa_adress(nval / 16, count + 1, res);
	res[count] = base[nval % 16];
	return (res);
}

char	*ft_itoa_b_a(unsigned long long nval, t_flags flags)
{
	char	*res;

	res = NULL;
	if (nval == 0 && flags.fpoint == 0)
	{
		if (!(res = malloc(sizeof(char) * 3)))
			return (NULL);
		res[0] = 'x';
		res[1] = '0';
		res[2] = '\0';
	}
	else
		res = ft_itoa_adress(nval, 0, res);
	if (res == NULL)
		return (NULL);
	return (str_reverse(res));
}

int		put_ptrptr(char *s, t_flags flags, int l, int type)
{
	int size;

	size = 0;
	if (type == 1)
	{
		while (l++ < flags.prec)
			size += ft_putchar(' ');
		size += ft_putstr(s);
	}
	else
	{
		while (l++ < flags.fpoint)
			size += ft_putchar('0');
		size += ft_putstr(s);
		while (l++ <= flags.prec)
			size += ft_putchar(' ');
	}
	return (size);
}

int		put_ptrprec(char *s, t_flags flags, int l, int type)
{
	int size;
	int i;

	i = -1;
	size = 0;
	if (type == 1)
		while (++i < flags.prec)
			size += ft_putchar(' ');
	else if (type == 0)
	{
		while (++i < flags.prec - fptlen(l, flags))
			size += ft_putchar(' ');
		while (l++ < flags.fpoint)
			size += ft_putchar('0');
		size += ft_putstr(s);
	}
	else
	{
		while (l++ < flags.prec)
			size += ft_putchar('0');
		size += ft_putstr(s);
	}
	return (size);
}

int		f_p(char *s, t_flags flags)
{
	int l;
	int size;

	if (!s)
		return (0);
	size = 0;
	l = ft_strlen(s);
	if (flags.fpoint == 0 && ft_strlen(s) == 1 && s[0] == '0')
		size += put_ptrprec(s, flags, l, 1);
	else if (flags.fzero && (flags.fpoint == -1 && !flags.fminus))
		size += put_ptrprec(s, flags, l, 2);
	else if (!flags.fminus && flags.fpoint == 0 && flags.prec)
		size += put_ptrptr(s, flags, l, 1);
	else if (!flags.fminus && (flags.prec >= 0 || flags.fpoint >= 0))
		size += put_ptrprec(s, flags, l, 0);
	else if (flags.fminus)
		size += put_ptrptr(s, flags, l, 0);
	else
		size += ft_putstr(s);
	free(s);
	return (size);
}
