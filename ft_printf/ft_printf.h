/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prodrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:59:54 by prodrigo          #+#    #+#             */
/*   Updated: 2020/12/23 01:26:59 by prodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_flags
{
	int			fminus;
	int			fpoint;
	int			fzero;
	int			falign;
	int			fplus;
	int			fll;
	int			fhash;
	int			fhh;
	int			fspace;
	int			fwidth;
}				t_flags;

void			fminus_handle(char **str, t_flags *flags, va_list al);
void			fempty_handle(char **str, t_flags *flags, va_list al);
void			fpoint_handle(char **str, t_flags *flags, va_list al);

int				handle(char *str, t_flags *flags, int *size);
static	void	handle_align(int *str, t_flags *flags, int *size, int n);
static	void	handle_zero(char **str, t_flags *flags, int *size, int *n);
static	void	handle_int(t_flags *flags, va_list al, int *size);
void			handle_empty(va_list al, int *size);
void			handle_types(char **str, t_flags *flags, va_list al, int *size);
static	void	handle_hex(char **str, t_flags *flags, va_list al, int *size);
void			handle_float(t_flags *flags, va_list al, int *size);
void			handle_unsigned(va_list ap, int *size, t_flags *flags);

int				ft_printf(const char *format, ...);

#endif
