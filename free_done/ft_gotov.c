/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gotov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:35:37 by mmahasim          #+#    #+#             */
/*   Updated: 2020/02/20 16:52:49 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*make_per(void)
{
	char	*str;

	str = ft_memalloc(2);
	str[0] = '%';
	return (str);
}

int 	ft_tochnost(char *str)
{
	int		dot;
	int		prec;

	if ((dot = find_dot(str)) == 0)
		return (6);
	prec = ft_atoi(str + dot);
	return (prec);
}

void	ft_gotov(va_list factor, t_tab *x)
{
	int len;
	int base;
	char c;

	base = 16;
	x->tochnost = ft_tochnost(x->allforms[x->co]);
	len = ft_strlen(x->allforms[x->co]);
	x->cf = x->allforms[x->co][len - 1];
	if (x->cf == 'x' || x->cf == 'X' || x->cf == 'i'
	|| x->cf == 'd' || x->cf == 'u' || x->cf == 'o' || x->cf == 'b')
		ft_str_number(factor, x);
	else if (x->cf == 'p')
	{
	    x->allargs[x->co] = ft_itoa_b(va_arg(factor, long int), base, x, 'l');
		x->allargs[x->co] = ft_strrejoin("0x" , x->allargs[x->co], 2);
	}
//	else if (x->cf == 's' || x->cf == 'r')
//    {
//        if ((x->allargs[x->co] = va_arg(factor, char*)) == NULL)
//            x->allargs[x->co] = make_null();
//    }
	else if (x->cf == 'r' || x->cf == 's')
	{
//	    if (x->co == 0)
//	    {
            if ((x->allargs[x->co] = ft_strdup(va_arg(factor, char*))) == NULL)
                x->allargs[x->co] = ft_strdup("(null)");
//        }
//	    if (x->co > 0)
//		    if ((x->allargs[x->co] = va_arg(factor, char*)) == NULL)
//		    	x->allargs[x->co] = ft_strdup("(null)");
	}
	else if (x->cf == 'c')
	{

		c = va_arg(factor, int);
		// ft_strdel(&x->allargs[x->co]);
		x->allargs[x->co] = ft_strnew(1);
		x->allargs[x->co][0] = c;
	}
	else if (x->cf == '%')
		x->allargs[x->co] = make_per();
	else if (x->cf == 'f' || x->cf == 'e' || x->cf == 'g')
	{
		ft_float(factor, x);
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
	if (x->cf == 'b')
		base = 2;
	if (form_ll(x->allforms[x->co]) == 1)
		x->allargs[x->co] = ft_itoa_b(va_arg(factor, long long int), base, x, 'l');
	else if (form_ll(x->allforms[x->co]) == 2)
		x->allargs[x->co] = ft_itoa_b(va_arg(factor, long int), base, x, 'l');
	else if (form_hh(x->allforms[x->co]) == 1)
		x->allargs[x->co] = ft_itoa_b((signed char)va_arg(factor, int), base, x, 'h');
	else if (form_hh(x->allforms[x->co]) == 2)
		x->allargs[x->co] = ft_itoa_b((short int)va_arg(factor, int), base, x, 's');
	else
		x->allargs[x->co] = ft_itoa_b(va_arg(factor, int), base, x, 'n');
}

int 	form_hh(char *form)
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

int 	form_ll(char *form)
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
