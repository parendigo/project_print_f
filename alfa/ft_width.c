/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:59:36 by mlarraq           #+#    #+#             */
/*   Updated: 2020/01/27 14:25:01 by mlarraq          ###   ########.fr       */
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
		if (NU19(str[i]) && str[i - 1] != '.' && NUNE19(str[i - 1]))
			n = i;
		i++;
	}
	return (n == 0 ? 0 : n);
}

void	p_change_x(t_tab *x, int wdt)
{
	int		i;

	i = 0;
	if (x->cf == 'p' && wdt > ft_strlen(x->gotov))
	{
		while (x->result[i] == '0' && x->result[i])
			i++;
		if (x->result[i] = 'x')
		{
			x->result[i] = '0';
			x->result[1] = 'x';
		}
	}
}

int		zapol_width(t_tab *x, int wdt)
{
	int		i;
	int		len;

	len = ft_strlen(x->result) - ft_strlen(x->gotov);
	i = -1;
	if (find_minus(x->form) == 1)
	{
		while (x->gotov[++i])
			x->result[i] = x->gotov[i];
	}
	else if (find_zero(x->form) == 1)
	{
		x->result = ft_memal(wdt, '0');
		while (x->gotov[++i])
			x->result[len++] = x->gotov[i];
		p_change_x(x, wdt);
	}
	else
	{
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
		x->result = ft_strdup(x->gotov);
		return 0;
	}
	wdt = ft_atoi(x->form + nu);
	if (wdt > ft_strlen(x->gotov))
	{
		x->result = ft_memal(wdt, ' ');
		zapol_width(x, wdt);
	}
	else
		x->result = ft_strdup(x->gotov);
	return 1;
}
