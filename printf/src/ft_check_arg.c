/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 03:02:30 by mrubio            #+#    #+#             */
/*   Updated: 2020/10/28 01:24:34 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

long		ft_abs(long n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int			ft_check_arg(char *s, va_list args, t_flg flags, t_pf *print)
{
	int z;
	int r;

	r = 0;
	z = 0;
	if (s[z] == 'c')
		r += ft_put_flag_char(va_arg(args, int), flags);
	else if (s[z] == 's')
		r += ft_put_flag_str(va_arg(args, char*), flags);
	else if (s[z] == 'd' || s[z] == 'i')
		r += ft_put_flag_nbr(va_arg(args, int), flags);
	else if (s[z] == 'u')
		r += ft_putnbr_abs(va_arg(args, unsigned int), flags);
	else if (s[z] == 'x')
		r += ft_put_flag_hex(va_arg(args, unsigned int), 0, flags);
	else if (s[z] == 'X')
		r += ft_put_flag_hex(va_arg(args, unsigned int), 32, flags);
	else if (s[z] == '%')
		r += ft_put_flag_char('%', flags);
	else if (s[z] == 'p')
		r += ft_put_flag_mem((unsigned long)va_arg(args, void *), flags);
	else
		print->none = 1;
	return (r);
}
