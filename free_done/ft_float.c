/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:13:46 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/19 19:18:57 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_float(va_list factor, t_tab *x)
{
	t_double	*d1;

	x->nk = 0;
	d1 = malloc(sizeof(t_double));
	d1->d = find_big_l(x->allforms[x->co], factor);
	if (d1->di.z == 1)
	{
		d1->d = d1->d * -1;
		x->nk = 1;
	}
	if (d1->d <= 922337203685477580.0)
		x->celoe = ft_itoa_b(d1->d, 10, x, 'a');
	else
		x->celoe = ft_celoe(d1, x);
	ft_posle_tochki(d1, x);
	podrezal_g_e_f(x);
	podrezal_esche_raz(x);
	free(d1);
}

long double	find_big_l(char *form, va_list factor)
{
	int i;

	i = 0;
	while (form[i] != '\0')
	{
		if (form[i] == 'L')
			return (va_arg(factor, long double));
		i++;
	}
	return (va_arg(factor, double));
}

void		ft_posle_tochki(t_double *d1, t_tab *x)
{
	long double	stepen_dva;
	int			i;
	int			exp;

	i = 0;
	stepen_dva = 1;
	exp = d1->di.e - 1023;
	if (exp > 0)
	{
		if (exp == 0)
			stepen_dva = 4503599627370496;
		if (exp > 0)
		{
			while (i < 52 - exp)
			{
				stepen_dva *= 2;
				i++;
			}
			d1->di.m <<= exp - 1;
			d1->di.m >>= exp - 1;
		}
		ft_stolbik(d1->di.m, stepen_dva, x);
	}
	else
		double_sub_zero_exp(x, stepen_dva, exp, d1);
}

char		*ft_okruglenie(t_tab *x)
{
	int		len;

	len = x->tochnost + 2;
	if (x->e == 1)
		x->okrug_ostatok = ft_strdup(x->gotov_e);
	else
	{
		ft_strdel(&x->okrug_ostatok);
		x->okrug_ostatok = ft_strdup(x->str_ostatok);
	}
	if (x->okrug_ostatok[len] >= '5')
		okruglenie_sokr(x, len - 1);
	if (x->tochnost == 0 && find_octotorp(x->allforms[x->co]) == 0)
		return (ft_strsub(x->okrug_ostatok, 1, x->tochnost));
	return (ft_strsub(x->okrug_ostatok, 1, x->tochnost + 1));
}

int			ft_tochnost_g(t_tab *x)
{
	int i;

	x->j = 0;
	ukrotil_tochku_g(x);
	i = 0;
	if (x->celoe[0] == '0' && ft_atoi(x->exp_e + 2) < 5 &&
	ft_atoi(x->exp_e) != 100)
	{
		if (x->str_ostatok[2] == '0')
		{
			while (x->str_ostatok[i + 2] == '0')
				i++;
			x->tochnost += i + 1;
		}
		else
			x->tochnost += i + 1;
	}
	if (x->celoe[0] == '0' && ft_atoi(x->exp_e + 2) == 100)
		x->exp_e = ft_strdup("0000000");
	return (1);
}
