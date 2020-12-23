/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:26:37 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 02:19:06 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		handle_int(t_flags *flags, va_list al, int *size)
{
	char	*num;

	if (!flags->fll && !flags->fhh)
		num = ft_itoa(va_arg(al, int));
	else if (flags->fll == 2)
		num = ll_itoa(va_arg(al, long long int));
	else if (flags->fll == 1)
		num = l_itoa(va_arg(al, long int));
	else if (flags->fhh == 1)
		num = ft_itoa((short)va_arg(al, int));
	else
		num = ft_itoa((char)va_arg(al, int));
	handle(num, flags, size);
	free(num);
}
