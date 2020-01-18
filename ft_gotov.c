/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gotov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:38:52 by mlarraq           #+#    #+#             */
/*   Updated: 2020/01/18 17:53:13 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_gotov(va_list factor, t_tab *x)
{
	int		len;

	len = ft_strlen(x->form);
	if (SYMBOLS1(x->form[len - 1]))
	{
		x->ar = va_arg(factor, int);
		x->gotov = ft_itoa(x->ar);
	}
	else if (x->form[len -1] == 's' || x->form[len -1] == 'c' || x->form[len -1] == 'p')
	{
		x->arg = va_arg(factor, char *);
		x->gotov = ft_strdup(x->arg);
	}
	return 0;
}
