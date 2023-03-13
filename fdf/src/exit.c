/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:04:22 by prodrigo          #+#    #+#             */
/*   Updated: 2023/03/13 21:44:14 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** * DESCRIPTION
** Exit the window properly.
** * @param fdf
** fdf: Fdf struct
** * RETURN VALUE
** None
*/

int	close_window(t_fdf *fdf)
{
	fdf = NULL;
	exit(EXIT_SUCCESS);
	return (0);
}

/*
** * DESCRIPTION
** Whenever an error happens, use this function to print out an error and exit
** with an error code.
** * @param myParam
** Description of params
** * RETURN VALUE
** Explain what do you return
*/

void	exit_error(char *error, int errcode)
{
	printf("%s,  Error code: %d \n", error, errcode);
	exit(errcode);
}
