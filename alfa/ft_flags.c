/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:56:31 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/19 16:26:12 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Здесь флаги: '+', ' ', '#'. */

#include "printf.h"

int		show_sign(t_tab *x)
{
	char	*res;

	res = (char *)malloc(sizeof(char *) * 2);
	res[1] = '\0';
	if (find_plus(x->form) == 1 && x->gotov[0] != '-')
	{
		res[0] = '+';
		x->gotov = ft_strjoin(res, x->gotov);
	}
	else if (find_space(x->form) == 1)
	{
		res[0] = ' ';
		x->gotov = ft_strjoin(res, x->gotov);
	}
	return (0);
}

int		use_octo(t_tab *x)
{
	char	*res;

	if (find_octotorp(x->form) == 0 || x->ar == 0 )
		return (0);
	if (x->cf == 'o')
	{
		res = (char *)malloc(sizeof(char *) * 2);
		res[1] = '\0';
		res[0] = '0';
		x->gotov = ft_strjoin(res, x->gotov);
	}
	else if (x->cf == 'x' || x->cf == 'X')
	{
		res = (char *)malloc(sizeof(char *) * 3);
		res[2] = '\0';
		res[1] = x->cf;
		res[0] = '0';
		x->gotov = ft_strjoin(res, x->gotov);
	}
	return (1);
}

int		ft_flags(t_tab *x)
{
	if ((x->cf == 'd' || x->cf == 'i' || x->cf == 'f') && x->gotov[0] != '-')
		show_sign(x);
	else if (x-> cf == 'o' || x-> cf == 'x' || x-> cf == 'X')
		if (x->ar != 0)
		{
			if (use_octo(x) == 1)
				return 1;
		}
	return 0;
}
