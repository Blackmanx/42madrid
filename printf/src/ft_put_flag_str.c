/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_flag_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:00:55 by mrubio            #+#    #+#             */
/*   Updated: 2020/11/02 13:22:23 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		flag_width_str(char *s, t_flg flags)
{
	int		x;
	int		siz;

	x = 0;
	siz = ft_strlen(s);
	if (flags.second < siz && flags.second > -1)
		siz = flags.second;
	if (flags.zero == 1 && flags.alig == 0 && flags.first > 0)
		while (flags.first > siz)
		{
			x += ft_putchar('0');
			flags.first--;
		}
	else if (flags.first > 0)
		while (flags.first > siz)
		{
			x += ft_putchar(' ');
			flags.first--;
		}
	return (x);
}

int		ft_flag_prec_str(char *str, t_flg flags)
{
	int		x;

	x = 0;
	while (x < flags.second && str[x] != '\0')
		x += ft_putchar(str[x]);
	return (x);
}

int		ft_put_flag_str(char *s, t_flg flags)
{
	int		x;

	x = 0;
	if (!s)
		s = "(null)";
	if (flags.alig == 1)
	{
		if (flags.second > -1)
			x += ft_flag_prec_str(s, flags);
		else
			x += ft_putstr(s);
		x += flag_width_str(s, flags);
	}
	else
	{
		x += flag_width_str(s, flags);
		if (flags.second > -1)
			x += ft_flag_prec_str(s, flags);
		else
			x += ft_putstr(s);
	}
	return (x);
}
