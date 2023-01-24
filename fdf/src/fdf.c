/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:12:53 by prodrigo          #+#    #+#             */
/*   Updated: 2022/09/28 17:49:35 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
** * DESCRIPTION
** Whenever an error happens, use this function to print out an error and exit with an error code.
** * @param myParam
** Description of params
** * RETURN VALUE
** Explain what do you return
*/

int	ft_error(char *error, int code_error)
{
	printf("%s,  Error code: %d \n", error, code_error);
	exit(code_error);
}

/*
** * DESCRIPTION
** main function
** * @param myParam
** argc : Number of args
** argv : args themselves as string.
** * RETURN VALUE
** Exit code (int)
*/

void	check_type(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (ft_strncmp(&filename[len - 4], ".fdf", 4) != 0)
		ft_error("Error: Wrong file extension", BAD_FILE);
}

int	main(int argc, char *argv[])
{
	t_fdf	*fdf;
	char	*file_path;

	if (argc != 2)
		ft_error("Error: Invalid arguments", INVALID_ARGS);
	check_type(argv[1]);
	fdf = (t_fdf *)ft_calloc(1, sizeof(t_fdf));
	if (!fdf)
		ft_error("Error: Malloc failed", ALLOC_FAIL);
	init_fdf(argv);
	return (0);
}
