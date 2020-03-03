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
	t_double    *d1;
	char        *tmp;

	x->nk = 0;
	d1 = malloc(sizeof(t_double));
	d1->d = find_big_l(x->form , factor);
	if (d1->di.z == 1)
	{
		d1->d = d1->d * -1;
		x->nk = 1;
	}
	if (d1->d <= 922337203685477580.0)
		x->celoe = ft_itoa_b(d1->d, 10, x, 'a');
	else
	{
		x->celoe = ft_celoe(d1, x);
	}
	ft_posle_tochki(d1, x);
	if (x->cf == 'e' || x->cf == 'g') {
        x->e = 1;
        x->gotov_e = ft_strjoin(x->celoe, x->str_ostatok + 1);
        ft_exp_forma(x);
        x->c_and_exp = ft_strsub(x->gotov_e, 0, 1);
        if (x->cf == 'g')
            x->tochnost = ft_tochnost_g(x);
        x->gotov_e = ft_okruglenie(x);
        tmp = ft_strjoin(x->c_and_exp, x->gotov_e);
        x->gotov_e = ft_strjoin(tmp, x->exp_e);
        ft_strdel(&tmp);
        if (x->cf != 'g')
        {
            x->gotov = ft_strdup(x->gotov_e);
        }
    }
	if (x->cf == 'f' || x->cf == 'g') {
        x->e = 0;
        tmp = ft_okruglenie(x);
        x->gotov_f = ft_strjoin(x->celoe, tmp);
        ft_strdel(&tmp);
        if (x->cf != 'g')
        {
            x->gotov = ft_strdup(x->gotov_f);
        }

	}
	if (x->cf == 'g')
        x->gotov = ft_e_or_f(x);
	if (x->nk == 1)
	{
		x->gotov = ft_strjoin("-", x->gotov);
	}
	ft_strdel(&x->celoe);
	ft_strdel(&x->str_ostatok);
	ft_strdel(&x->okrug_ostatok);
    ft_strdel(&x->gotov_f);
    ft_strdel(&x->gotov_e);
	free(d1);
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
	if (x->e == 1)
		x->okrug_ostatok = ft_strdup(x->gotov_e);
	else
		x->okrug_ostatok = ft_strdup(x->str_ostatok);
	if (x->okrug_ostatok[len] >= '5')
	{
		len--;
		while (len != 1)
		{
			x->okrug_ostatok[len]++;
			if (x->okrug_ostatok[len] == ':')
			{
				x->okrug_ostatok[len] = '0';
			}
			if (x->okrug_ostatok[len] != '0')
				break ;
			len--;
		}
		if ((x->okrug_ostatok[2] == '0' && len == 1) || x->tochnost == 0)
		{
			if (x->e == 1)
			{
				x->c_and_exp[0]++;
				if (x->c_and_exp[0] == ':')
				{
					x->c_and_exp[0] = '1';
					x->exp_e[3]--;
				}
			}
			else
				x->celoe[ft_strlen(x->celoe) - 1]++;
		}
	}
	if (x->tochnost == 0 && find_octotorp(x->form) == 0)
		return (ft_strsub(x->okrug_ostatok, 1, x->tochnost));
	return (ft_strsub(x->okrug_ostatok, 1, x->tochnost + 1));
}

int		ft_tochnost_g(t_tab *x)
{
	int i;

	x->j = 0;
	if ((x->tochnost > ft_atoi(x->exp_e + 2) && x->exp_e[1] == '+') ||
	(x->celoe[0] == '0' && ft_atoi(x->exp_e + 2) == 100))
	{
		x->j = ft_strlen(x->celoe);
		x->tochnost -= x->j;
	}
	else
		if (x->tochnost > 0)
			x->tochnost--;
	i = 0;
	if (x->celoe[0] == '0' && ft_atoi(x->exp_e + 2) < 5 && ft_atoi(x->exp_e) != 100)
	{
		if (x->str_ostatok[2] == '0')
		{
			while (x->str_ostatok[i + 2] == '0')
			{
				i++;
			}
			x->tochnost += i + 1;
		}
		else
			x->tochnost += i + 1;
	}
	if (x->celoe[0] == '0' && ft_atoi(x->exp_e + 2) == 100)
		x->exp_e = ft_strdup("0000000");
	return (x->tochnost);
}
