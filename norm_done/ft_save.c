/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:50:13 by mlarraq           #+#    #+#             */
/*   Updated: 2020/03/08 16:33:18 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		find_dollar(t_tab *x)
{
	int		co;
	int		flag;
	int		cflag;

	co = 0;
	flag = 0;
	x->dollarcount[0] = 0;
	while (co < x->co)
	{
		cflag = flag;
		flag = dollar_numbers(x, co, flag);
		if (cflag == flag)
		{
			if (co > 0)
			{
				if (x->dollarcount[co - 1] + 1 <= x->co)
					x->dollarcount[co] = x->dollarcount[co - 1] + 1;
				else
					x->dollarcount[co] = co + 1;
			}
			else if (x->dollarcount[co] == 0)
				x->dollarcount[co] = co + 1;
		}
		co++;
	}
}

int			skip(t_tab *x, int *i)
{
	int		j;

	j = 1;
	while (x->str[*i + j])
	{
		if (compare_fsn(x->str[*i + j], x->str[*i + j - 1]) == 1)
			j = j + 0;
		else if (compare_symbols(x->str[*i + j]) == 1)
		{
			*i = *i + j + 1;
			return (1);
		}
		else
			break ;
		j++;
	}
	*i = *i + j;
	return (0);
}

int			ft_vivod(char *str, char c)
{
	int i;

	i = 0;
	if (c != 'r')
		return (ft_putstr(str));
	while (str[i])
	{
		if (str[i] >= 0 && str[i] <= 32)
		{
			if (str[i] == 9)
				ft_putstr("\\t");
			else if (str[i] == 10)
				ft_putstr("\\n");
			else
			{
				ft_putchar('^');
				ft_putchar(str[i] + 64);
			}
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	ft_putstr("^@");
	return (0);
}

void		cycle_print(t_tab *x, int *co)
{
	char	c;
	int		len;

	c = x->allforms[*co][((int)ft_strlen(x->allforms[*co]) - 1)];
	if (c == 'c' && !x->allargs[x->dollarcount[*co] - 1][0])
		exception(x, *co);
	len = ft_strlen(x->allforms[x->dollarcount[*co] - 1]) - 1;
	ft_vivod(x->allargs[x->dollarcount[*co] - 1],
			x->allforms[x->dollarcount[*co] - 1][len]);
	x->lengovna = x->lengovna + ft_strlen(x->allargs[x->dollarcount[*co] - 1]);
}

void		save_result(t_tab *x)
{
	int		i;
	int		co;

	x->lengovna = 0;
	i = 0;
	co = 0;
	find_dollar(x);
	while (x->str[i])
	{
		if (x->str[i] == '%')
		{
			if (skip(x, &i) != 0)
			{
				cycle_print(x, &co);
				co++;
			}
		}
		else
		{
			x->lengovna++;
			ft_putchar(x->str[i++]);
		}
	}
	clean_tabs(x);
}
