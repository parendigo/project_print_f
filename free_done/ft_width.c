/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:59:36 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/27 16:34:10 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	p_change_x(t_tab *x, int wdt)
{
	int		i;

	i = 0;
	if (wdt > (int)ft_strlen(x->allargs[x->co]))
	{
		if (x->cf == 'p' || x->cf == 'x' || x->cf == 'X')
		{
			while (x->result[i] == '0' && x->result[i])
				i++;
			if (x->result[i] == 'x' || x->result[i] == 'X')
			{
				x->result[1] = x->result[i];
				x->result[i] = '0';
			}
		}
	}
}

int		zero_pol(t_tab *x, int wdt, int len, int i)
{
	if (lf_diouxx(x->cf) || x->cf == 'f')
	{
		if (x->allargs[x->co][0] == '-' || x->allargs[x->co][0] == '+' || x->allargs[x->co][0] == ' ')
		{
			ft_strdel(&x->result);
			x->result = ft_memal(wdt, '0');
			x->result[0] = x->allargs[x->co][0];
			i++;
			len++;
			while (x->allargs[x->co][++i])
				x->result[len++] = x->allargs[x->co][i];
			return (0);
		}
	}
	ft_strdel(&x->result);
	x->result = ft_memal(wdt, '0');
	while (x->allargs[x->co][++i])
		x->result[len++] = x->allargs[x->co][i];
	p_change_x(x, wdt);
	return (0);
}

void	print_exep(t_tab *x, int wdt, int how, int co)
{
	if (how == 1)
	{
		x->result = ft_memal(wdt - 1, ' ');
		ft_putchar(x->allargs[co][0]);
		ft_putstr(x->result);
//		x->result = NULL;
	}
	if (how == 2)
	{
		x->result = ft_memal(wdt - 1, ' ');
		ft_putstr(x->result);
		ft_putchar(x->allargs[co][0]);
//		x->result = NULL;
	}
//	ft_strdel(&x->result);
}

int		zapol_width(t_tab *x, int wdt)
{
	int		i;
	int		len;

	len = ft_strlen(x->result) - ft_strlen(x->allargs[x->co]);
	i = -1;
	if (find_minus(x->allforms[x->co]) == 1)
	{
		if (x->cf == 'c' && !x->allargs[x->co][0])
			x->result = ft_strdup(x->allargs[x->co]);
		else
			while (x->allargs[x->co][++i])
				x->result[i] = x->allargs[x->co][i];
	}
	else if (find_zero(x->allforms[x->co]) == 1 && (!find_dot(x->allforms[x->co]) || x->cf == 'f'))
		zero_pol(x, wdt, len, i);
	else
	{
		if (x->cf == 'c' && !x->allargs[x->co][0])
			x->result = ft_strdup(x->allargs[x->co]);
		else
			while (x->allargs[x->co][++i])
				x->result[len++] = x->allargs[x->co][i];
	}
	return (0);
}

int		ft_width(t_tab *x)
{
	int		nu;
	int		wdt;

	if ((nu = find_width(x->allforms[x->co])) == 0)
	{
		// write(1, "YOYOYOY\n", 8);
		// x->result = x->allargs[x->co];
		// x->allargs[x->co] = NULL;
		// ft_strdel(&x->result);
	    // printf("x->allargs[%d] = %s\n", x->co, x->allargs[x->co]);

		return (0);
	}
	wdt = ft_atoi(x->allforms[x->co] + nu);
	if (wdt > (int)ft_strlen(x->allargs[x->co]))
	{
		ft_strdel(&x->result);
        x->result = ft_memal(wdt, ' ');
        zapol_width(x, wdt);
    }
	else
		x->result = ft_strdup(x->allargs[x->co]);
	ft_strdel(&x->allargs[x->co]);
	x->allargs[x->co] = x->result;
	x->result = NULL;

    // x->allargs[x->co + 1] = NULL;
    // ft_strdel(&x->result);
//	if (x->cf = 'c')
//	    ft_strdel(&x->allargs[x->co]);
	return (1);
}