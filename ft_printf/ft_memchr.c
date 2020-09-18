/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlertypes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 13:02:58 by prodrigo          #+#    #+#             */
/*   Updated: 2020/07/27 13:03:54 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_handle_char(char c, t_flags f)
{
	int count;

	count = 0;
	if (f.minus == 1)
		ft_putchar(c);
	count = ft_handle_width(f.width, 1, 0);
	if (f.minus == 0)
		ft_putchar(c);
	return (count + 1);
}
