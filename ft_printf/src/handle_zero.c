/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:35:20 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 00:01:36 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			sign_handler(char **str, t_flags *flags, int *size)
{
	if (**str == '-')
		ft_putstr_fd("-", 1);
	else
		ft_putstr_fd("+", 1);
	(*size)++;
	(*str)++;
	if (!flags->fzero)
	{
		if (!flags->fminus)
			flags->fspace -= 1;
		flags->fwidth += 1;
	}
}

static	void	handle_zero(char **str, t_flags *flags, int *size, int *n)
{
	int		*arr;

	if (flags->fzero)
		arr = &flags->fspace;
	else
		arr = &flags->fwidth;
	*arr -= *n;
	if (**str == '+' || **str == '-')
		sign_handler(str, flags, size);
	while (*arr > 0)
	{
		ft_putstr_fd("0", 1);
		(*size++);
		flags->fspace -= 1;
		flags->fwidth -= 1;
	}
}
