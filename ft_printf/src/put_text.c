/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 20:16:38 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 02:31:24 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		put_spaces(t_flags *flags)
{
	int size;
	int pr;
	int width;

	pr = flags->fprec;
	width = flags->fwidth;
	size = 0;
	if (flags->fsign)
		pr--;
	if (!flags->fminus && !flags->fcprec)
		while (width-- > 0)
			size += write(1, " ", 1);
	else if (!flags->fminus && !flags->fzero)
		while (flags->fwidth-- > 0)
			size += write(1, " ", 1);
	else if (flags->fminus && flags->fwidth)
		while (flags->fwidth-- > 0)
			size += write(1, " ", 1);
	return (size);
}

int		put_zero(t_flags *flags, int len)
{
	int size;
	int width;
	int pr;

	width = flags->fwidth;
	pr = flags->fprec;
	flags->fzero = (!flags->fcprec && (pr <= len)) ? 0 : flags->fzero;
	size = 0;
	if (flags->fsign)
		size += write(1, "-", 1);
	if (!flags->fcprec && (pr - len > 0))
		while (pr-- - len > 0)
			size += write(1, "0", 1);
	else if (flags->fwidth && !flags->fminus && flags->fzero)
		while (width-- > 0)
			size += write(1, "0", 1);
	return (size);
}

int		ptext_char(char c, t_flags *flags)
{
	int size;
	int len;

	len = 1;
	size = 0;
	flags->fprec = (flags->fcprec) ? 0 : flags->fprec;
	flags->fprec = (flags->fprec >= 0 && flags->fprec < len) ?
	len : flags->fprec;
	flags->fwidth = flags->fwidth > flags->fprec ?
	(flags->fwidth - flags->fprec) : 0;
	if (flags->fminus)
	{
		size += put_zero(flags, len);
		write(1, &c, 1);
		size = put_spaces(flags);
	}
	else
	{
		size += put_spaces(flags);
		size += put_zero(flags, len);
		write(1, &c, 1);
	}
	return (++size);
}

void	ptext_str_aux(t_flags *flags, int len)
{
	flags->fprec = (flags->fcprec) ? len : flags->fprec;
	flags->fprec = (flags->fdot) ? flags->fprec : len;
	flags->fprec = (flags->fprec >= 0 && flags->fprec < len) ?
	flags->fprec : len;
	flags->fwidth = ((flags->fdot && (flags->fprec == 0)) &&
	!flags->fcprec && !flags->fwidth) ? 0 : flags->fwidth;
	flags->fwidth = flags->fwidth > flags->fprec ?
	(flags->fwidth - flags->fprec) : 0;
}

int		ptext_str(char *str, t_flags *flags)
{
	int size;
	int len;

	if (!str)
		str = ft_strdup("(null)");
	str = (flags->fdot && (flags->fprec == 0)) ? ft_strdup("") : str;
	size = 0;
	len = ft_strlen(str);
	ptext_str_aux(flags, len);
	if (flags->fminus)
	{
		size += write(1, str, flags->fprec);
		size += put_spaces(flags);
	}
	else
	{
		size += put_spaces(flags);
		size += write(1, str, flags->fprec);
	}
	return (size);
}
