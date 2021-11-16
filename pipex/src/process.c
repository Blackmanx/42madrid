/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:51:26 by prodrigo          #+#    #+#             */
/*   Updated: 2021/11/15 23:58:08 by prodrigo         ###   ########.fr       */
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

	filein = open(argv[1], O_RDONLY);
	if (filein < 0)
		error("Error while opening filein");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		error("Error while allocating new file descriptor.");
	if (dup2(filein, STDIN_FILENO) == -1)
		error("Error while allocating new file descriptor.");
	close(fd[0]);
	close(filein);
	close(fd[1]);
	exec(argv[2], envp);
}

// argv: Argument of main(). String pointer that contains program parameters.
// envp: Pointer matrix that points to env paths. It's an argument of main().
// fd: File Descriptor

void	p_parent(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout < 0)
		error("Error while opening filein");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		error("Error while allocating new file descriptor.");
	if (dup2(fileout, STDOUT_FILENO) == -1)
		error("Error while allocating new file descriptor.");
	close(fd[1]);
	close(fileout);
	close(fd[0]);
	exec(argv[3], envp);
}
