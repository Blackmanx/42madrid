/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <sfournio@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 08:52:42 by sfournio          #+#    #+#             */
/*   Updated: 2020/12/17 13:00:09 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_tolow(char *s)
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

char	*ft_strrev(char *src)
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

int		pointlen(int j, t_global infos)
{
	if (infos.flagp > -1)
	{
		if (infos.flagp == 0)
			return (0);
		else
		{
			if (infos.flagp >= j)
				return (infos.flagp);
			return (j);
		}
	}
	else
		return (j);
}

char	*little(char *nbr, int i, int *ind)
{
	nbr[i] = '\0';
	*ind += i;
	return (nbr);
}
