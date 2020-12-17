/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 22:34:50 by mrubio            #+#    #+#             */
/*   Updated: 2020/10/28 01:32:52 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_print_mem(long nb)
{
	if (nb < 10)
		return (ft_putnbr(nb));
	else if (nb == 10)
		return (ft_putchar('a'));
	else if (nb == 11)
		return (ft_putchar('b'));
	else if (nb == 12)
		return (ft_putchar('c'));
	else if (nb == 13)
		return (ft_putchar('d'));
	else if (nb == 14)
		return (ft_putchar('e'));
	else if (nb == 15)
		return (ft_putchar('f'));
	return (0);
}

int		ft_putmem(long addr, t_flg flags)
{
	int x;

	x = 0;
	if (addr == 0 && flags.dot == 1 && flags.second == 0)
		return (x);
	if (addr > 15)
		x += ft_putmem((addr / 16), flags);
	x += ft_print_mem(addr % 16);
	return (x);
}
