/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:13:51 by prodrigo          #+#    #+#             */
/*   Updated: 2019/10/23 16:54:22 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

int		fill(int rows, unsigned int **sizearr, char **arr);
int		findsquare(int rows, int columns, char **arr, unsigned int **sizearr);
int		bsq_modarr(int rows, int columns, char **arr);

#endif
