/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:12:38 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 02:23:37 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		identify(t_flags *flags, va_list vl)
{
	int size;

	size = 0;
	if (flags->ftype == 'c')
		size += ptext_char(va_arg(vl, int), flags);
	else if (flags->ftype == 's')
		size += ptext_str(va_arg(vl, char *), flags);
	else if (flags->ftype == 'p')
		size += put_ptr(va_arg(vl, unsigned long long), flags);
	else if (chrstr(flags->ftype, "di"))
		size += pnum_d(va_arg(vl, int), flags);
	else if (flags->ftype == 'u')
		size += pnum_u((unsigned int)va_arg(vl, unsigned int), flags);
	else if (flags->ftype == 'x')
		size += put_hex(va_arg(vl, unsigned int), flags, 0);
	else if (flags->ftype == 'X')
		size += put_hex(va_arg(vl, unsigned int), flags, 1);
	else if (flags->ftype == '%')
		size += ptext_char('%', flags);
	return (size);
}
