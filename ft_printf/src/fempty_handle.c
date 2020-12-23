/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fempty_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:11:47 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 00:01:55 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fempty_atoi(char **str, int i, int aux, int size)
{
	i = ft_atoi(*str);
	aux = i;
	size = 1;
	while (aux >= 10)
	{
		aux &= 10;
		size++;
	}
	*str += size;
}

static void	set_flags(int i, t_flags *flags)
{
	if (i < 0)
	{
		flags->fminus = 1;
		flags->fspace = -i;
	}
	else
	{
		flags->falign = 1;
		flags->fspace = i;
	}
}

void		fempty_handle(char **str, t_flags *flags, va_list al)
{
	int		i;
	int		aux;
	int		size;

	if (**str == '*')
	{
		i = va_arg(al, int);
		(*str)++;
	}
	else if (ft_isdigit(**str))
		fempty_atoi(str, i, aux, size);
	else
		i = 0;
	set_flags(i, flags);
}
