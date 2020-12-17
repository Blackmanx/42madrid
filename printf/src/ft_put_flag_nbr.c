/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flag_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 01:22:15 by mrubio            #+#    #+#             */
/*   Updated: 2020/10/28 01:33:41 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		print_width(long n, t_flg *flags)
{
	int x;
	int siz;
	int i;

	x = 0;
	i = flags->first;
	siz = (flags->second > ft_nblen(n)) ? flags->second : ft_nblen(n);
	i -= siz + (n < 0);
	if (n < 0 && flags->alig == 0 && flags->zero == 1)
		x += ft_putchar('-');
	if (n == 0 && flags->second == 0)
		i++;
	if (flags->zero == 1)
		while (i-- > 0)
			x += ft_putchar('0');
	else
		while (i-- > 0)
			x += ft_putchar(' ');
	if (n < 0 && flags->alig == 0 && flags->zero == 0)
		x += ft_putchar('-');
	return (x);
}

int		print_sign(long n)
{
	int x;

	x = 0;
	if (n < 0)
		x += ft_putchar('-');
	return (x);
}

int		print_num(long n, t_flg *flags)
{
	int x;

	x = 0;
	if (n < 0)
		n *= -1;
	if (n == 0 && flags->dot == 1 && flags->second == -1 && flags->ast == 1)
		x += ft_putchar('0');
	if (n == 0 && flags->second == 0)
		return (x);
	x += ft_putnbr(n);
	return (x);
}

int		print_prec(long n, t_flg *flags)
{
	int x;
	int i;

	i = flags->second;
	x = 0;
	if (n == 0 && flags->dot == 1 && flags->second == 0)
		return (x);
	while (i > ft_nblen(n))
	{
		x += ft_putchar('0');
		i--;
	}
	return (x);
}

int		ft_put_flag_nbr(long n, t_flg flags)
{
	int x;

	x = 0;
	if (flags.dot == 1 && flags.second == -1 && flags.ast != -1)
		flags.second = 0;
	if (flags.second > -1)
		flags.zero = 0;
	if (flags.alig == 0)
	{
		x += print_width(n, &flags);
		x += print_prec(n, &flags);
		x += print_num(n, &flags);
	}
	else
	{
		flags.zero = 0;
		x += print_sign(n);
		x += print_prec(n, &flags);
		x += print_num(n, &flags);
		x += print_width(n, &flags);
	}
	return (x);
}
