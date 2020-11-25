/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 13:11:25 by prodrigo          #+#    #+#             */
/*   Updated: 2020/11/25 14:19:23 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	pf_symbol(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
	|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	pf_isflag(int c)
{
	return ((c == '.') || (c == '*') || (c == '0') || (c == '-') || (c == ' '));
}

int	pf_flaghandle(int c, t_flags f, va_list args)
{
	int handletype;

	handletype = 0;
	if (c == 'c')
		handletype = pf_handle_char(va_arg(args, int), f);
	else if (c == '%')
		handletype += pf_handle_percent(f);
	else if (c == 'p')
		handletype = pf_handle_pointer(va_arg(args, unsigned long long), f);
	else if (c == 's')
		handletype = pf_handle_string(va_arg(args, char *), f);
	else if ((c == 'i') || (c == 'd'))
		handletype = pf_handle_int(va_arg(args, int), f);
	else if (c == 'x')
		handletype += pf_handle_hex(va_arg(args, unsigned int), 1, f);
	else if (c == 'X')
		handletype += pf_handle_hex(va_arg(args, unsigned int), 0, f);
	else if (c == 'u')
		handletype += pf_handle_uint((unsigned int)va_arg(args, unsigned int)
		, f);
	return (handletype);
}
