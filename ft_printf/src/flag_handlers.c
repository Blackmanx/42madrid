/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:30:33 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 00:01:41 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_point(char **str, t_flags *flags, int *n)
{
	*n = ft_strlen(*str);
	if (flags->fwidth && !flags->fpoint)
	{
		if (**str == '0')
		{
			*str += *n;
			*n = 0;
		}
		else if (!ft_strncmp(*str, "+0", 2))
		{
			free(*str);
			*str = ft_strdup("+");
			*n = 1;
		}
	}
}

static void	check_plus(char **str, t_flags flags, int *size)
{
	char	*aux;

	if (flags->fplus == 1)
	{
		if (**str != '-')
		{
			aux = ft_strjoin("+", *str);
			*str = aux;
		}
	}
	if (flags->flag_plus == 2 && **str != '-')
	{
		ft_putstr_fd(" ", 1);
		(*size)++;
		flags->fspace -= 1;
	}
}

int			handle(char *str, t_flags *flags, int *size)
{
	int		n;

	if (!str)
		return (0);
	fplus_handle(&str, flags, size);
	fpoint_handle(&str, flags, &n);
	if (flags->falign)
		handle_align(str, flags, size, n);
	if (flags->fzero || flags->fpoint)
		handle_zero(&str, flags, size, &n);
	ft_putstr_fd(str, 1);
	if (flags->fminus)
		handle_align(str, flags, size, n);
	return (1);
}
