/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_celoe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:49:51 by mmahasim          #+#    #+#             */
/*   Updated: 2020/02/08 15:49:53 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *ft_celoe(t_double *d1, t_tab *x)
{
	double clone_d;
	int len_nbr;
	char *str;
	double nulls;

	str = ft_strnew(1);
	clone_d = d1->d;
	len_nbr = 0;
	nulls = 1.0;
	while (clone_d > 10)
	{
		clone_d /= 10;
		nulls *= 10;
		len_nbr++;
	}
	while (nulls > 0.1)
	{
		str = ft_strjoin(str, ft_itoa(clone_d));
		x->chast_x = clone_d;
		clone_d = (double)x->chast_x * nulls;
		d1->d -= clone_d;
		clone_d = d1->d*10/nulls;
		nulls /= 10;
	}
	return (str);
}