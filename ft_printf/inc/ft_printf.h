/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:14:35 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/25 02:35:58 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_flags
{
	char		*str;
	int			fsign;
	int			fdot;
	char		ftype;
	int			fminus;
	int			fzero;
	int			fwidth;
	int			fprec;
	int			fcprec;
}				t_flags;

int				ft_printf(const char *format, ...);
int				check_flags(t_flags *flags, va_list vl, int i);
int				identify(t_flags *flags, va_list vl);
int				put_spaces(t_flags *flags);
int				put_zero(t_flags *flags, int len);
int				ptext_char(char c, t_flags *flags);
int				ptext_str(char *str, t_flags *flags);
int				put_ptr(unsigned long long num, t_flags *flags);
int				pnum_d(int num, t_flags *flags);
int				pnum_u(unsigned int num, t_flags *flags);
int				put_hex(unsigned int num, t_flags *flags, int ucase);
int				chrstr(char c, char const *str);
char			*imtoa(intmax_t n, int base, int ucase);
char			*u_imtoa(uintmax_t n, int base, int ucase);

#endif
