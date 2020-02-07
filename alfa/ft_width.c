/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:59:36 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/07 18:13:40 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Кроме ширины здесь флаг '-', '0'. */

#include "printf.h"

int		find_width(char *str)
{
	int		i;
	int		n;

	i = 1;
	n = 0;
	while (str[i])
	{
		if (NUMBER(str[i]) && str[i - 1] != '.' && NOTNB(str[i - 1]))
			n = i;
		i++;
	}
	return (n == 0 ? 0 : n);
}

void	p_change_x(t_tab *x, int wdt)
{
	int		i;

	i = 0;
	if (wdt > (int)ft_strlen(x->gotov))
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
	if (SYMBOLS1(x->cf))
	{
		if (x->gotov[0] == '-' || x->gotov[0] == '+' || x->gotov[0] == ' ')
		{
			x->result = ft_memal(wdt, '0');
			x->result[0] = x->gotov[0];
			i++;
			len++;
			while (x->gotov[++i])
				x->result[len++] = x->gotov[i];
			return 0;
		}
	}
	x->result = ft_memal(wdt, '0');
	while (x->gotov[++i])
		x->result[len++] = x->gotov[i];
	p_change_x(x, wdt);
	return 0;
}

int		zapol_width(t_tab *x, int wdt)
{
	int		i;
	int		len;

	len = ft_strlen(x->result) - ft_strlen(x->gotov);
	i = -1;
	if (find_minus(x->form) == 1)
	{
		if (x->cf == 'c' && !x->gotov[0])
		{
			x->result = ft_memal(wdt - 1, ' ');
			ft_putchar(x->gotov[0]);
			ft_putstr(x->result);
			x->result = NULL;
		}
		else
			while (x->gotov[++i])
				x->result[i] = x->gotov[i];
	}
	else if (find_zero(x->form) == 1 && find_dot(x->form) == 0)
	{
		zero_pol(x, wdt, len, i);
	}
	else
	{
		if (x->cf == 'c' && !x->gotov[0])
		{
			x->result = ft_memal(wdt - 1, ' ');
			ft_putstr(x->result);
			ft_putchar(x->gotov[0]);
			x->result = NULL;
		}
		else
			while (x->gotov[++i])
				x->result[len++] = x->gotov[i];
	}
	return 0;
}

int		ft_width(t_tab *x)
{
	int		nu;
	int		wdt;

	if ((nu = find_width(x->form)) == 0)
	{
		if (x->cf == 'c' && !x->gotov[0])
		{
			ft_putchar(x->gotov[0]);
			x->result = NULL;
		}
		else
			x->result = ft_strdup(x->gotov);
		return 0;
	}
	wdt = ft_atoi(x->form + nu);
	if (wdt > (int)ft_strlen(x->gotov))
	{
		x->result = ft_memal(wdt, ' ');
		zapol_width(x, wdt);
	}
	else
		x->result = ft_strdup(x->gotov);
	return 1;
}
