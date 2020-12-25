/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 02:34:27 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 02:34:35 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ptr_aux(char *str, t_flags *flags, int len)
{
	int size;

	size = 0;
	flags->fprec = (flags->fcprec) ? 0 : flags->fprec;
	flags->fprec = (flags->fprec >= 0 && flags->fprec < len) ?
	len : flags->fprec;
	flags->fwidth = flags->fwidth > flags->fprec ?
	(flags->fwidth - flags->fprec) : 0;
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
** Receives the unsigned long long `num` which
** will be converted into base 16 using own function
** u_imtoa, then standard procedure to print
** and returns `size` which is number of bytes written.
*/

int	put_ptr(unsigned long long num, t_flags *flags)
{
	char	*str;
	int		size;
	int		len;

	str = ft_strdup("0x");
	if (flags->fdot && (flags->fprec == 0) && (num == 0))
		len = 2;
	else
	{
		len = ft_strlen(u_imtoa(num, 16, 0)) + 3;
		ft_strlcat(str, u_imtoa(num, 16, 0), len--);
	}
	size = ptr_aux(str, flags, len);
	free(str);
	return (size);
}
