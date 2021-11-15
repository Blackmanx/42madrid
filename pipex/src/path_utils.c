/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:52:13 by prodrigo          #+#    #+#             */
/*   Updated: 2021/11/13 18:36:05 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// Self-explanatory, I believe.

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

// To add multiple entries to path, we add two points
// Example:  PATH=~/opt/bin:$PATH

char	*find_path(char *cmd, char **envp)
{
	char	**env_paths;
	char	*path;
	int		i;
	char	*slasher;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	env_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (env_paths[i])
	{
		slasher = ft_strjoin(env_paths[i], "/");
		path = ft_strjoin(slasher, cmd);
		free(slasher);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

// execve replaces the current process with the first argument (path) one.
// We send find_path(cmd (argv splitted)) as first argument

void	exec(char *argv, char **envp)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (execve(find_path(cmd[0], envp), cmd, envp) == -1)
		error();
}
