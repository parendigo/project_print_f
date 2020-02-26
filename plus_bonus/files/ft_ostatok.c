/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ostatok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 13:04:54 by mmahasim          #+#    #+#             */
/*   Updated: 2020/02/01 13:04:57 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long long int ft_ostatok(t_tab *x)
{
	unsigned long long int	i;
	long double  ch1;
	unsigned long long int 	exp[52];
	unsigned long long int	j;
	unsigned long long int	stepen_dva;

	i = 0;
	j = 0;
	stepen_dva = 2;
	ch1 = 0.0;
	x->cf = 'd';
	while (x->binary_ost[i])
	{
		if (x->binary_ost[i] == '1')
		{
			exp[j] = (i + 1);
			j++;
		}
		i++;
	}
	i = 0;

	while (i < j)
	{
		while (exp[i] > 1)
		{
			stepen_dva *= 2;
			exp[i]--;
		}
		exp[i] = stepen_dva;
		stepen_dva = 2;
		i++;
	}
	i = 0;

	while (i < j)
	{
		ch1 += 1000000000000000000.0/exp[i];
		i++;
	}
	return (ch1);

}