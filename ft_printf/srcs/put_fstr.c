/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_fstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 03:53:01 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 13:58:50 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	slen(char *s, t_flags flags)
{
	int i;

	i = ft_strlen(s);
	if (flags.fpoint > -1)
	{
		if (flags.fpoint == 0)
			return (0);
		else
		{
			if (flags.fpoint >= i)
				return (i);
			return (flags.fpoint);
		}
	}
	else
		return (i);
}

int	put_s(char *s, t_flags flags, int l, int type)
{
	int i;

	i = -1;
	if (type == 1)
	{
		while (l++ < flags.prec)
			ft_putchar(' ');
		while (s[++i] && (flags.fpoint == -1 || i < flags.fpoint))
			write(1, &s[i], 1);
	}
	else
	{
		while (s[++i] && (flags.fpoint == -1 || i < flags.fpoint))
			write(1, &s[i], 1);
		while (l++ < flags.prec)
			ft_putchar(' ');
	}
	return (l - 1);
}

int	put_s_2(t_flags flags, int l)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = ft_strdup("(null)\0");
	l = slen(tmp, flags);
	if (flags.fminus)
	{
		while (tmp[++i])
			if (flags.fpoint == -1 || i < flags.fpoint)
				ft_putchar(tmp[i]);
		while (l++ < flags.prec)
			ft_putchar(' ');
	}
	else
	{
		while (l++ < flags.prec)
			ft_putchar(' ');
		while (tmp[++i])
			if (flags.fpoint == -1 || i < flags.fpoint)
				ft_putchar(tmp[i]);
	}
	free(tmp);
	return (l - 1);
}

int	put_s3(char *s, t_flags flags, int l)
{
	int i;

	i = -1;
	while (l++ < flags.prec)
		ft_putchar('0');
	while (s[++i] && (flags.fpoint == -1 || i < flags.fpoint))
		write(1, &s[i], 1);
	return (l - 1);
}

int	ft_putstr_prec(char *s, t_flags flags)
{
	int i;
	int l;

	i = -1;
	l = 0;
	if (flags.fpoint == 0)
	{
		while (l++ < flags.prec)
			ft_putchar(' ');
		return (l - 1);
	}
	else if (s == NULL)
		return (put_s_2(flags, l));
	l = slen(s, flags);
	if (!flags.fminus && flags.prec > -1 && !flags.fzero)
		return (put_s(s, flags, l, 1));
	else if (!flags.fminus && flags.fzero && flags.prec > -1)
		return (put_s3(s, flags, l));
	else if (flags.fminus)
		return (put_s(s, flags, l, 0));
	else
		while (s[++i] && (flags.fpoint == -1 || i < flags.fpoint))
			write(1, &s[i], 1);
	return (i);
}
