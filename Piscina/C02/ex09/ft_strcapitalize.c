/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:08:49 by prodrigo          #+#    #+#             */
/*   Updated: 2019/10/24 17:32:10 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_getstr(char *str)
{
	int n;
	int found;

	n = 1;
	found = 0;
	while (str[n] != '\0')
	{
		if (((str[n] >= '0' && str[n] <= '9') ||
		(str[n] >= 'a' && str[n] <= 'z')))
		{
			if (str[n] >= 'a' && str[n] <= 'z' && found == 0)
			{
				str[n] = str[n] - 32;
				found = 1;
			}
		}
		else
			found = 0;
		n++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int n;
	int found;

	n = 0;
	while (str[n] != '\0')
		if (str[n] >= 'A' && str[n] <= 'Z')
			str[n] += 32;
	n = 0;
	if (str[0] != '\0' && str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
	ft_getstr(str);
	return (str);
}
