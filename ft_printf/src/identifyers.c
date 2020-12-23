/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifyers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:47:27 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 00:01:38 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** * DESCRIPTION
** Looks for a hh, h, ll or l flag.
** * @param str
** Modifyable char** pointer we use for format at printf.
** * @param flags
** Flags structure, we use them to control if certain
** conditions have been met.
** * RETURN VALUE
** No return values/void value.
*/

static void		handle_fbonus(char **str, t_flags *flags)
{
	if (!ft_strncmp(*str, "hh", 2))
	{
		flags->fhh = 2;
		*str += 2;
	}
	else if (**str == 'h')
	{
		flags->fhh = 1;
		(*str)++;
	}
	else if (!ft_strncmp(*str, "ll", 2))
	{
		flags->fll = 2;
		*str += 2;
	}
	else if (**str == 'l')
	{
		flags->fll = 1;
		(*str)++;
	}
}

/*
** * DESCRIPTION
** Looks for hex/pointer types, then handles them
** accordingly. Also handles bonus flags.
** * @param str
** Modifyable char** pointer we use for format at printf.
** * @param flags
** Flags structure, we use them to control if certain
** conditions have been met.
** * @param al
** The magic va_list that stores the variable-length list
** of arguments.
** * @param size
** Size of what you are printing
** * RETURN VALUE
** Integer, 1 if a type was found, 0 if not.
*/

static int		handle_others(char **str, t_flags *flags, va_list al, int size)
{
	char	*aux;
	char	*itoa;

	handle_fbonus(str, flags);
	if (**str == 'x' || **str == 'X')
	{
		handle_hex(str, flags, al, size);
		return (1);
	}
	if (**str == 'p')
	{
		itoa = hex_itoa(va_arg(ap, unsigned long), 0);
		aux = ft_strjoin("0x", itoa);
		handle_pointer(size, flags, &aux);
		free(itoa);
		return (1);
	}
	return (0);
}

/*
** * DESCRIPTION
** Looks for number types then handles them accordingly.
** * @param str
** Modifyable char** pointer we use for format at printf.
** * @param flags
** Flags structure, we use them to control if certain
** conditions have been met.
** * @param al
** The magic va_list that stores the variable-length list
** of arguments.
** * @param size
** Size of what you are printing
** * RETURN VALUE
** Integer, 1 if a type was found, 0 if not.
*/

static int		handle_nums(char **str, t_flags *flags, va_list al, int size)
{
	if (**str == 'i' || **str == 'd')
	{
		handle_int(flags, al, size);
		return (1);
	}
	if (**str == 'u')
	{
		handle_unsignedint(flags, al, size);
		return (1);
	}
	if (**str == 'f')
	{
		handle_float(flags, al, size);
		return (1);
	}
	return (0);
}

/*
** * DESCRIPTION
** Looks for string/char types, then handles them accordingly.
** * @param str
** Modifyable char** pointer we use for format at printf.
** * @param flags
** Flags structure, we use them to control if certain
** conditions have been met.
** * @param al
** The magic va_list that stores the variable-length list
** of arguments.
** * @param size
** Size of what you are printing
** * RETURN VALUE
** Integer, 1 if a type was found, 0 if not.
*/

static int		handle_text(char **str, t_flags *flags, va_list al, int size)
{
	if (**str == 'c' || **str == '%')
	{
		handle_char(**str, flags, al, size);
		return (1);
	}
	if (**str == 's')
	{
		handle_string(flags, al, size);
		return (1);
	}
	return (0);
}

/*
** * DESCRIPTION
** Calls for other functions to look for types, as specified in the
** format parameter in ft_printf (%[flags][width][.precision][length]"type")
** If no type was found, prints whatever character was read.
** * @param str
** Modifyable char** pointer we use for format at printf.
** * @param flags
** Flags structure, we use them to control if certain
** conditions have been met.
** * @param al
** The magic va_list that stores the variable-length list
** of arguments.
** * @param size
** Size of what you are printing
** * RETURN VALUE
** Void value / Nothing, due to it being a void function.
*/

void			handle_types(char **str, t_flags *flags, va_list al, int *size)
{
	if (handle_others(str, flags, al, size))
		return ;
	if (handle_nums(str, flags, al, size))
		return ;
	if (handle_text(str, flags, al, size))
		return ;
	else
	{
		ft_putchar_fd(**str, 1)
		(*size)++;
	}
}
