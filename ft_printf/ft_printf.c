/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 20:55:43 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/22 21:50:34 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** * DESCRIPTION
** Initializes flags variables from t_flags structure
** * @param flags
** Flags structure, we use them to control if certain
** conditions have been met.
** * RETURN VALUE
** Void, you do not return anything.
*/

static void		set_flagsdefault(t_flags *flags)
{
	flags->fminus = 0;
	flags->fzero = 0;
	flags->fpoint = 0;
	flags->falign = 0;
	flags->fplus = 0;
	flags->fll = 0;
	flags->fsharp = 0;
	flags->fspaces = 0;
	flags->fwidth = 0;
	flags->fhh = 0;
}

/*
** * DESCRIPTION
** Sets the minus or zero flags to 1, depending of what
** the pointer returns
** * @param str
** Modifyable char** pointer we use for format at printf.
** * @param flags
** Flags structure, we use them to control if certain
** conditions have been met.
** * RETURN VALUE
** Void, you do not return anything.
*/

static void		set_flags_mz(char **str, t_flags *flags)
{
	if (**str == '-')
	{
		flags->fzero = 0;
		flags->fminus = 1;
	}
	if (**str == '0' && !flags->fminus)
		flags->fzero = 1;
	if (**str == '+')
		flags->fplus = 1;
	if (**str == ' ')
		flags->fplus = 2;
	if (**str == '#')
		flags->fhash = 1;
	(*str)++;
}

/*
** * DESCRIPTION
** Searchs for flags and calls handlers.
** * @param str
** Modifyable char** pointer we use for format at printf.
** * @param flags
** Flags structure, we use them to control if certain
** conditions have been met.
** * @param al
** The magic va_list that stores the variable-length list
** of arguments.
** * RETURN VALUE
** Void, you do not return anything or a void value.
*/

static void		flags_handle(char **str, t_flags *flags, va_list al)
{
	if (!al)
		return ;
	while (**str == '0' || **str == '-' || **str == '+' ||
		**str == ' ' || **str == '#')
		set_flags_mz(str, flags);
	if ((**str == '*') || ft_isdigit(**str))
	{
		if (flags->fminus)
			fminus_handle(str, flags, al);
		else if (flags->fzero)
			fzero_handle(str, flags, al);
		else
			fempty_handle(str, flags, al);
	}
	if (**str == '.')
		fpoint_handle(str, flags, al);
}

/*
** * DESCRIPTION
** Finds a % char, then sets flags to 0 and handles flags.
** After that, it calls conversion handlers. If it couldn't
** find a %, then it prints the character.
** * @param str
** Modifyable char** pointer we use for format at printf.
** * @param flags
** Flags structure, we use them to control if certain
** conditions have been met.
** * @param al
** The magic va_list that stores the variable-length list
** of arguments.
** * @param size
** Size of what you are printing.
** * RETURN VALUE
** Void, you do not return anything or a void value.
*/

static void		find_percent(char **str, t_flags *flags, va_list al, int *size)
{
	if (**str == '%')
	{
		(*str)++;
		set_flagsdefault(flags);
		flags_handle(str, flags, al);
		handle_types(str, flags, al, size);
	}
	else
	{
		ft_putchar_fd(**str, 1);
		(*size)++;
	}
}

/*
** * DESCRIPTION
** Main function, calls find_percent() until the string ends.
** * @param *format
** Format follows this prototype:
** %[flags][width][.precision][length]type
** * @param ...
** Whatever you want printed.
** * RETURN VALUE
** Return the number of characters written.
*/

int				ft_printf(const char *format, ...)
{
	char	*str;
	t_flags	flags;
	va_list	al;
	int		size;

	str = (char*)format;
	size = 0;
	va_start(al, format);
	while (*str)
	{
		find_percent(&str, &flags, al, &size);
		if (!*str)
			break ;
		str++;
	}
	va_end(al);
	return (size);
}
