/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:53:07 by prodrigo          #+#    #+#             */
/*   Updated: 2021/11/16 00:38:08 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	args_error(void)
{
	ft_putstr_fd("Error: Bad arguments\n", 2);
	ft_putstr_fd("Args: ./pipex <file1> <cmd1> <cmd2> file2\n", 1);
}

void	pipex(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error("Error pipeing file descriptor");
		pid1 = fork();
		if (pid1 == -1)
			error("ERROR");
		if (pid1 == 0)
			p_child(argv, envp, fd);
		pid2 = fork();
		if (pid2 == -1)
			error("ERROR");
		if (pid2 == 0)
			p_parent(argv, envp, fd);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		args_error();
}

int	main(int argc, char *argv[], char *envp[])
{
	pipex(argc, argv, envp);
	return (0);
}
