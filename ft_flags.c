/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:56:31 by mlarraq           #+#    #+#             */
/*   Updated: 2020/01/19 17:23:50 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Здесь флаги: '+', ' ', '0', '#'. */

#include "printf.h"

int		find_plus(char *str)
{
	int		i;

	i = 1;
	while (str[i])
		if (str[i++] == '+')
			return (1);
	return (0);
}

int		find_space(char *str)
{
	int		i;

	i = 1;
	while (str[i])
		if (str[i++] == ' ')
			return (1);
	return (0);
}

int		show_sign(t_tab *x)
{
	char	*res;

	res = (char *)malloc(sizeof(char *) * 2);
	res[1] = '\0';
	if (find_plus(x->form) == 1 && x->gotov[0] != '-')
	{
		res[0] = '+';
		res = ft_strjoin(res, x->gotov);
		x->gotov = ft_strdup(res);
	}
	else if (find_space(x->form) == 1)
	{
		res[0] = ' ';
		res = ft_strjoin(res, x->gotov);
		x->gotov = ft_strdup(res);
	}
	return (0);
}

int		ft_flags(t_tab *x)
{
	if (x->cf == 'd' || x->cf == 'i')
		show_sign(x);
	return 0;
}
