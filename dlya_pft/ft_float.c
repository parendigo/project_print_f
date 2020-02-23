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

void	ft_float(va_list factor, t_tab *x)
{
	t_double *d1;

	x->nk = 0;
	d1 = malloc(sizeof(t_double));
	d1->d = find_big_l(x->form , factor);
	if (d1->di.z == 1)
	{
		d1->d = d1->d * -1;
		x->nk = 1;
	}
	if (d1->d <= 922337203685477580.0 && d1->d >= -922337203685477580.0)
		x->gotov = ft_strdup(ft_itoa_b(d1->d, 10, x, 'a'));
	else
	{
		x->gotov = ft_strdup(ft_celoe(d1, x));
	}
	if (x->nk == 1)
	{
		x->gotov = ft_strjoin("-", x->gotov);
	}
	ft_posle_tochki(d1, x);
	x->gotov = ft_strjoin(x->gotov, ft_okruglenie(x));
}

long double		find_big_l(char *form,  va_list factor)
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

void	ft_posle_tochki(t_double *d1, t_tab *x)
{
	long double stepen_dva;
	int i;
	int exp;

	i = 0;
	stepen_dva = 1;
	exp = d1->di.e - 1023;
	if (exp >= 0)
	{
		if (exp == 0)
			stepen_dva = 4503599627370496;
		if (exp > 0)
		{
			stepen_dva = 1;
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
	{
		while (i > exp)
		{
			stepen_dva *= 2;
			i--;
		}
		ft_stolbik(1 + ((long double)d1->di.m/4503599627370496), stepen_dva, x);
	}
}

char	*ft_okruglenie(t_tab *x)
{
	int len;

	len = x->tochnost + 2;
	if (x->str_ostatok[len] >= '5')
	{
		len--;
		while (len != 1)
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
		if ((x->str_ostatok[2] == '0' && len == 1) || x->tochnost == 0)
			x->gotov[ft_strlen(x->gotov) - 1]++;
	}
	if (x->tochnost == 0 && find_octotorp(x->form) == 0)
		return (ft_strsub(x->str_ostatok, 1, x->tochnost));
	return (ft_strsub(x->str_ostatok, 1, x->tochnost + 1));
}
