/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 03:53:22 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 13:58:49 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	numlen(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		nb *= -1;
	while (1)
	{
		nb /= 10;
		i++;
		if (nb == 0)
			return (i);
	}
}

int	putnum_prec(t_flags flags, int nb, int type, int l)
{
	int t;
	int size;

	size = 0;
	t = (nb >= 0) ? 0 : 1;
	if (type == 1)
	{
		if (nb < 0)
			size += ft_putchar('-');
		while (l++ < flags.prec - t)
			size += ft_putchar('0');
		size += ft_putnbr(nb);
	}
	else
	{
		while (l++ < flags.prec - t)
			size += ft_putchar(' ');
		if (nb < 0)
			size += ft_putchar('-');
		if (nb != 0)
			size += ft_putnbr(nb);
		else
			size += ft_putchar(' ');
	}
	return (size);
}

int	putnum_pnt(t_flags flags, int nb, int type, int l)
{
	int i;
	int t;
	int size;

	size = 0;
	t = (nb >= 0) ? 0 : 1;
	i = -1;
	if (type == 1)
	{
		while (++i < flags.prec - fptlen(l, flags) - t)
			size += ft_putchar(' ');
		if (nb < 0)
			size += ft_putchar('-');
		while (l++ < flags.fpoint)
			size += ft_putchar('0');
		size += ft_putnbr(nb);
	}
	else
	{
		if (nb < 0)
			size += ft_putchar('-');
		size += ft_putnbr(nb);
	}
	return (size);
}

int	putnum_precpnt(t_flags flags, int nb, int type, int l)
{
	int t;
	int size;

	size = 0;
	t = (nb >= 0) ? 0 : 1;
	if (type == 1)
	{
		if (nb < 0)
			size += ft_putchar('-');
		while (l++ < flags.fpoint)
			size += ft_putchar('0');
		size += ft_putnbr(nb);
		while (l++ <= flags.prec - t)
			size += ft_putchar(' ');
	}
	else
	{
		while (l++ < flags.fpoint)
			size += ft_putchar('0');
		while (l++ <= flags.prec + 1)
			size += ft_putchar(' ');
	}
	return (size);
}

int	put_fnbr(t_flags flags, va_list va)
{
	int nb;
	int l;
	int size;

	size = 0;
	nb = va_arg(va, int);
	if (nb == 0 && (flags.fpoint == 0 && flags.prec <= 0))
		return (0);
	l = numlen(nb);
	if (flags.fzero && (flags.fpoint == -1 && !flags.fminus))
		size += putnum_prec(flags, nb, 1, l);
	else if (!flags.fminus && flags.fpoint == 0 && flags.prec)
		size += putnum_prec(flags, nb, 0, l);
	else if (!flags.fminus && (flags.prec >= 0 || flags.fpoint >= 0))
		size += putnum_pnt(flags, nb, 1, l);
	else if (flags.fminus && nb == 0 && flags.fpoint == 0)
		size += putnum_precpnt(flags, nb, 0, l);
	else if (flags.fminus)
		size += putnum_precpnt(flags, nb, 1, l);
	else
		size += putnum_pnt(flags, nb, 0, l);
	return (size);
}
