/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:59:05 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 01:29:49 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*u_itoa(unsigned long int n)
{
	int						i;
	unsigned long int		aux;
	char					*num;

	aux = n;
	i = 1;
	while (aux >= 10)
	{
		i++;
		aux /= 10;
	}
	if (!(num = malloc(i + 1)))
		return (NULL);
	num[i] = 0;
	while (n >= 10)
	{
		i--;
		num[i] = 48 + n % 10;
		n /= 10;
	}
	num[--i] = 48 + n % 10;
	return (num);
}

static char		*u_int_itoa(unsigned int n)
{
	char					*num;
	int						i;
	unsigned long int		aux;

	aux = n;
	i = 1;
	while (aux >= 10)
	{
		i++;
		aux /= 10;
	}
	if (!(num = malloc(i + 1)))
		return (NULL);
	num[i] = 0;
	while (n >= 10)
	{
		i--;
		num[i] = 48 + n % 10;
		n /= 10;
	}
	num[--i] = 48 + n % 10;
	return (num);
}

char			*u_long_itoa(unsigned long long int n)
{
	char					*num;
	int						i;
	unsigned long long int	aux;

	aux = n;
	i = 1;
	while (aux >= 10)
	{
		i++;
		aux /= 10;
	}
	if (!(num = malloc(i + 1)))
		return (NULL);
	num[i] = 0;
	while (n >= 10)
	{
		i--;
		num[i] = 48 + n % 10;
		n /= 10;
	}
	num[--i] = 48 + n % 10;
	return (num);
}

void			handle_unsigned(t_flags *flags, va_list al, int *size)
{
	char					*aux;

	if (!flags->fll && !flags->fhh)
		aux = u_int_itoa(va_arg(al, unsigned int));
	else if (flags->fll == 1)
		aux = u_itoa(va_arg(al, unsigned long int));
	else if (flags->fll == 2)
		aux = u_long_itoa(va_arg(al, unsigned long long int));
	else if (flags->fhh == 2)
		aux = u_int_itoa((unsigned char)va_arg(al, unsigned int));
	else
		aux = u_int_itoa((unsigned short)va_arg(al, unsigned int));
	handle(size, flags, aux);
}
