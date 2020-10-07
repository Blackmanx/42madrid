/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:10:57 by prodrigo          #+#    #+#             */
/*   Updated: 2020/10/07 14:08:27 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_initialize(void)
{
	t_flags		flags;

	flags.width = 0;
	flags.pointer = 0;
	flags.type = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	return (flags);
}

static int		ft_flags(const char *str, int i,
t_flags *f, va_list args)
{
	while (str[i])
	{
		if (!ft_symbol(str[i]) && !ft_isflag(str[i])
		&& !ft_isdigit(str[i]))
			break ;
		if (str[i] == '0' && f->width == 0 && f->minus == 0)
			f->zero = 1;
		if (str[i] == '*')
			*f = ft_width_flag(args, *f);
		if (str[i] == '.')
			i = ft_dot_flag(str, i, f, args);
		if (str[i] == '-')
			*f = ft_minus_flag(*f);
		if (ft_isdigit(str[i]))
			*f = ft_digit_flag(str[i], *f);
		if (ft_symbol(str[i]))
		{
			f->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

static int		ft_handle_input(const char *format, va_list args)
{
	int			i;
	int			count;
	t_flags		flags;

	i = 0;
	count = 0;
	while (!0)
	{
		flags = ft_initialize();
		if (!format[i])
			break ;
		else if (format[i] != '%')
			count += ft_putchar(format[i]);
		else if (format[i] == '%' && format[i + 1])
		{
			i = ft_flags(format, ++i, &flags, args);
			if (ft_symbol(format[i]))
				count += ft_flaghandle((char)flags.type, flags, args);
			else if (format[i])
				count += ft_putchar(format[i]);
		}
		i++;
	}
	return (count);
}

/*
** It's time to explain what kind of magic va_vars do.
** So, basically they are macros that manipulate a stack pointer
** You create a list (arg) that are passed to va_start, then va_arg
** pops (see: stacks) values from the stack.
*/

int				ft_printf(const char *format, ...)
{
	va_list		arg;
	int			exitcode;

	va_start(arg, format);
	exitcode = ft_handleinput(format, arg);
	va_end(arg);
	return (exitcode);
}
