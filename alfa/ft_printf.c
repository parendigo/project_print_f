/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:41:33 by mlarraq           #+#    #+#             */
/*   Updated: 2020/01/27 15:20:45 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int		return_arg(va_list factor, t_tab *x)
{
	ft_gotov(factor, x);
	ft_precision(x);
	ft_flags(x);
	ft_width(x);
	ft_putstr(x->result);
	return (0);
}

int		find_percent_twice(t_tab *x)
{
	int		j;
	
	j = 1;
	while (x->str[x->i + j])
	{
		if (x->str[x->i + j] == '%')
			return (j);
		j++;
	}
	return (0);
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
			x->form = ft_strsub(x->str, x->i, j + 1);
			x->i = x->i + j + 1;
			x->lenform = j + 1;
			x->cf = x->form[j];
			return 1;
		}
		else
			break;
		j++;
	}
	x->i = x->i + j;
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
