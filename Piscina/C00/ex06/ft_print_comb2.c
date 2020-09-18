/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:27:26 by prodrigo          #+#    #+#             */
/*   Updated: 2019/10/10 18:48:25 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char n);

void	ft_printpair(int c)
{
	int	a;
	int	b;

	if (c > 9)
	{
		a = c / 10;
		b = c % 10;
		ft_putchar(a + '0');
		ft_putchar(b + '0');
	}
	else
	{
		ft_putchar('0');
		ft_putchar(c + '0');
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_printpair(a);
			ft_putchar(' ');
			ft_printpair(b);
			if (a < 98 || b < 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			b++;
		}
		a++;
	}
}

void	ft_putchar(char n)
{
	write(1, &n, 1);
}
