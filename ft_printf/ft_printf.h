/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:11:16 by prodrigo          #+#    #+#             */
/*   Updated: 2020/11/25 13:29:49 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_flags
{
	int		pointer;
	int		width;
	int		zero;
	int		minus;
	int		type;
	int		dot;
}				t_flags;

int				pf_isflag(int c);
int				pf_symbol(int c);
int				pf_handle_char(char c, t_flags f);
t_flags			pf_minus_flag(t_flags f);
t_flags			pf_digit_flag(char c, t_flags f);
t_flags			pf_width_flag(va_list args, t_flags f);
int				pf_handle_dot(const char *str, int start,
t_flags *f, va_list args);
int				pf_handle_hex(unsigned int number,
int lowercase, t_flags f);
int				pf_handle_int(int i, t_flags f);
int				pf_handle_percent(t_flags f);
int				pf_handle_pointer(unsigned long long num, t_flags f);
int				pf_handle_string(char *str, t_flags f);
int				pf_handle_uint(unsigned int number, t_flags f);
int				pf_handle_width(int width, int minus, int zero);
int				pf_flaghandle(int c, t_flags f, va_list args);
int				ft_printf(const char *fmt, ...);

#endif
