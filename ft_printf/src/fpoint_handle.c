/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpoint_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:51:25 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 00:01:49 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			fpoint_atoi(char **str, int i, int aux, int size)
{
	i = ft_atoi(*str);
	aux = i;
	size = 1;
	while (**str == '0' && ft_isdigit(*(*str + 1)))
		(*str)++;
	while (aux >= 10)
	{
		aux /= 10;
		(*size)++;
	}
	*str += size;
}

static void		set_flag(int i, t_flags *flags)
{
	flags->fpoint = 1;
	flags->fwidth = i;
	if (flags->fzero)
		flags->falign = 1;
	flags->fzero = 0;
}

void			fpoint_handle(char **str, t_flags *flags, va_list al)
{
	int		i;
	int		aux;
	int		size;

	(*str)++;
	i = 0;
	if (**str == '*')
	{
		i = va_arg(al, int);
		(*str)++;
	}
	else if (ft_isdigit(**str))
		fpoint_atoi(str, i, aux, size);
	set_flag(i, flags);
}
