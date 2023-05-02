/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:51:52 by prodrigo          #+#    #+#             */
/*   Updated: 2023/05/02 15:44:54 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//  { unistd.h }
//  [                       ]
//  { stdio.h }
//  [                       ]
//  { string.h }
//  [                       ]
//  { stdlib.h }
//  [                       ]
//  { fcntl.h }
//  [                       ]

# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

void	p_parent(char **argv, char **envp, int *fd);
void	p_child(char **argv, char **envp, int *fd);
void	error(char *str);
char	*parse_path(char *cmd, char **envp);
void	exec(char *argv, char **envp);

// Bonus
int		get_next_line(char **line);
void	process_child(char *argv, char **envp);
int		open_file(char *argv, int i);
#endif
