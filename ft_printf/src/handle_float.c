/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:18:36 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 02:44:01 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_length(int n, int *length)
{
	*length = 1;
	while (n >= 10)
	{
		length /= 10;
		(*length)++;
	}
}

static int	negative(char **str, float *f, int *i, int *length)
{
	int		negnum;

	negnum = (int)*f;
	if (f < 0)
	{
		*f *= -1;
		negnum *= -1;
		if (negnum == 0)
		{
			*str[0] = '-';
			(*i)++;
			(*length)++;
		}
	}
	return (negnum);
}

static void	to_string(char *str, float *f, int length, char size)
{
	int		i;
	char	*aux;
	int		negnum;

	i = 0;
	negnum = toneg(&str, &f, &i, &length);
	aux = ft_itoa(negnum);
	while (*aux)
	{
		str[i] = *aux;
		aux++;
		i++;
	}
	length += size + 1;
	str[i++] = '.';
	while (i < length)
	{
		f = f - (float)negnum;
		f *= 10;
		negnum = (int)f;
		aux = ft_itoa(negnum);
		str[i++] = *aux;
	}
	str[i] = 0;
}

void		handle_float(t_flags *flags, va_list al, int *size)
{
	char	*str;
	int		length;
	double	n;

	n = va_arg(al, double);
	get_length((int)n, &length);
	if (flags->fpoint)
	{
		str = malloc(flags->fwidth + length + 2);
		to_string(str, n, length, flags->fwidth);
	}
	else
	{
		str = malloc(length + 8);
		to_string(str, n, length, 6);
	}
	ft_putstr_fd(str, 1);
	*size += ft_strlen(str);
	free(str);
}
