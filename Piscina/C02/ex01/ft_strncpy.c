/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:11:47 by prodrigo          #+#    #+#             */
/*   Updated: 2019/10/24 16:27:30 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *src);

char			*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	c;

	c = 0;
	while (src[n] != '\0' && c < n)
	{
		dest[c] = src[c];
		c++;
	}
	dest[c] = '\0';
	while (c < n)
	{
		dest[c] = '\0';
		c++;
	}
	return (dest);
}

unsigned int	ft_strlen(char *src)
{
	unsigned int n;

	n = 0;
	while (src[n] != '\0')
	{
		n++;
	}
	return (n);
}
