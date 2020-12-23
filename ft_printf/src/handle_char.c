/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 23:59:09 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 02:19:11 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putchar_space(t_flags *flags, int *size)
{
	while (flags->fspace-- > 1)
	{
		ft_putchar_fd(' ', 1);
		(*size)++;
	}
}

static void	putchar_zero(t_flags *flags, int *size)
{
	while (flags->fspace-- > 1)
	{
		ft_putchar_fd('0', 1);
		(*size)++;
	}
}

void		handle_char(char chr, t_flags *flags, va_list al, int *size)
{
	if (!flags->fzero && flags->fminus)
		putchar_space(flags, size);
	if (flags->fzero)
		putchar_zero(flags, size);
	(*size)++;
	if (chr == 'c')
		ft_putchar_fd((char)va_arg(al, int), 1);
	else
		ft_putchar_fd('%', 1);
	if (flags->fminus)
		putchar_space(flags, size);
}
