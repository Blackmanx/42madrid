/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <sfournio@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:06:28 by sfournio          #+#    #+#             */
/*   Updated: 2020/12/17 13:38:57 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_global	main_while(const char *str, t_global infos, va_list va)
{
	int index;

	index = 0;
	while (str[index])
	{
		infos = init_global(infos, 0);
		if (str[index] == '%')
		{
			infos = check_flags(&str[index + 1], infos, &index, va);
			infos.length += check_type(&str[index + 1], infos, va, &index);
		}
		else
			infos.length += ft_putchar(str[index]);
		if (str[index])
			index++;
	}
	return (infos);
}

t_global	init_global(t_global infos, int reset)
{
	if (reset == 1)
		infos.length = 0;
	infos.precision = -1;
	infos.flagp = -1;
	infos.flagm = 0;
	infos.flagz = 0;
	return (infos);
}

int			ft_printf(const char *str, ...)
{
	va_list		va;
	t_global	infos;

	infos.length = 0;
	infos = init_global(infos, 1);
	va_start(va, str);
	infos = main_while(str, infos, va);
	va_end(va);
	return (infos.length);
}
