/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:43:12 by mlarraq           #+#    #+#             */
/*   Updated: 2020/01/18 19:32:21 by mlarraq          ###   ########.fr       */
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

typedef struct	s_tab
{
	int			i;
	char		*str;
	char		*arg;
	int			ar;
	char		*gotov;
	char		*form;
	int			lenform;
	int			cf;
}				t_tab;
int     		ft_printf(const char *format, ...);
int				ft_gotov(va_list factor, t_tab *x);
int				ft_precision(t_tab *x);

#endif
