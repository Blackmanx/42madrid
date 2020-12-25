/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 03:47:48 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 04:41:42 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	extens(long int prec, t_flags flags, int *ix, int type)
{
	if (type == 1)
	{
		*ix += 1;
		if (prec >= 0)
			flags.fpoint = prec;
	}
	else
	{
		if (prec < 0)
		{
			flags.prec = -prec;
			flags.fminus = 1;
		}
		else
			flags.prec = prec;
	}
	return (flags);
}

t_flags	flagpnbr(const char *str, t_flags flags, int *ix, va_list va)
{
	int		i;
	char	*nbr;

	if (str[0] == '*')
		return (extens(va_arg(va, int), flags, ix, 1));
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i > 0)
	{
		if (!(nbr = malloc(sizeof(char) * (i + 1))))
			return (flags);
	}
	else if (i == 0)
	{
		flags.fpoint = 0;
		return (flags);
	}
	i = -1;
	while (str[++i] >= '0' && str[i] <= '9')
		nbr[i] = str[i];
	tonull(nbr, i, ix);
	flags.fpoint = ft_atoi(nbr);
	free(nbr);
	return (flags);
}

t_flags	check_prec(const char *str, t_flags flags, va_list va, int *ix)
{
	int		i;
	char	*nbr;

	if (str[0] == '*')
		return (extens(va_arg(va, int), flags, ix, 0));
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i > 0)
	{
		if (!(nbr = malloc(sizeof(char) * (i + 1))))
			return (flags);
	}
	else
		return (flags);
	i = -1;
	while (str[++i] >= '0' && str[i] <= '9')
		nbr[i] = str[i];
	nbr[i] = '\0';
	flags.prec = ft_atoi(nbr);
	free(nbr);
	*ix += i - 1;
	return (flags);
}

t_flags	check_flags(const char *str, t_flags flags, va_list va, int *ix)
{
	int		i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '.'
		|| str[i] == '*')
	{
		if (str[i] == '0' && i == 0)
			flags.fzero = 1;
		else if (str[i] == '-')
			flags.fminus = 1;
		else if (str[i] == '.')
			flags = flagpnbr(&str[i + 1], flags, &i, va);
		else if ((((str[i] > '0' && str[i] <= '9') || str[i] == '*')
			&& str[i - 1] != '.'))
			flags = check_prec(&str[i], flags, va, &i);
		i++;
	}
	*ix += i;
	return (flags);
}

int		check_type(const char *str, t_flags flags, va_list va, int *ix)
{
	*ix += 1;
	if (str[0] == 'd' || str[0] == 'i')
		return (put_fnbr(flags, va));
	if (str[0] == 'c')
		return (ft_putchar_c(va_arg(va, int), flags));
	if (str[0] == 's')
		return (ft_putstr_prec(va_arg(va, char *), flags));
	if (str[0] == 'u')
		return (put_uint(flags, va));
	if (str[0] == 'p')
		return (f_p(to_ucase(ft_itoa_b_a(va_arg(va, intptr_t), flags)), flags));
	if (str[0] == 'x')
		return (ft_putstr_hex(to_ucase(ft_itoa_base(va_arg(va, int))), flags));
	if (str[0] == 'X')
		return (ft_putstr_hex(ft_itoa_base(va_arg(va, int)), flags));
	if (str[0] == '%')
		return (ft_putpercent('%', flags));
	return (0);
}
