/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:42:40 by prodrigo          #+#    #+#             */
/*   Updated: 2019/10/10 20:22:46 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char n);

void	ft_print_comb(void)
{
	int a;
	int b;
	int c;

	a = 0;
	while (a < 7)
	{
		b = a + 1;
		while (b < 8)
		{
			c = b + 1;
			while (c < 9)
			{
				ft_putchar(a + '0', b + '0', c + '0');
				if (a != 7 && b != 8 && c != 9)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
				c++;
			}
			b++;
		}
		a++;
	}
}

void	ft_putchar(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}
