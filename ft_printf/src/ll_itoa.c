/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 01:50:52 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 02:19:05 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	sum_num(unsigned long long int *num, int *i)
{
	while (*num >= 10)
	{
		(*i)++;
		*num /= 10;
	}
}

static char	*mem_number(long long int n, int *i)
{
	char					*cnum;
	unsigned long long int	num;

	if (n == 0)
	{
		if (!(cnum = malloc(2)))
			return (NULL);
		cnum[0] = '0';
		cnum[1] = 0;
		return (cnum);
	}
	*i = 1;
	if (n < 0)
	{
		num = -n;
		(*i)++;
	}
	else
		num = n;
	sum_num(&num, i);
	if (!(cnum = malloc(*i + 1)))
		return (NULL);
	cnum[*i] = 0;
	return (cnum);
}

char		*ll_itoa(long long int n)
{
	char					*cnum;
	int						i;
	unsigned long long int	num;

	cnum = NULL;
	if (!(cnum = mem_number(n, &i)))
		return (NULL);
	if (n < 0)
	{
		num = -n;
		cnum[0] = '-';
	}
	else
		num = n;
	while (num >= 10)
	{
		i--;
		cnum[i] = 48 + num % 10;
		num /= 10;
	}
	if (i)
		i--;
	cnum[i] = 48 + num % 10;
	return (cnum);
}
