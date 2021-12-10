/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:01:01 by prodrigo          #+#    #+#             */
/*   Updated: 2021/12/09 16:05:47 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# ifdef OSX
#  define KEY_ESC 53
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_P 35
#  define KEY_MINUS 27
#  define KEY_PLUS 24
#  define KEY_R 15
#  define KEY_U 32
#  define KEY_J 38
#  define KEY_I 34
#  define KEY_K 40
#  define KEY_O 31
#  define KEY_L 37
# else
#  define KEY_A		'a'
#  define KEY_S		's'
#  define KEY_D		'd'
#  define KEY_W		'w'
#  define KEY_LEFT	65361
#  define KEY_RIGHT	65363
#  define KEY_SPACE	32
#  define KEY_ESCAPE	65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_P 112
#  define KEY_MINUS 45
#  define KEY_PLUS 61
#  define KEY_R 114
#  define KEY_U 117
#  define KEY_J 106
#  define KEY_I 105
#  define KEY_K 107
#  define KEY_O 111
#  define KEY_L 108
# endif

#endif
