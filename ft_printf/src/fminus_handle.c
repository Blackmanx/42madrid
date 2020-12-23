/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fminus_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:52:02 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 00:01:45 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fminus_atoi(char **str, int i, int aux, int size)
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

void	fminus_handle(char **str, t_flags *flags, va_list al)
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
		fminus_atoi(str, i, aux, size);
	else
		i = 0;
	if (i < 0)
		i = -i;
	flags->fspace = i;
}
