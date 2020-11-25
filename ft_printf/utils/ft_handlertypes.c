/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlertypes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:02:58 by prodrigo          #+#    #+#             */
/*   Updated: 2020/11/25 13:50:01 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int			pf_handle_char(char c, t_flags f)
{
	int i;

	i = 0;
	if (f.minus == 1)
		ft_putchar(c);
	i = ft_handle_width(f.width, 1, 0);
	if (f.minus == 0)
		ft_putchar(c);
	return (i + 1);
}

int			pf_handle_width(int width, int minus, int zero)
{
	int i;

	i = 0;
	while (width > minus)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		i++;
	}
	return (i);
}

int			pf_handle_percent(t_flags f)
{
	int i;

	i = 0;
	if (f.minus == 1)
		i += pf_putsp("%", 1);
	i += pf_handle_width(f.width, 1, f.zero);
	if (f.minus == 0)
		i += pf_putsp("%", 1);
	return (i);
}

static int	pf_input(char *str, t_flags f)
{
	int i;

	i = 0;
	if (f.dot >= 0)
	{
		i += pf_handle_width(f.dot, pf_strlen(str), 0);
		i += pf_putsp(str, f.dot);
	}
	else
		i += pf_putsp(str, pf_strlen(str));
	return (i);
}

int			pf_handle_string(char *str, t_flags f)
{
	int i;

	i = 0;
	if (!str)
		str = "(null)";
	if (f.dot >= 0 && (size_t)f.dot > ft_strlen(str))
		f.dot = ft_strlen(str);
	if (f.minus == 1)
		i += pf_input(str, f);
	if (f.dot >= 0)
		i += pf_handle_width(f.width, f.dot, 0);
	else
		i += pf_handle_width(f.width, ft_strlen(str), 0);
	if (f.minus == 0)
		i += pf_input(str, f);
	return (i);
}
