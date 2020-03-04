/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gotov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:35:37 by mmahasim          #+#    #+#             */
/*   Updated: 2020/01/18 17:35:41 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void ft_gotov(va_list factor, t_tab *x)
{
	if (x->cf == 'x' || x->cf == 'X' || x->cf == 'i'
	|| x->cf == 'd' || x->cf == 'u' || x->cf == 'o')
		ft_str_number(factor, x);
	if (x->cf == 'p')
	{
		x->allargs[x->co] = ft_itoa_base(va_arg(factor, long int), 16, x, 'l');
		x->allargs[x->co] = ft_strjoin("0x" , x->allargs[x->co]);
	}
	if (x->cf == 's' )
		x->allargs[x->co] = ft_strdup(va_arg(factor, char*));
	if (x->cf == 'c')
	{
		x->allargs[x->co] = ft_strnew(1);
		x->allargs[x->co][0] = va_arg(factor, int);
	}
}

void	ft_str_number(va_list factor, t_tab *x)
{
	int base;

	base = 10;
	if (x->cf == 'x' || x->cf == 'X')
		base = 16;
	if (x->cf == 'o')
		base = 8;
	if (form_ll(x->allforms[x->co]) == 1)
		x->allargs[x->co] = ft_itoa_base(va_arg(factor, long long int), base, x, 'l');
	else if (form_ll(x->allforms[x->co]) == 2)
		x->allargs[x->co] = ft_itoa_base(va_arg(factor, long int), base, x, 'l');
	else if (form_hh(x->allforms[x->co]) == 1)
		x->allargs[x->co] = ft_itoa_base((signed char)va_arg(factor, int), base, x, 'h');
	else if (form_hh(x->allforms[x->co]) == 2)
		x->allargs[x->co] = ft_itoa_base((short int)va_arg(factor, int), base, x, 's');
	else
		x->allargs[x->co] = ft_itoa_base(va_arg(factor, int), base, x, 'n');
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