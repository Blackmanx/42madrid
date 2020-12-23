/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_empty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:11:15 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 00:01:21 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** * DESCRIPTION
** Creates arg in order to store in the int* the number
** of characters that would be printed.
** * @param al
** The magic va_list that stores the variable-length list
** of arguments.
** * @param size
** Size of what you are printing
** * RETURN VALUE
** Explain what do you return
*/

void		handle_empty(va_list al, int *size)
{
	int		*arg;

	arg = va_arg(al, int*);
	if (!arg)
		return ;
	*arg = *size;
}
