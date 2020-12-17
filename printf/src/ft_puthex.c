/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 00:06:04 by mrubio            #+#    #+#             */
/*   Updated: 2020/10/28 01:33:03 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_print_numhex(unsigned int nb, int mayus)
{
	if (nb < 10)
		return (ft_putnbr(nb));
	else if (nb == 10)
		return (ft_putchar('a' - mayus));
	else if (nb == 11)
		return (ft_putchar('b' - mayus));
	else if (nb == 12)
		return (ft_putchar('c' - mayus));
	else if (nb == 13)
		return (ft_putchar('d' - mayus));
	else if (nb == 14)
		return (ft_putchar('e' - mayus));
	else if (nb == 15)
		return (ft_putchar('f' - mayus));
	return (0);
}

int		ft_puthex(unsigned int n, int mayus, t_flg flags)
{
	int x;

	x = 0;
	if (n == 0 && flags.dot == 1 && flags.second == 0)
		return (x);
	if (n > 15)
		x += ft_puthex((n / 16), mayus, flags);
	x += ft_print_numhex((n % 16), mayus);
	return (x);
}
