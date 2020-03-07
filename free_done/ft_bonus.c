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

void	change_i_one(t_tab *x, int *i, char **c)
{
    char	*tmp;

    (*i)++;
//	*c = ft_strnew(1);
	while (x->gotov_e[*i] == '0')
		(*i)++;
	if (*i == 101)
	{
	    x->exp_e = ft_strdup("e+00");
        return ;
    }
	else if (*i - 1 < 10)
        x->exp_e = ft_strrejoin("e-0", ft_itoa(*i - 1), 2);
	else
        x->exp_e = ft_strjoin("e-", ft_itoa(*i - 1));
	*c[0] = x->gotov_e[*i];
	tmp = ft_strsub(x->gotov_e, *i + 1, ft_strlen(x->gotov_e));
	ft_strdel(&x->gotov_e);
	x->gotov_e = ft_strrejoin(*c, ft_strrejoin(".", tmp, 2), 2);
	ft_strdel(c);
}

void	ft_exp_forma(t_tab *x)
{
	int		i;
	char	*c;
	char	*bt;
	char	*tmp;

	i = 0;
    c = ft_strnew(1);
	while (x->gotov_e[i] != '.')
		i++;
	if (i == 1)
		change_i_one(x, &i, &c);
	else
	{
		if (i - 1 < 10)
			x->exp_e = ft_strrejoin("e+0", ft_itoa(i - 1), 2);
		else
			x->exp_e = ft_strrejoin("e+", ft_itoa(i - 1), 2);
		tmp = ft_strsub(x->gotov_e, i + 1, ft_strlen(x->gotov_e));
		bt = ft_strrejoin(ft_strsub(x->gotov_e, 0, i), tmp, 1);
		ft_strdel(&tmp);
		i = 0;
		c[0] = x->gotov_e[i];
        ft_strdel(&x->gotov_e);
		x->gotov_e = ft_strrejoin(c, ft_strjoin(".", bt + i + 1), 2);
		ft_strdel(&bt);
	}
	ft_strdel(&c);
}

int	 prosto_sokratil_ft_e_or_f(t_tab *x, int len)
{
	if (find_octotorp(x->allforms[x->co]) != 0)
    {
	    x->allargs[x->co] = ft_strdup(x->gotov_e);
	    return (1);
    }
	else
	{
		len = ft_strlen(x->gotov_e) - 5;
		if (x->gotov_e[len] != '0')
        {
            x->allargs[x->co] = ft_strdup(x->gotov_e);
            return (1);
        }
		while (x->gotov_e[len] == '0')
		{
			x->gotov_e[len] = '\0';
			len--;
		}
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
		return (1);
	}
}

int	ft_e_or_f(t_tab *x)
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
                return (1);
            }
		}
        x->allargs[x->co] = ft_strdup(x->gotov_f);
		return (1);
	}
	if (x->tochnost + x->j <= ft_atoi(x->exp_e + 2) ||
			(ft_atoi(x->exp_e + 2) >= 5 && x->celoe[0] == '0'))
	{
		return (prosto_sokratil_ft_e_or_f(x, len));
	}
	return (1);
}
