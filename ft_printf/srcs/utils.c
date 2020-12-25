/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 03:56:51 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 04:08:19 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*to_ucase(char *s)
{
	int i;

	if (s == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	return (s);
}

char	*str_reverse(char *src)
{
	int		length;
	int		i;
	char	temp;

	length = ft_strlen(src);
	i = -1;
	while (++i < length / 2)
	{
		temp = src[i];
		src[i] = src[length - i - 1];
		src[length - i - 1] = temp;
	}
	return (src);
}

int		fptlen(int j, t_flags flags)
{
	if (flags.fpoint > -1)
	{
		if (flags.fpoint == 0)
			return (0);
		else
		{
			if (flags.fpoint >= j)
				return (flags.fpoint);
			return (j);
		}
	}
	else
		return (j);
}

char	*tonull(char *nbr, int i, int *ix)
{
	nbr[i] = '\0';
	*ix += i;
	return (nbr);
}
