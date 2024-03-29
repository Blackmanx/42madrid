/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:49:53 by prodrigo          #+#    #+#             */
/*   Updated: 2019/10/24 13:57:23 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int n;

	n = 0;
	while (s1[n] && s2[n] && s1[n] == s2[n])
	{
		n++;
	}
	return (s1[n] - s2[n]);
}
