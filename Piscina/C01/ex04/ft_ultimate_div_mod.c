/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:26:20 by prodrigo          #+#    #+#             */
/*   Updated: 2019/10/09 15:33:18 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int adiv;
	int bdiv;

	adiv = *a;
	bdiv = *b;
	*a = adiv / bdiv;
	*b = adiv % bdiv;
}
