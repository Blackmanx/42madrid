/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 02:43:13 by mrubio            #+#    #+#             */
/*   Updated: 2020/10/28 18:01:59 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int		first;
	int		alig;
	int		zero;
	int		second;
	int		f_ast;
	int		s_ast;
	int		ast;
	int		minus;
	int		dot;
}				t_flg;

typedef struct	s_printf
{
	int		x;
	int		ret;
	int		none;
}				t_pf;

unsigned int	ft_strlen(const char *str);
void			*ft_memcpy(void *dest, const void *src, unsigned int n);
void			ft_bzero(void *s, unsigned int n);
int				ft_nblen(long n);
char			*ft_strchr(char *s, int c);

int				ft_check_arg(char *s, va_list args, t_flg flags, t_pf *print);
t_pf			ft_info_flags(char *str, va_list args, t_flg flags, t_pf print);
long			ft_abs(long n);

int				ft_put_flag_char(char c, t_flg flags);
int				ft_putchar(char c);

int				ft_put_flag_nbr(long n, t_flg flags);
int				ft_putnbr(long n);

int				ft_put_flag_str(char *s, t_flg flags);
int				ft_putstr(char *s);

int				ft_putnbr_abs(long n, t_flg flags);

int				ft_put_flag_hex(unsigned int n, int mayus, t_flg flags);
int				ft_puthex(unsigned int n, int mayus, t_flg flags);

int				ft_put_flag_mem(unsigned long addr, t_flg flags);
int				ft_putmem(long addr, t_flg flags);

int				ft_printf(const char *str, ...);
void			ft_init_struct(t_pf *print, t_flg *flags);

#endif
