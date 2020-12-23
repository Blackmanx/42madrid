/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fzero_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:59:06 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 00:01:52 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_fzero(int i, t_flags *flags)
{
	i *= -1;
	flags->fzero = 0;
	flags->fminus = 1;
	flags->fspace = i;
}

void		fzero_atoi(char **str, int i, int aux, int size)
{
	i = ft_atoi(*str);
	aux = i;
	size = 1;
	while (aux >= 10)
	{
		aux /= 10;
		(*size)++;
	}
	*str += size;
}

void		fzero_handle(char **str, t_flags *flags, va_list al)
{
	int		i;
	int		aux;
	int		size;

	i = 0;
	if (**str == '*')
	{
		i = va_arg(al, int);
		(*str)++;
	}
	else if (ft_isdigit(**str))
	{
		fzero_atoi(str, i, aux, size);
	}
	flags->fspace = i;
	if (i < 0)
		set_fzero(i, flags);
}
