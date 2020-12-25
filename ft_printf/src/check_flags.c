/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:48:50 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 02:23:37 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		check_nums(t_flags *flags, int pr, int i)
{
	while (ft_strchr("0123456789", flags->str[i]))
	{
		if (pr)
			flags->fprec = (flags->fprec * 10) + (flags->str[i++] - '0');
		else
			flags->fwidth = (flags->fwidth * 10) + (flags->str[i++] - '0');
	}
	return (i);
}

/*
** Receives the format struct, vl list, index position of flags->str
** and a param to denote if its precision or not (width)
** Auxiliary function that parses digits or '*' char to assign the
** flags->fwidth or flags->fprec
*/

int		check_digits(t_flags *flags, va_list vl, int i, int pr)
{
	i += pr == 1 ? 1 : 0;
	if (flags->str[i] == '*')
	{
		if (pr)
		{
			flags->fprec = va_arg(vl, int);
			flags->fcprec = (flags->fprec < 0) ? 1 : 0;
		}
		else
		{
			flags->fwidth = va_arg(vl, int);
			if (flags->fwidth < 0 && (flags->fminus = 1) &&
			(flags->fwidth *= -1))
				(flags->fzero = 0);
		}
		i++;
	}
	else if (ft_strchr("0123456789", flags->str[i]))
		i = check_nums(flags, pr, i);
	else if (pr)
	{
		flags->fcprec = 1;
		flags->fzero = 0;
	}
	return (--i);
}

/*
** Parses from the start of the '%' char until the end
** of its flags (of the mandatory part). To assign values
** to the `flags` t_flags struct.
*/

int		check_flags(t_flags *flags, va_list vl, int i)
{
	while (ft_strchr("-0.*123456789cspdiuxX%", flags->str[++i]))
	{
		if (flags->str[i] == '-' && !flags->fminus && (flags->fminus = 1))
			flags->fzero = 0;
		else if (flags->str[i] == '0' && !flags->fwidth && !flags->fminus
			&& !flags->fzero)
			flags->fzero = 1;
		else if (ft_strchr("0123456789*", flags->str[i]) && !flags->fwidth
			&& !flags->fprec)
			i = check_digits(flags, vl, i, 0);
		else if (flags->str[i] == '.' && !flags->fprec && (flags->fdot = 1))
			i = check_digits(flags, vl, i, 1);
		else if (chrstr(flags->str[i], "cspdiuxX%"))
		{
			flags->ftype = ft_strchr("cspdiuxX%", flags->str[i])[0];
			if (!flags->fdot)
				flags->fcprec = 1;
			break ;
		}
	}
	return (i);
}
