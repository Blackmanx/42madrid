/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 01:42:37 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 01:47:07 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_align(t_flags *flags, int *size, int l)
{
	while (flags->fspace-- > l)
	{
		ft_putstr_fd(" ", 1);
		(*size)++;
	}
}

static void	handle_zero(t_flags *flags, int *size, int l)
{
	while (flags->fspace-- > l)
	{
		ft_putstr_fd("0", 1);
		(*size)++;
	}
}

static void	handle_point(t_flags *flags, char *str)
{
	while (flags->fwidth-- > 0)
	{
		ft_putchar_fd(*str, 1);
		str++;
	}
}

int			handle_string(t_flags flags, va_list al, int *size)
{
	char	*str;
	int		l;

	str = va_arg(ap, char*);
	if (!str)
	{
		str = ft_strdup("(null)");
	}
	if (flags->fpoint && flags->fwidth < (int)ft_strlen(str))
		l = (flags->fwidth >= 0 ? flags->fwidth
			: ft_strlen(str));
	else
		l = ft_strlen(str);
	if (flags->falign)
		handle_align(flags, size, l);
	if (flags->fzero)
		handle_zero(flags, size, l);
	if (flags->fpoint && flags->fwidth == l)
		handle_point(str, flags);
	else
		ft_putstr_fd(str, 1);
	if (flags->fminus)
		handle_align(size, flags, l);
	*size += l;
	return (1);
}
