/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:51:26 by prodrigo          #+#    #+#             */
/*   Updated: 2021/11/15 15:22:43 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// argv: Argument of main(). String pointer that contains program parameters.
// envp: Pointer matrix that points to env paths. It's an argument of main().
// fd: File Descriptor
//

void	p_child(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	exec(argv[2], envp);
}

// argv: Argument of main(). String pointer that contains program parameters.
// envp: Pointer matrix that points to env paths. It's an argument of main().
// fd: File Descriptor

void	p_parent(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	exec(argv[3], envp);
}
