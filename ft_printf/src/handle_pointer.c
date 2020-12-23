/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 01:29:28 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 02:19:06 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putchar_fspace(char **str, t_flags *flags, int *size)
{
	if (flags->fwidth > (int)ft_strlen(*str) - 2)
		flags->fspace -= flags->fwidth + 2;
	else
		flags->fspace -= ft_strlen(*str);
	while (flags->fspace > 0)
	{
		ft_putchar_fd(' ', 1);
		(*size)++;
		flags->fspace--;
	}
}

static void	putchar_fpoint(char **str, t_flags *flags, int *size)
{
	if (!flags->falign)
		flags->fspace -= ft_strlen(*str);
	if (flags->fpoint)
		flags->fspace -= 2;
	while (flags->fspace-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*size)++;
	}
}

static void	putchar_fzero(char **str, t_flags *flags, int *size)
{
	int		*n;

	if (flags->fzero)
		n = &flags->fspace;
	else
		n = &flags->fwidth;
	ft_putchar_fd(**str, 1);
	(*str)++;
	ft_putchar_fd(**str, 1);
	(*str)++;
	*size += 2;
	if (flags->fzero)
		*n -= 2;
	while (*n > (int)ft_strlen(*str))
	{
		ft_putchar_fd('0', 1);
		(*size)++;
		flags->fspace--;
		flags->fwidth--;
	}
}

int			handle_pointer(char **str, t_flags *flags, int *size)
{
	if (!str)
		return (0);
	if (!ft_strncmp("0x0", *str, 4) && !flags->fwidth)
		if (flags->fpoint)
		{
			free(*str);
			*str = "0x";
		}
	if (flags->falign)
		putchar_fspace(str, flags, size);
	if (flags->fpoint || flags->fzero)
		putchar_fzero(str, flags, size);
	ft_putstr_fd(*str, 1);
	*size += ft_strlen(*str);
	if (flags->flag_minus)
		putchar_fpoint(str, flags, size);
	return (1);
}
