/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 12:36:58 by prodrigo          #+#    #+#             */
/*   Updated: 2021/05/17 19:01:04 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# include <stdlib.h>
# include <unistd.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
void		ft_bzero(void *s, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
void		ft_byteshandler(char **str, char *buf, int fd, int bytes);

#endif
