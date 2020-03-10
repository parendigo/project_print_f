/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_funcs_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:00:52 by mlarraq           #+#    #+#             */
/*   Updated: 2020/03/10 16:00:53 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		make_everything_null(t_tab *x)
{
	x->allargs[x->co] = NULL;
	x->result = NULL;
	x->allforms[x->co] = NULL;
	x->allargs[x->co] = NULL;
	x->str_ostatok = NULL;
	x->gotov_e = NULL;
	x->exp_e = NULL;
	x->celoe = NULL;
	x->gotov_f = NULL;
	x->c_and_exp = NULL;
	x->okrug_ostatok = NULL;
}

int			dollar_numbers(t_tab *x, int co, int flag)
{
	int		i;
	int		l;

	i = 0;
	x->dollarcount[co] = 0;
	while (x->allforms[co][i])
	{
		if (one_nine(x->allforms[co][i - 1]) == 1 && x->allforms[co][i] == '$')
		{
			l = 1;
			while (one_nine(x->allforms[co][i - l]) == 1)
				l++;
			l--;
			x->dollarcount[co] = ft_atoi((x->allforms[co]) + (i - l));
			flag++;
		}
		i++;
	}
	return (flag);
}

void		clean_tabs(t_tab *x)
{
	int		co;

	co = 0;
	while (co < x->co)
		ft_strdel(&x->allargs[co++]);
	ft_strdel(&x->str);
	co = 0;
	while (x->allforms[co])
		ft_strdel(&x->allforms[co++]);
}
