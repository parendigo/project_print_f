/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:43:12 by mlarraq           #+#    #+#             */
/*   Updated: 2020/01/20 16:23:19 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"
# define SYMBOLS1(a) a == 'd' || a == 'i' || a == 'o' || a == 'u' || a == 'x' || a == 'X'
# define SYMBOLS2(a) a == 'E' || a == 'f' || a == 'F' || a == 'g' || a == 'G' || a == 'a'     || a == 'A' || a == 'n' || a == 'Z' || a == 'S' || a == 'C' || a == 'e'
# define SYMBOLS3(a) a == 's' || a == 'c' || a == 'p'
# define FLAGS(a) a ==  '-' || a == '+' || a == ' ' || a == '#' || a == '0' || a == '.'
# define SPECS(a) a == 'l' || a == 'h' || a == 'L' || a == '%'
# define NUMBER(a) (a >= '0' && a <= '9')
# define NOTNB(a) (a != '0' && a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6' && a != '7' && a != '8' && a != '9')
# define NU19(a) (a >= '1' && a <= '9')
# define NUNE19(a) (a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6' && a != '7' && a != '8' && a != '9')


typedef struct	s_tab
{
	int			i;
	char		*str;
	char		*arg;
	int			ar;
	char		*gotov;
	char		*result;
	char		*form;
	int			lenform;
	int			cf;
}				t_tab;
int     		ft_printf(const char *format, ...);
int				ft_gotov(va_list factor, t_tab *x);
int				ft_precision(t_tab *x);
int				ft_width(t_tab *x);
void			*ft_memal(size_t size, int c);
int				ft_flags(t_tab *x);

#endif
