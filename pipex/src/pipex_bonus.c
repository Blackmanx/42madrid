/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <prodrigo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:48:22 by prodrigo          #+#    #+#             */
/*   Updated: 2023/05/02 17:06:38 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	args_error(void)
{
	ft_putstr_fd("Error: Bad arguments\n", 2);
	ft_putstr_fd("Args: ./pipex <file1> <cmd1> <cmd2> <...> file2\n", 1);
	ft_putstr_fd("Args: ./pipex here_doc <file1> <cmd1> <cmd2> <...> file2\n",
		1);
	exit(EXIT_FAILURE);
}

// Handle appending, if there's no limiter

void	here_doc(char *argv, int argc)
{
	pid_t	processes;
	int		fd[2];
	char	*line;

	if (argc < 6)
		args_error();
	if (pipe(fd) == -1)
		error("Error: Failed to pipe file descriptor");
	processes = fork();
	if (processes == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, argv, ft_strlen(argv)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

// Check if using here_doc or just regular pipes without appending

void	pipex(int argc, char **argv, char **envp)
{
	int	i;
	int	filein;
	int	fileout;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			fileout = open_file(argv[argc - 1], 0);
			here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			fileout = open_file(argv[argc - 1], 1);
			filein = open_file(argv[1], 2);
			dup2(filein, STDIN_FILENO);
		}
		while (i < argc - 2)
			process_child(argv[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		exec(argv[argc - 2], envp);
	}
	args_error();
}

int	main(int argc, char *argv[], char *envp[])
{
	pipex(argc, argv, envp);
	return (0);
}
