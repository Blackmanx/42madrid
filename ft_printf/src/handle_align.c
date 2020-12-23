/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_align.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:51:17 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 00:01:58 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	handle_align(int *str, t_flags *flags, int *size, int n)
{
	if (flags->fwidth >= n)
	{
		flags->fspace -= flags->fwidth;
		if (*str == '+' || *str == '-')
			flags->fspace -= 1;
	}
	else
		flags->fspace -= n;
	while (flags->fspace > 0)
	{
		ft_putstr_fd(" ", 1);
		(*size)++;
		flags->fspace -= 1;
	}
}
