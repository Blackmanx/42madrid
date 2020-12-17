/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flag_mem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:27:01 by mrubio            #+#    #+#             */
/*   Updated: 2020/10/28 01:37:03 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_memlen(long n)
{
	int x;

	x = 0;
	if (n >= 0)
		x = 2;
	while ((n / 16) != 0)
	{
		x++;
		n /= 16;
	}
	x++;
	return (x);
}

int		print_width_mem(unsigned long n, t_flg *flags)
{
	int x;
	int siz;
	int i;

	x = 0;
	i = flags->first;
	siz = (flags->second > ft_memlen(n)) ? flags->second : ft_memlen(n);
	i -= siz;
	if (n == 0 && flags->second == 0)
		i++;
	if (flags->zero == 1)
		while (i-- > 0)
			x += ft_putchar('0');
	else
		while (i-- > 0)
			x += ft_putchar(' ');
	return (x);
}

int		print_prec_mem(long n, t_flg *flags)
{
	int x;
	int i;

	i = flags->second;
	x = 0;
	while (i > (ft_memlen(n) - 2))
	{
		x += ft_putchar('0');
		i--;
	}
	return (x);
}

int		ft_put_flag_mem(unsigned long addr, t_flg flags)
{
	int x;

	x = 0;
	if (flags.dot == 1 && flags.second == -1 && flags.ast != -1)
		flags.second = 0;
	if (flags.second > -1)
		flags.zero = 0;
	if (flags.alig == 0)
	{
		x += print_width_mem((unsigned long)addr, &flags);
		x += ft_putstr("0x");
		x += print_prec_mem((unsigned long)addr, &flags);
		x += ft_putmem((unsigned long)addr, flags);
	}
	else
	{
		flags.zero = 0;
		x += ft_putstr("0x");
		x += print_prec_mem((unsigned long)addr, &flags);
		x += ft_putmem((unsigned long)addr, flags);
		x += print_width_mem((unsigned long)addr, &flags);
	}
	return (x);
}
