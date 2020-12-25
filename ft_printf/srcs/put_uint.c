/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 03:56:05 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 13:58:51 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_len(int nb)
{
	unsigned int	nbr;
	int				i;

	nbr = nb;
	i = 0;
	while (1)
	{
		nbr /= 10;
		i++;
		if (nbr == 0)
			return (i);
	}
}

int	put_u_prec(t_flags flags, int nb, int l, int type)
{
	int	max;

	max = 0;
	if (type == 1)
	{
		while (l++ < flags.prec)
			max += ft_putchar('0');
		max += ft_putnbr_u(nb);
		return (max);
	}
	else if (type == 2)
	{
		while (l++ < flags.prec)
			max += ft_putchar(' ');
		if (nb != 0)
			max += ft_putnbr_u(nb);
		else
			max += ft_putchar(' ');
		return (max);
	}
	while (l++ < flags.fpoint)
		max += ft_putchar('0');
	while (l++ <= flags.prec + 1)
		max += ft_putchar(' ');
	return (max);
}

int	put_u_point(t_flags flags, int nb, int l, int type)
{
	int max;
	int i;

	i = -1;
	max = 0;
	if (type == 1)
	{
		while (++i < flags.prec - fptlen(l, flags))
			max += ft_putchar(' ');
		while (l++ < flags.fpoint)
			max += ft_putchar('0');
		max += ft_putnbr_u(nb);
	}
	else
	{
		while (l++ < flags.fpoint)
			max += ft_putchar('0');
		max += ft_putnbr_u(nb);
		while (l++ <= flags.prec)
			max += ft_putchar(' ');
	}
	return (max);
}

int	put_uint(t_flags flags, va_list va)
{
	int nb;
	int l;
	int print;

	print = 0;
	nb = va_arg(va, int);
	if (nb < 0)
		nb = nb + 4294967296;
	if (nb == 0 && (flags.fpoint == 0 && flags.prec <= 0))
		return (0);
	l = u_len(nb);
	if (flags.fzero && (flags.fpoint == -1 && !flags.fminus))
		print += put_u_prec(flags, nb, l, 1);
	else if (!flags.fminus && flags.fpoint == 0 && flags.prec)
		print += put_u_prec(flags, nb, l, 2);
	else if (!flags.fminus && (flags.prec >= 0 || flags.fpoint >= 0))
		print += put_u_point(flags, nb, l, 1);
	else if (flags.fminus && nb == 0 && flags.fpoint == 0)
		print += put_u_prec(flags, nb, l, 0);
	else if (flags.fminus)
		print += put_u_point(flags, nb, l, 0);
	else
		print += ft_putnbr_u(nb);
	return (print);
}
