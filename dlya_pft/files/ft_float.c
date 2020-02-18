/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:13:46 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/06 18:15:36 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void ft_float(va_list factor, t_tab *x)
{
	t_double *d1;
//	l_double *ld1;
	int nk;

	nk = 0;
	d1 = malloc(sizeof(t_double));
//	ld1 = malloc(sizeof(l_double));
	d1->d = find_L(x->form , factor);
//	if ((int)d1->d == 0)
//	{
//		nk = 1;
//	}
	d1->d += nk;
	x->str_ostatok = ft_posle_tochki(x, d1);
	x->str_ostatok = ft_okruglenie(x, d1);
	d1->d -= nk;
	if (d1->d <= 922337203685477580.0 && d1->d >= -922337203685477580.0)
		x->gotov = ft_strjoin(ft_itoa_base(d1->d, 10, x, 'a'), x->str_ostatok);
	else
	{
		x->gotov = ft_strjoin(ft_celoe(d1, x), x->str_ostatok);
	}
}

long double		find_L(char *form,  va_list factor)
{
	int i;

	i = 0;
	while (form[i] != '\0')
	{
		if (form[i] == 'L')
			return (va_arg(factor,long double));
		i++;
	}
	return (va_arg(factor, double));
}

char *ft_okruglenie(t_tab *x, t_double *d1)
{
	int len;

	len = x->tochnost + 1;
	if (x->str_ostatok[len] >= '5')
	{
		len--;
		while (len != 0)
		{
			x->str_ostatok[len]++;
			if (x->str_ostatok[len] == ':')
			{
				x->str_ostatok[len] = '0';
			}
			if (x->str_ostatok[len] != '0')
				break ;
			len--;
		}
		if (x->str_ostatok[1] == '0' && len == 0)
			d1->d++;
	}
	return (ft_strsub(x->str_ostatok, 0, x->tochnost + 1));
}

char *ft_posle_tochki(t_tab *x, t_double *d1)
{
	int len;
	int exp;

	exp = d1->di.e - 1023;
	x->binary_m = ft_itoa_base(d1->di.m, 2, x, 'r');
	len = ft_strlen(x->binary_m);
	if (len < 52)
	{
		while (len < 52)
		{
			x->binary_m = ft_strjoin("0", x->binary_m);
			len++;
		}
	}
	x->binary_ost = ft_strdup(x->binary_m + exp);
	x->str_ostatok = ft_itoa_base(ft_ostatok(x), 10, x, 'a');
	len = ft_strlen(x->str_ostatok);
	while (len < 18)
	{
		x->str_ostatok = ft_strjoin("0", x->str_ostatok);
		len++;
	}
	return (ft_strjoin(".", x->str_ostatok));
}