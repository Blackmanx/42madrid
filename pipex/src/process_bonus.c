/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:51:26 by prodrigo          #+#    #+#             */
/*   Updated: 2023/05/02 17:01:33 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	open_file(char *argv, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		fd = open(argv, O_RDONLY, 0777);
	if (fd == -1)
		error("Error: Failed to open file");
	return (fd);
}

// argv: Argument of main(). String pointer that contains program parameters.
// envp: Pointer matrix that points to env paths. It's an argument of main().

void	process_child(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error("Error: Failed to pipe file descriptor");
	pid = fork();
	if (pid == -1)
		error("Error: Failed to obtain pid");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		exec(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}
