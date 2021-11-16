/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:52:13 by prodrigo          #+#    #+#             */
/*   Updated: 2021/11/16 00:10:10 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// Self-explanatory, I believe.

void	error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

// To add multiple entries to path, we add two points
// Example:  PATH=~/opt/bin:$PATH

char	*parse_path(char *cmd, char **envp)
{
	char	**env_paths;
	char	*path;
	char	*slasher;
	int		i;

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
	if (execve(parse_path(cmd[0], envp), cmd, envp) == -1)
		error("Error while executing command.");
}
