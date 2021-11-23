/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 03:48:02 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 13:58:45 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		flags_handle(const char *str, t_flags flags, va_list va)
{
	int i;

	i = 0;
	while (str[i])
	{
		flags = init_flags(flags, 0);
		if (str[i] == '%')
		{
			flags = check_flags(&str[i + 1], flags, va, &i);
			flags.len += check_type(&str[i + 1], flags, va, &i);
		}
		else
			flags.len += ft_putchar(str[i]);
		if (str[i])
			i++;
	}
	return (flags);
}

t_flags		init_flags(t_flags flags, int reinit)
{
	if (reinit == 1)
		flags.len = 0;
	flags.prec = -1;
	flags.fpoint = -1;
	flags.fminus = 0;
	flags.fzero = 0;
	return (flags);
}

int			ft_printf(const char *format, ...)
{
	va_list	va;
	t_flags	flags;

	flags.len = 0;
	flags = init_flags(flags, 1);
	va_start(va, format);
	flags = flags_handle(format, flags, va);
	va_end(va);
	return (flags.len);
}
