/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <sfournio@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 03:18:24 by sfournio          #+#    #+#             */
/*   Updated: 2020/12/17 13:41:23 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct		s_global
{
	int		length;
	int		flagp;
	int		flagz;
	int		flagm;
	int		precision;
}					t_global;

int					ft_printf(const char *str,
					...) __attribute__((format(printf,1,2)));

/*
**			Basic printers
*/
int					ft_putchar(char c);
int					ft_putnbr(int n);
int					ft_putstr(char *s);
int					ft_putchar_pourcent(char c, t_global infos);

/*
**			Main functions
*/
t_global			check_flags(const char *str, t_global infos, int *ind,
					va_list va);
t_global			init_global(t_global infos, int reset);
t_global			check_prec(const char *str, t_global infos, int *ind,
					va_list va);
int					check_type(const char *str, t_global infos, va_list va,
					int *ind);

/*
**			%d %i and %u
*/
int					ft_put_d_i(t_global infos, va_list va);
int					ft_put_u(t_global infos, va_list va);
int					ft_putnbr_u(int n);
int					intlen(int nb);

/*
**			%s and %c
*/
int					ft_putchar_c(char c, t_global infos);
int					ft_putstr_prec(char *s, t_global infos);

/*
**			%x and %X
*/
int					ft_putstr_hex(char *s, t_global infos);
char				*ft_itoa_base(int value);

/*
**			%p flag
*/
int					f_p(char *s, t_global infos);
char				*ft_itoa_b_a(unsigned long long value, t_global infos);

/*
**			Mini lib
*/
int					ft_atoi(const char *str);
char				*ft_strdup(const char *src);
int					ft_strlen(const char *str);

/*
**			Others
*/
char				*ft_tolow(char *s);
char				*ft_strrev(char *src);
int					pointlen(int j, t_global infos);
char				*little(char *nbr, int i, int *ind);

#endif
