/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_funcs_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:01:21 by mlarraq           #+#    #+#             */
/*   Updated: 2020/03/10 15:41:08 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		okruglenie_sokr_one(t_tab *x, int *len)
{
	if (x->e == 1)
	{
		x->c_and_exp[0]++;
		if (x->c_and_exp[0] == ':')
		{
			x->c_and_exp[0] = '1';
			if (x->exp_e[1] == '-')
			{
				x->exp_e[3]--;
				if (x->exp_e[3] == '/')
				{
					x->exp_e[3] = '9';
					x->exp_e[2]--;
				}
			}
			if (x->exp_e[1] == '+')
				x->exp_e[3]++;
		}
	}
	else
	{
		*len = ft_strlen(x->celoe) - 1;
		x->celoe[*len]++;
	}
}

int			change_to_ten(t_tab *x, int *len)
{
	char	*tmp;

	if (x->celoe[*len] == ':' && *len > 0)
	{
		x->celoe[*len] = '0';
		x->celoe[*len - 1]++;
		return (1);
	}
	else if (x->celoe[*len] == ':' && *len == 0)
	{
		x->celoe[*len] = '0';
		tmp = ft_strdup(x->celoe);
		ft_strdel(&x->celoe);
		x->celoe = ft_strrejoin("1", tmp, 2);
		return (1);
	}
	return (0);
}

void		p_chan_x(t_tab *x)
{
	int		i;

	i = 0;
	if (x->cf == 'p' || x->cf == 'x' || x->cf == 'X')
	{
		while (x->allargs[x->co][i] == '0' && x->allargs[x->co][i])
			i++;
		if ((x->allargs[x->co][i] == 'x' || x->allargs[x->co][i] == 'X') &&
			i > 1)
		{
			x->allargs[x->co][1] = x->allargs[x->co][i];
			x->allargs[x->co][i] = '0';
		}
	}
}

void		prec_put_sign(t_tab *x, int prec, int *lenprec)
{
	char *res;

	if ((*lenprec = prec - (int)ft_strlen(x->allargs[x->co]) + 1) > 0)
	{
		res = ft_memal(*lenprec, '0');
		res = ft_strrejoin(res, x->allargs[x->co], 1);
		swaperino(&res[0], &res[*lenprec]);
		x->allargs[x->co] = ft_strdup(res);
		ft_strdel(&res);
	}
}

void		scp_convertion(t_tab *x, int *prec)
{
	char	*tmp;

	if ((int)ft_strlen(x->allargs[x->co]) > *prec)
	{
		if (x->cf == 'p' && *prec == 0 &&
		(int)ft_strlen(x->allargs[x->co]) == 3)
		{
			if (x->allargs[x->co][2] == '0')
				tmp = ft_strsub(x->allargs[x->co], 0, *prec + 2);
		}
		else if (x->cf == 'p')
			tmp = ft_strsub(x->allargs[x->co], 0, 2147483647);
		else
			tmp = ft_strsub(x->allargs[x->co], 0, *prec);
		x->allargs[x->co] = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
}
