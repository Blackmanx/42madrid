/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:51:52 by prodrigo          #+#    #+#             */
/*   Updated: 2021/11/13 18:37:01 by prodrigo         ###   ########.fr       */
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

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

void	parent_process(char **argv, char **envp, int *fd);
void	child_process(char **argv, char **envp, int *fd);
void	error(void);
char	*find_path(char *cmd, char **envp);
void	exec(char *argv, char **envp);

#endif