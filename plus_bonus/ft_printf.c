/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:41:33 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/26 17:35:20 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int				return_arg(va_list factor, t_tab *x, int *count)
{
	ft_gotov(factor, x);
	ft_precision(x);
	ft_flags(x);
	ft_width(x);
	ft_save(x, count);
	*count = *count + 1;
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
	if (c == 'f' || c == '%' || c == 's' || c == 'c' || c == 'p' || c == 'e' || c == 'g')
		return (1);
	return (0);
}

int				find_operator(t_tab *x, int *count)
{
	int			j;

	j = 1;
	while (x->str[x->i + j])
	{
		if (compare_fsn(x->str[x->i + j], x->str[x->i + j - 1])== 1)
			j = j + 0;
		else if (compare_symbols(x->str[x->i + j]) == 1)
		{
			x->form = ft_strsub(x->str, x->i, j + 1);
			x->allforms[*count] = ft_strdup(x->form);
			x->ints[*count] = x->i;
			x->i = x->i + j + 1;
			x->intse[*count] = x->i;
			x->lenform = j + 1;
			x->cf = x->form[j];
//			printf("ints[count] = %d\nintse[count] = %d\n", x->ints[*count], x->intse[*count]);
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
	int		count;

	count = 0;
	x = (t_tab*)malloc(sizeof(t_tab));
	x->i = 0;
	x->str = ft_strdup(format);
	va_start(factor, format);
	x->vse = ft_strnew(1);
	while (x->str[x->i])
	{
		if (x->str[x->i] == '%')
		{
			if (find_operator(x, &count) != 0)
				return_arg(factor, x, &count);
		}
		else
//		{
//	ft_putendl(x->vse);
//	ft_putchar(x->str[x->i]);
//			x->vse = ft_add_char(x->vse, x->str[x->i++]);
//		}
		x->i++;
	}
	save_result(x, &count);
	ft_putstr(x->vse);
	va_end(factor);
//	while (--count >= 0)
//	{
//		ft_putendl(x->allargs[count]);
//	}
	return (0);
}
