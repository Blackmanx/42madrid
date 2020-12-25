/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:45:18 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 02:34:12 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		phex_aux(char *str, t_flags *flags)
{
	int size;
	int len;

	size = 0;
	len = ft_strlen(str);
	flags->fprec = ((flags->fprec >= 0 && flags->fprec < len) ||
	flags->fcprec) ? len : flags->fprec;
	flags->fwidth = flags->fwidth > flags->fprec
	? (flags->fwidth - flags->fprec) : 0;
	if (flags->fminus)
	{
		size += put_zero(flags, len);
		size += write(1, str, len);
		size += put_spaces(flags);
	}
	else
	{
		size += put_spaces(flags);
		size += put_zero(flags, len);
		size += write(1, str, len);
	}
	return (size);
}

/*
** Transforms the num in a base 16 string, depending
** if flag 'x' or 'X', `ucase` will be 0 or 1
** Returns total number of bytes written.
*/

int				put_hex(unsigned int num, t_flags *flags, int ucase)
{
	char	*str;
	int		size;

	size = 0;
	str = (flags->fdot && (flags->fprec == 0) && (num == 0)) ?
		ft_strdup("") : u_imtoa((uintmax_t)num, 16, ucase);
	size += phex_aux(str, flags);
	free(str);
	return (size);
}
