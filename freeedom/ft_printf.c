/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:41:33 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/27 16:43:30 by mlarraq          ###   ########.fr       */
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
	ft_save(x);
	x->co = x->co + 1;
	return(0);
}

int				compare_fsn(char c, char c2)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '.' || c == '0')
		return (1);
	if (c == 'l' || c == 'h' || c == 'L' || c == 39)
		return (1);
	if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5')
		return (1);
	if (c == '6' || c == '7' || c == '8' || c == '9')
		return (1);
	if (c == '$' && (c2 == '1' || c2 == '2' || c2 == '3' || c2 == '4' || c2 == '5'))
		return (1);
	if (c == '$' && (c2 == '6' || c2 == '7' || c2 == '8' || c2 == '9'))
		return (1);
	return (0);
}

int				compare_symbols(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	if (c == 'f' || c == '%' || c == 's' || c == 'c' || c == 'p' ||
	c == 'e' || c == 'g' || c == 'b' || c == 'r')
		return (1);
	return (0);
}

int				find_operator(t_tab *x)
{
	int			j;

	j = 1;
	while (x->str[x->i + j])
	{
		if (compare_fsn(x->str[x->i + j], x->str[x->i + j - 1])== 1)
			j = j + 0;
		else if (compare_symbols(x->str[x->i + j]) == 1)
		{
			x->allforms[x->co] = ft_strsub(x->str, x->i, j + 1);
			x->i = x->i + j + 1;
			x->lenform = j + 1;
			x->cf = x->allforms[x->co][j];
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
	x->co = 0;
	x->str = ft_strdup(format);
	x->gotov = NULL;
	x->result = NULL;
	x->allforms[x->co] = NULL;
	x->str_ostatok = NULL;
	x->gotov_e = NULL;
	x->exp_e = NULL;
	x->celoe = NULL;
	x->gotov_f = NULL;
	x->c_and_exp = NULL;
	x->okrug_ostatok = NULL;
	va_start(factor, format);
	while (x->str[x->i])
	{
		if (x->str[x->i] == '%')
		{
			if (find_operator(x) != 0)
				return_arg(factor, x);
		}
		else
		x->i++;
	}
	save_result(x);
	va_end(factor);
	free(x);
	return (0);
}

//int main()
//{
//int i = 0;
//	char str[33];
//
//	while (i < 33)
//	{
//		str[i] = i + 1;
//		i++;
//	}
//	str[28] = '\0';
//	ft_printf("%r\n", str);
//	ft_printf("%10d, %.10i, %0o, %+u, % x, %X, %-10s, %c, %p, %f", 123, 123, 123, 123, 123, 123, "Kolo", 'A', 56, 0.00006);
//	return (1);
//}

int main()
{
    ft_printf("%.s", "HELLO");
    return (1);
}