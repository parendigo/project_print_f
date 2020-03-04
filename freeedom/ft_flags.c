/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:56:31 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/27 16:47:46 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		show_sign(t_tab *x)
{
	char	*tmp;

	if (find_plus(x->allforms[x->co]) == 1 && x->allargs[x->co][0] != '-')
	{
		tmp = ft_strjoin("+", x->allargs[x->co]);
		x->allargs[x->co] = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else if (find_space(x->allforms[x->co]) == 1)
	{
		tmp = ft_strjoin(" ", x->allargs[x->co]);
		x->allargs[x->co] = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	return (0);
}

int		use_octo(t_tab *x)
{
	char	*res;

	if (find_octotorp(x->allforms[x->co]) == 0 || x->ar == 0)
		return (0);
	if (x->cf == 'o')
		x->allargs[x->co] = ft_strrejoin("0", x->allargs[x->co], 2);
	else if (x->cf == 'x' || x->cf == 'X')
	{
		res = (char *)malloc(sizeof(char *) * 3);
		res[2] = '\0';
		res[1] = x->cf;
		res[0] = '0';
		x->allargs[x->co] = ft_strrejoin(res, x->allargs[x->co], 2);
		ft_strdel(&res);
	}
	return (1);
}

int		ft_flags(t_tab *x)
{
	if ((x->cf == 'd' || x->cf == 'i' || x->cf == 'f') && x->allargs[x->co][0] != '-')
		show_sign(x);
	else if (x->cf == 'o' || x->cf == 'x' || x->cf == 'X')
		if (x->ar != 0)
		{
			if (use_octo(x) == 1)
				return (1);
		}
	return (0);
}
