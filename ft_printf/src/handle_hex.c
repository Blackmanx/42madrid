/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:11:33 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 02:41:31 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		to_hs(char **s, unsigned long n, char *base, unsigned long bl)
{
	unsigned long	aux;
	int				len;

	aux = n;
	len = 0;
	while (aux >= bl)
	{
		len++;
		aux /= bl;
	}
	(*s)[len + 1] = 0;
	while (n >= bl)
	{
		(*s)[len] = base[n % bl];
		len--;
		n /= bl;
	}
	(*s)[len] = base[n % bl];
}

char			*hex_itoa(unsigned long num, int ucase)
{
	unsigned long	blength;
	char			*base;
	int				hlength;
	char			*str;
	unsigned long	aux;

	hlength = 1;
	blength = 16;
	if (ucase)
		base = ft_strdup("0123456789ABCDEF");
	else
		base = ft_strdup("0123456789abcdef");
	aux = num;
	while (aux >= blength)
	{
		hlength++;
		aux /= blength;
	}
	if (!(str = malloc(hlength + 1)))
		return (NULL);
	to_hs(&str, num, base, blength);
	free(base);
	return (str);
}

char			*handle_p(char **str, t_flags *flags, va_list al)
{
	char			*aux;

	if (!flags->fll && !flags->fhh)
		aux = hex_itoa(va_arg(al, unsigned int), (**str == 'x' ? 0 : 1));
	else if (flags->fll == 2)
		aux = hex_itoa(va_arg(al, unsigned long long), (**str == 'x' ? 0 : 1));
	else if (flags->fll == 1)
		aux = hex_itoa(va_arg(al, unsigned long), (**str == 'x' ? 0 : 1));
	else if (flags->fhh == 1)
		aux = hex_itoa((unsigned short)va_arg(al, unsigned long),
			(**str == 'x' ? 0 : 1));
	else
		aux = hex_itoa((unsigned char)va_arg(al, unsigned long),
			(**str == 'x' ? 0 : 1));
	return (aux);
}

/*
** * DESCRIPTION
** Handles pointers, then transforms into hex.
** * @param str
** Modifyable char** pointer we use for format at printf.
** * @param flags
** Flags structure, we use them to control if certain
** conditions have been met.
** * @param al
** The magic va_list that stores the variable-length list
** of arguments.
** * @param size
** Size of what you are printing
** * RETURN VALUE
** Nothing / Void value.
*/

static void		handle_hex(char **str, t_flags *flags, va_list al, int *size)
{
	char	*hex;

	hex = handle_p(str, flags, al);
	if (flags->fsharp && *hex != '0')
	{
		if (**str == 'x')
			hex = ft_strjoin("0x", hex);
		if (**str == 'X')
			hex = ft_strjoin("0X", hex);
		handle_pointer(&hex, flags, size);
	}
	else
		handle(hex, flags, size);
	free(hex);
}
