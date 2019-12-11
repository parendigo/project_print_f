/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:41:33 by mlarraq           #+#    #+#             */
/*   Updated: 2019/12/11 17:06:14 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

#define SYMBOLS1(a) a == 'd' || a == 'i' || a == 'o' || a == 'u' || a == 'x' || a == 'X'
#define SYMBOLS2(a) a == 'E' || a == 'f' || a == 'F' || a == 'g' || a == 'G' || a == 'a' || a == 'A' || a == 'n' || a == 'p' || a == 'c' || a == 'C' || a == 'e'
#define SYMBOLS3(a) a == 's' || a == 'S' || a == 'Z'
#define FLAGS(a) a ==  '-' || a == '+' || a == ' ' || a == '#' || a == '0' || a == '.' 
#define SPECS(a) a == 'l' || a == 'h' || a == 'L' || a == '%'
#define NUMBER(a) (a >= '0' && a <= '9')

int		return_arg(va_list factor, t_tab *x)
{
	x->arg = va_arg(factor, char *);
	ft_putstr(x->arg);
	return (0);
}

char	*get_form(const char **format, char *str, int i)
{
	char	*form;

	form = ft_strsub(str, 0, i + 1);
	*format += i + 1;
	return (form);
}

int		find_operator(t_tab *x)
{
	int		j;

	j = 1;
	while (x->str[x->i + j])
	{
		if (FLAGS(x->str[x->i + j]) || SPECS(x->str[x->i + j]) || NUMBER(x->str[x->i + j]))
			j = j;
		else if  (SYMBOLS1(x->str[x->i + j]) || SYMBOLS2(x->str[x->i + j]) || SYMBOLS3(x->str[x->i + j]))
		{
			x->form = ft_strsub(x->str, x->i, x->i + j + 1);
			x->i = x->i + j + 1;
			return 1;
		}
		else
			break;
		j++;
	}
	return 0;
}
int		ft_printf(const char *format, ...)
{
	t_tab	*x;
	va_list factor;

	x = (t_tab*)malloc(sizeof(t_tab));
	x->i = 0;
	x->str = ft_strdup(format);
	va_start(factor, format);
	while (x->str[x->i])
	{
		if (x->str[x->i] == '%')
		{
			if (find_operator(x) != 0)
				return_arg(factor, x);
		}
		ft_putchar(x->str[x->i]);
		x->i++;
	}
	va_end(factor);
	return 0;
}
