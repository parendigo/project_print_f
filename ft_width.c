/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:59:36 by mlarraq           #+#    #+#             */
/*   Updated: 2020/01/19 18:45:31 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Кроме ширины здесь флаг '-' */

#include "printf.h"

int		find_minus(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

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

int		find_zero(char *str)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (str[i] == '0' && NUNE19(str[i - 1]))
			return (1);
		i++;
	}
	return (0);
}

int		zapol_width(t_tab *x, int wdt)
{
	int		i;
	int		len;

	len = ft_strlen(x->result) - ft_strlen(x->gotov);
	i = 0;
	if (find_minus(x->form) == 1)
	{
		while (x->gotov[i])
		{
			x->result[i] = x->gotov[i];
			i++;
		}
	}
	else if (find_zero(x->form) == 1)
	{
		x->result = ft_memal(wdt, '0');
		while (x->gotov[i])
			x->result[len++] = x->gotov[i++];
	}
	else
	{
		while (x->gotov[i])
		{
			x->result[len++] = x->gotov[i++];
		}
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
