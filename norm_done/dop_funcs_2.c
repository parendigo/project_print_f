/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_funcs_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:15:51 by mmahasim          #+#    #+#             */
/*   Updated: 2020/03/10 15:03:59 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		podrezal_esche_raz(t_tab *x)
{
	char	*tmp;

	if (x->cf == 'f' || x->cf == 'g')
	{
		x->e = 0;
		tmp = ft_okruglenie(x);
		x->gotov_f = ft_strjoin(x->celoe, tmp);
		ft_strdel(&tmp);
		if (x->cf != 'g')
			x->allargs[x->co] = ft_strdup(x->gotov_f);
	}
	if (x->cf == 'g')
		ft_e_or_f(x);
	if (x->nk == 1)
		x->allargs[x->co] = ft_strrejoin("-", x->allargs[x->co], 2);
	ft_strdel(&x->celoe);
	ft_strdel(&x->str_ostatok);
	ft_strdel(&x->okrug_ostatok);
	ft_strdel(&x->gotov_f);
	ft_strdel(&x->gotov_e);
	ft_strdel(&x->exp_e);
	ft_strdel(&x->c_and_exp);
}

void		double_sub_zero_exp(t_tab *x, long double stepen_dva,
		int exp, t_double *d1)
{
	int i;

	i = 0;
	while (i > exp)
	{
		stepen_dva *= 2;
		i--;
	}
	ft_stolbik(1 + ((long double)d1->di.m / 4503599627370496),
	stepen_dva, x);
}

void		okruglenie_sokr(t_tab *x, int len)
{
	while (len != 1)
	{
		x->okrug_ostatok[len]++;
		if (x->okrug_ostatok[len] == ':')
			x->okrug_ostatok[len] = '0';
		if (x->okrug_ostatok[len] != '0')
			break ;
		len--;
	}
	if ((x->okrug_ostatok[2] == '0' && len == 1) || x->tochnost == 0)
	{
		okruglenie_sokr_one(x, &len);
		while (len >= 0)
		{
			if (change_to_ten(x, &len) == 1)
				len = len + 0;
			else
				break ;
			len--;
		}
	}
}

void		ukrotil_tochku_g(t_tab *x)
{
	if ((x->tochnost > ft_atoi(x->exp_e + 2) && x->exp_e[1] == '+') ||
		(x->celoe[0] == '0' && ft_atoi(x->exp_e + 2) == 100))
	{
		x->j = ft_strlen(x->celoe);
		x->tochnost -= x->j;
	}
	else
	{
		if (x->tochnost > 0)
			x->tochnost--;
	}
}

int			check_five(t_tab *x, int len)
{
	len++;
	while (x->okrug_ostatok[len])
	{
		if (x->okrug_ostatok[len] != '0')
			return (1);
		len++;
	}
	return (0);
}
