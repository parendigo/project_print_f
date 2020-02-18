/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gotov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:35:37 by mmahasim          #+#    #+#             */
/*   Updated: 2020/02/06 16:26:18 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*make_per()
{
	char	*str;

	str = ft_memalloc(2);
	str[0] = '%';
	return (str);
}

char	*make_null()
{
	char	*str = "(null)";

	return (str);
}

void	ft_gotov(va_list factor, t_tab *x)
{
	int len;
	int base;

	base = 16;
	len = ft_strlen(x->form);
	x->cf = x->form[len - 1];
	if (x->cf == 'x' || x->cf == 'X' || x->cf == 'i'
	|| x->cf == 'd' || x->cf == 'u' || x->cf == 'o')
		ft_str_number(factor, x);
	if (x->cf == 'p')
	{
		x->gotov = ft_itoa_base(va_arg(factor, long int), base, x, 'l');
		x->gotov = ft_strjoin("0x" , x->gotov);
	}
	if (x->cf == 's' )
	{
		if ((x->gotov = ft_strdup(va_arg(factor, char*))) == NULL)
			x->gotov = make_null();
	}
	if (x->cf == 'c')
	{
		x->gotov = ft_strnew(1);
		x->gotov[0] = va_arg(factor, int);
	}
	if (x->cf == '%')
		x->gotov = make_per();
	if (x->cf == 'f')
		ft_float(va_arg(factor, double), x);
}

void	ft_str_number(va_list factor, t_tab *x)
{
	int base;

	base = 10;
	if (x->cf == 'x' || x->cf == 'X')
		base = 16;
	if (x->cf == 'o')
		base = 8;
	if (form_ll(x->form) == 1)
		x->gotov = ft_itoa_base(va_arg(factor, long long int), base, x, 'l');
	else if (form_ll(x->form) == 2)
		x->gotov = ft_itoa_base(va_arg(factor, long int), base, x, 'l');
	else if (form_hh(x->form) == 1)
		x->gotov = ft_itoa_base((signed char)va_arg(factor, int), base, x, 'h');
	else if (form_hh(x->form) == 2)
		x->gotov = ft_itoa_base((short int)va_arg(factor, int), base, x, 's');
	else
		x->gotov = ft_itoa_base(va_arg(factor, int), base, x, 'n');
}

int form_hh(char *form)
{
	int i;

	i = 0;
	while (form[i])
	{
		if (form[i] == 'h' && form[i + 1] == 'h')
			return 1;
		if (form[i] == 'h' && form[i + 1] != 'h')
			return 2;
		i++;
	}
	return 0;
}

int form_ll(char *form)
{
	int i;

	i = 0;
	while (form[i])
	{
		if (form[i] == 'l' && form[i + 1] == 'l')
			return (1);
		if (form[i] == 'l' && form[i + 1] != 'l')
			return (2);
		i++;
	}
	return (0);
}
