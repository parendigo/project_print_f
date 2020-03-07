/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:54:50 by mmahasim          #+#    #+#             */
/*   Updated: 2020/03/05 15:07:18 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		podrezal_g_e_f(t_tab *x)
{
	char *tmp;

	if (x->cf == 'e' || x->cf == 'g')
	{
		x->e = 1;
		ft_strdel(&x->gotov_e);
		x->gotov_e = ft_strjoin(x->celoe, x->str_ostatok + 1);
		ft_exp_forma(x);
		x->c_and_exp = ft_strsub(x->gotov_e, 0, 1);
		if (x->cf == 'g')
			ft_tochnost_g(x);
		tmp = ft_okruglenie(x);
		ft_strdel(&x->gotov_e);
		x->gotov_e = tmp;
		tmp = NULL;
		tmp = ft_strjoin(x->c_and_exp, x->gotov_e);
		ft_strdel(&x->gotov_e);
		x->gotov_e = ft_strjoin(tmp, x->exp_e);
		ft_strdel(&tmp);
		if (x->cf != 'g')
			x->allargs[x->co] = ft_strdup(x->gotov_e);
	}
}

void		change_i_one(t_tab *x)
{
	char	*tmp;

	(x->i1)++;
	while (x->gotov_e[x->i1] == '0')
		(x->i1)++;
	if (x->i1 == 101)
	{
		x->exp_e = ft_strdup("e+00");
		return ;
	}
	else if (x->i1 - 1 < 10)
		x->exp_e = ft_strrejoin("e-0", ft_itoa(x->i1 - 1), 2);
	else
		x->exp_e = ft_strjoin("e-", ft_itoa(x->i1 - 1));
	x->c[0] = x->gotov_e[x->i1];
	tmp = ft_strsub(x->gotov_e, x->i1 + 1, ft_strlen(x->gotov_e));
	ft_strdel(&x->gotov_e);
	x->gotov_e = ft_strrejoin(x->c, ft_strrejoin(".", tmp, 2), 2);
	ft_strdel(&x->c);
}

void		ft_exp_forma(t_tab *x)
{
	char	*bt;
	char	*tmp;

	x->i1 = 0;
	x->c = ft_strnew(1);
	while (x->gotov_e[x->i1] != '.')
		x->i1++;
	if (x->i1 == 1)
		change_i_one(x);
	else
	{
		if (x->i1 - 1 < 10)
			x->exp_e = ft_strrejoin("e+0", ft_itoa(x->i1 - 1), 2);
		else
			x->exp_e = ft_strrejoin("e+", ft_itoa(x->i1 - 1), 2);
		tmp = ft_strsub(x->gotov_e, x->i1 + 1, ft_strlen(x->gotov_e));
		bt = ft_strrejoin(ft_strsub(x->gotov_e, 0, x->i1), tmp, 1);
		ft_strdel(&tmp);
		x->i1 = 0;
		x->c[0] = x->gotov_e[x->i1];
		ft_strdel(&x->gotov_e);
		x->gotov_e = ft_strrejoin(x->c, ft_strjoin(".", bt + x->i1 + 1), 2);
		ft_strdel(&bt);
	}
	ft_strdel(&x->c);
}

void		prosto_sokratil_ft_e_or_f(t_tab *x, int len)
{
	if (find_octotorp(x->allforms[x->co]) != 0)
		x->allargs[x->co] = ft_strdup(x->gotov_e);
	else
	{
		len = ft_strlen(x->gotov_e) - 5;
		if (x->gotov_e[len] != '0')
		{
			x->allargs[x->co] = ft_strdup(x->gotov_e);
			return ;
		}
		while (x->gotov_e[len] == '0')
			x->gotov_e[len--] = '\0';
		if (x->gotov_e[len] == '.')
		{
			ft_strdel(&x->allargs[x->co]);
			x->allargs[x->co] = ft_strjoin(x->c_and_exp, x->exp_e);
		}
		else
		{
			ft_strdel(&x->allargs[x->co]);
			x->allargs[x->co] = ft_strjoin(x->gotov_e, x->exp_e);
		}
	}
}

void		ft_e_or_f(t_tab *x)
{
	int len;

	len = 0;
	if (((x->tochnost + x->j) > ft_atoi(x->exp_e + 2) && x->exp_e[1] == '+') ||
	(x->exp_e[1] == '-' && x->celoe[0] > '0') ||
	(ft_atoi(x->exp_e + 2) < 5 && x->celoe[0] == '0'))
	{
		if (find_octotorp(x->allforms[x->co]) == 0)
		{
			len = ft_strlen(x->gotov_f) - 1;
			while (x->gotov_f[len] == '0' && len >= 0)
				x->gotov_f[len--] = '\0';
			if (x->gotov_f[len] == '.')
				x->gotov_f[len] = '\0';
			if (len < 0)
			{
				x->allargs[x->co] = ft_strdup(x->celoe);
				return ;
			}
		}
		x->allargs[x->co] = ft_strdup(x->gotov_f);
	}
	else if (x->tochnost + x->j <= ft_atoi(x->exp_e + 2) ||
			(ft_atoi(x->exp_e + 2) >= 5 && x->celoe[0] == '0'))
		return (prosto_sokratil_ft_e_or_f(x, len));
}
