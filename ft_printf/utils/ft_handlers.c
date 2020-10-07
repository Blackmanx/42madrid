/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:11:25 by prodrigo          #+#    #+#             */
/*   Updated: 2020/10/07 14:29:40 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_symbol(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
	|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_isflag(int c)
{
	return ((c == '.') || (c == '*') || (c == '0') || (c == '-') || (c == ' '));
}

int	ft_flaghandle(int c, t_flags f, va_list args)
{
	int handletype;

	handletype = 0;
	if (c == 'c')
		handletype = ft_handle_char(va_arg(args, int), f);
	else if (c == '%')
		handletype += ft_handle_percent(f);
	else if (c == 'p')
		handletype = ft_handle_pointer(va_arg(args, unsigned long long), f);
	else if (c == 's')
		handletype = ft_handle_string(va_arg(args, char *), f);
	else if ((c == 'i') || (c == 'd'))
		handletype = ft_handle_int(va_arg(args, int), f);
	else if (c == 'x')
		handletype += ft_handle_hex(va_arg(args, unsigned int), 1, f);
	else if (c == 'X')
		handletype += ft_handle_hex(va_arg(args, unsigned int), 0, f);
	else if (c == 'u')
		handletype += ft_handle_uint((unsigned int)va_arg(args, unsigned int)
		, f);
	return (handletype);
}
