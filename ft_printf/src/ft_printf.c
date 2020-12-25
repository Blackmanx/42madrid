/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:18:00 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 02:22:32 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flags *flags)
{
	flags->ftype = 0;
	flags->fminus = 0;
	flags->fzero = 0;
	flags->fwidth = 0;
	flags->fprec = 0;
	flags->fcprec = 0;
	flags->fdot = 0;
	flags->fsign = 0;
}

int		handle_flags(t_flags *flags, va_list vl)
{
	int			i;
	int			size;

	i = -1;
	size = 0;
	while (flags->str[++i])
	{
		if (flags->str[i] != '%')
			size += write(1, (flags->str + i), 1);
		else if (flags->str[i + 1])
		{
			init_flags(flags);
			i = check_flags(flags, vl, i);
			if (chrstr(flags->str[i], "cspdiuxX%"))
				size += identify(flags, vl);
			else if (flags->str[i])
				size += write(1, (flags->str + i), 1);
		}
	}
	return (size);
}

int		ft_printf(const char *format, ...)
{
	va_list		vl;
	t_flags		*flags;
	int			size;
	char		*str;

	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (-1);
	str = (char *)format;
	flags->str = ft_strdup(str);
	va_start(vl, format);
	size = handle_flags(flags, vl);
	va_end(vl);
	free(flags);
	return (size);
}
