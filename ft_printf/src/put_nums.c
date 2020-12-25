/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nums.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:45:07 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 02:30:56 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	pnumi_aux(char *nstr, t_flags *flags)
{
	int size;
	int len;

	size = 0;
	len = ft_strlen(nstr);
	flags->fprec = ((flags->fprec >= 0 && flags->fprec < len) ||
	flags->fcprec) ? len : flags->fprec;
	flags->fwidth = flags->fwidth > flags->fprec ?
	(flags->fwidth - flags->fprec) : 0;
	if (flags->fminus)
	{
		size += put_zero(flags, len);
		size += write(1, nstr, len);
		size += put_spaces(flags);
	}
	else
	{
		size += put_spaces(flags);
		size += put_zero(flags, len);
		size += write(1, nstr, len);
	}
	return (size);
}

static int	pnumu_aux(char *nstr, t_flags *flags)
{
	int size;
	int len;

	size = 0;
	len = ft_strlen(nstr);
	flags->fprec = ((flags->fprec >= 0 && flags->fprec < len) ||
	flags->fcprec) ? len : flags->fprec;
	flags->fwidth = flags->fwidth > flags->fprec ?
	(flags->fwidth - flags->fprec) : 0;
	if (flags->fminus)
	{
		size += put_zero(flags, len);
		size += write(1, nstr, len);
		size += put_spaces(flags);
	}
	else
	{
		size += put_spaces(flags);
		size += put_zero(flags, len);
		size += write(1, nstr, len);
	}
	return (size);
}

/*
** Receives num to format and struct.
** Returns total bytes written.
** First check if num is negative to handle cases
** then conver it to string, aux func, free and return.
*/

int			pnum_d(int num, t_flags *flags)
{
	char	*nstr;
	int		size;

	size = 0;
	if (num < 0 && (flags->fzero ||
	(flags->fprec - ft_strlen(ft_itoa(num)) > 0) || flags->fwidth > 0))
	{
		flags->fsign = 1;
		num *= -1;
		flags->fwidth--;
	}
	nstr = (flags->fdot && (flags->fprec == 0) && (num == 0)) ?
		ft_strdup("") : ft_itoa(num);
	nstr = (num == INT_MIN) ?
		ft_substr((const char *)nstr, 1, ft_strlen(nstr) - 1) : nstr;
	size += pnumi_aux(nstr, flags);
	free(nstr);
	return (size);
}

/*
** Returns total number of bytes written
** assigns the number as a string, then calls aux
*/

int			pnum_u(unsigned int num, t_flags *flags)
{
	char	*nstr;
	int		size;

	size = 0;
	nstr = (flags->fdot && (flags->fprec == 0) && (num == 0)) ?
		ft_strdup("") : imtoa((intmax_t)num, 10, 0);
	size += pnumu_aux(nstr, flags);
	free(nstr);
	return (size);
}
