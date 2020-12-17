/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flag_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 19:46:28 by mrubio            #+#    #+#             */
/*   Updated: 2020/10/28 01:37:16 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_hexlen(unsigned int n)
{
	int x;

	x = 0;
	while ((n / 16) != 0)
	{
		x++;
		n /= 16;
	}
	x++;
	return (x);
}

int		print_width_hex(unsigned int n, t_flg *flags)
{
	int x;
	int siz;
	int i;

	x = 0;
	i = flags->first;
	siz = (flags->second > ft_hexlen(n)) ? flags->second : ft_hexlen(n);
	i -= siz + (n < 0);
	if (n == 0 && flags->second == 0)
		i++;
	if (flags->zero == 1)
		while (i-- > 0)
			x += ft_putchar('0');
	else
		while (i-- > 0)
			x += ft_putchar(' ');
	if (n < 0 && flags->alig == 0 && flags->zero == 0)
		ft_putchar('-');
	return (x);
}

int		print_sign_hex(unsigned int n)
{
	int x;

	x = 0;
	if (n < 0)
		x += ft_putchar('-');
	return (x);
}

int		print_prec_hex(unsigned int n, t_flg *flags)
{
	int x;
	int i;

	i = flags->second;
	x = 0;
	while (i > ft_hexlen(n))
	{
		x += ft_putchar('0');
		i--;
	}
	return (x);
}

int		ft_put_flag_hex(unsigned int n, int mayus, t_flg flags)
{
	int x;

	x = 0;
	if (flags.second > -1)
		flags.zero = 0;
	if (flags.alig == 0)
	{
		x += print_width_hex(n, &flags);
		x += print_prec_hex(n, &flags);
		x += ft_puthex(n, mayus, flags);
	}
	else
	{
		flags.zero = 0;
		x += print_sign_hex(n);
		x += print_prec_hex(n, &flags);
		x += ft_puthex(n, mayus, flags);
		x += print_width_hex(n, &flags);
	}
	return (x);
}
