/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_exep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:42:36 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/26 15:52:51 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		exception(t_tab *x, int co)
{
	int		wdt;
	int		nu;

	if ((nu = find_width(x->allforms[co])) == 0)
	{
		x->lengovna++;
		ft_putchar(x->allargs[co][0]);
		return (1);
	}
	wdt = ft_atoi(x->allforms[co] + nu);
	if (wdt > (int)ft_strlen(x->allargs[co]))
	{
		if (find_minus(x->allforms[co]) == 1)
			print_exep(x, wdt, 1, co);
		else
			print_exep(x, wdt, 2, co);
		return (1);
	}
	return (0);
}
