/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 03:47:42 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 13:58:47 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar_c(char c, t_flags flags)
{
	int i;

	i = -1;
	if (flags.fminus)
	{
		ft_putchar(c);
		while (++i < flags.prec - 1)
			ft_putchar(' ');
		return (i + 1);
	}
	else if (flags.prec > 0 && !flags.fminus)
	{
		while (++i < flags.prec - 1)
			ft_putchar(' ');
		ft_putchar(c);
		return (i + 1);
	}
	return (ft_putchar(c));
}

int		ft_putpercent(char c, t_flags flags)
{
	int i;

	i = -1;
	if (flags.fminus)
	{
		ft_putchar(c);
		while (++i < flags.prec - 1)
			ft_putchar(' ');
		return (i + 1);
	}
	else if (flags.prec > 0 && flags.fzero)
	{
		while (++i < flags.prec - 1)
			ft_putchar('0');
		ft_putchar(c);
		return (i + 1);
	}
	else if (flags.prec > 0 && !flags.fminus)
	{
		while (++i < flags.prec - 1)
			ft_putchar(' ');
		ft_putchar(c);
		return (i + 1);
	}
	return (ft_putchar(c));
}
