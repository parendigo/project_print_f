/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:50:13 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/27 16:49:47 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		find_dollar(t_tab *x, int count)
{
	int		i;
	int		l;
	int		co;
	int		flag;
	int		cflag;

	i = 0;
	co = 0;
	flag = 0;
	x->dollarcount[0] = 0;
	while (co < count)
	{
		cflag = flag;
		i = 0;
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
		if (cflag == flag)
		{
			if (x->dollarcount[co - 1] + 1 <= count)
				x->dollarcount[co] = x->dollarcount[co - 1] + 1;
			else
				x->dollarcount[co] = co + 1;
		}
		co++;
	}
	return (1);
}

void	ft_save(t_tab *x, int *count)
{
	x->allargs[*count] = ft_strdup(x->result);
	ft_strdel(&x->result);
}

int		skip(t_tab *x, int *i)
{
	int		j;

	j = 1;
	while (x->str[*i + j])
	{
		if (compare_fsn(x->str[*i + j], x->str[*i + j -1]) == 1)
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

int	ft_vivod(char *str, char c)
{
	int i = 0;

	if (c != 'r')
	{
		ft_putstr(str);
		return (0);
	}
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

void	save_result(t_tab *x, int *count)
{
	int 		i;
	int			co;

	i = 0;
	co = 0;
	find_dollar(x, *count);
	while (x->str[i])
	{
		if (x->str[i] == '%')				
		{
			if (skip(x, &i) != 0)
			{
			if ((x->allforms[co][((int)ft_strlen(x->allforms[co]) - 1)]) == 'c' &&
					!x->allargs[x->dollarcount[co] - 1][0])
				exception(x, co);
//			ft_putstr(x->allargs[x->dollarcount[co] - 1]);
			ft_vivod(x->allargs[x->dollarcount[co] - 1],
					x->allforms[x->dollarcount[co] - 1][ft_strlen(x->allforms[x->dollarcount[co] - 1]) - 1]);
			co++;
			}
		}
		else
			ft_putchar(x->str[i++]);
	}
	ft_strdel(&x->str);
	co = 0;
	while (co < *count)
		ft_strdel(&x->allargs[co++]);
}
