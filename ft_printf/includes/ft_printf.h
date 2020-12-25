/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:18:24 by sfournio          #+#    #+#             */
/*   Updated: 2020/12/25 04:47:49 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_flags
{
	int		len;
	int		fpoint;
	int		fzero;
	int		fminus;
	int		prec;
}					t_flags;

int					ft_printf(const char *format, ...);
int					ft_putchar(char c);
int					ft_putnbr(int n);
int					ft_putstr(char *s);
int					ft_putpercent(char c, t_flags flags);
t_flags			check_flags(const char *str, t_flags flags, va_list va,
					int *ix);
t_flags			init_flags(t_flags flags, int reinit);
t_flags			check_prec(const char *str, t_flags flags, va_list va,
					int *ix);
int					check_type(const char *str, t_flags flags, va_list va,
					int *ix);
int					put_fnbr(t_flags flags, va_list va);
int					put_uint(t_flags flags, va_list va);
int					ft_putnbr_u(int n);
int					numlen(int nb);
int					ft_putchar_c(char c, t_flags flags);
int					ft_putstr_prec(char *s, t_flags flags);
int					ft_putstr_hex(char *s, t_flags flags);
char				*ft_itoa_base(int nval);
int					f_p(char *s, t_flags flags);
char				*ft_itoa_b_a(unsigned long long nval, t_flags flags);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *str);
int					ft_strlen(const char *str);
char				*to_ucase(char *s);
char				*str_reverse(char *src);
int					fptlen(int j, t_flags flags);
char				*tonull(char *nbr, int i, int *ix);

#endif
