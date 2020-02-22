/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:41:33 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/20 15:59:31 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int				return_arg(va_list factor, t_tab *x)
{
	ft_gotov(factor, x);
	ft_precision(x);
	ft_flags(x);
	ft_width(x);
	ft_putstr(x->result);
	return (0);
}

static int		compare_fsn(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '.' || c == '0')
		return (1);
	if (c == 'l' || c == 'h' || c == 'L')
		return (1);
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5')
		return (1);
	if (c == '6' || c == '7' || c == '8' || c == '9')
		return (1);
	return (0);
}

static int		compare_symbols(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	if (c == 'f' || c == '%' || c == 's' || c == 'c' || c == 'p')
		return (1);
	return (0);
}

int				find_operator(t_tab *x)
{
	int		j;

	j = 1;
	while (x->str[x->i + j])
	{
		if (compare_fsn(x->str[x->i + j]) == 1)
			j = j + 0;
		else if (compare_symbols(x->str[x->i + j]) == 1)
		{
			x->form = ft_strsub(x->str, x->i, j + 1);
			x->i = x->i + j + 1;
			x->lenform = j + 1;
			x->cf = x->form[j];
			return (1);
		}
		else
			break ;
		j++;
	}
	x->i = x->i + j;
	return (0);
}

int				ft_printf(const char *format, ...)
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
		else
			ft_putchar(x->str[x->i++]);
	}
	va_end(factor);
	return (0);
}
