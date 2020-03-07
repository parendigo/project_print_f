/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stolbik.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:36:06 by mmahasim          #+#    #+#             */
/*   Updated: 2020/02/26 13:41:53 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_stolbik(long double nbr, const long double d, t_tab *x)
{
	char *tmp;

	x->count = 0;
	x->prom = d;
	x->delimoe = nbr;
	x->j = 0;
	x->vo = 0;
	x->str_ostatok = ft_strnew(100);
	while (x->count <= 100)
	{
		x->flag = 0;
		if (x->prom > x->delimoe && x->j <= 100)
			add_zero(x);
		if (x->prom <= x->delimoe)
			add_numbers(d, x);
		if (x->delimoe == 0)
		{
			if (x->j == 1)
				x->str_ostatok[x->j] = '.';
			tmp = ft_strnew(100);
			x->str_ostatok = ft_strrejoin(x->str_ostatok,
					ft_memset(tmp, '0', 100), 1);
			ft_strdel(&tmp);
			break ;
		}
		x->count++;
	}
	if (x->delimoe != 0)
		x->str_ostatok[x->j] = '\0';
}

void	add_zero(t_tab *x)
{
	while (x->prom > x->delimoe && x->j <= 100)
	{
		if (x->j == 1)
		{
			x->str_ostatok[x->j] = '.';
			x->j++;
			if (x->delimoe == 0)
				break ;
			while (x->prom > x->delimoe * 10 && x->j <= 100)
			{
				x->str_ostatok[x->j] = '0';
				x->j++;
				x->delimoe *= 10;
			}
		}
		else if (x->flag == 0 && x->j != 0)
			x->flag++;
		else
		{
			x->str_ostatok[x->j] = '0';
			x->j++;
		}
		if (x->j != 1)
			x->delimoe *= 10;
	}
}

void	add_numbers(const long double d, t_tab *x)
{
	while (x->prom <= x->delimoe)
	{
		x->vo++;
		x->prom = x->prom + d;
	}
	if (x->prom > x->delimoe && x->j <= 100)
	{
		if (x->j == 1)
		{
			x->str_ostatok[x->j] = '.';
			x->j++;
		}
		x->str_ostatok[x->j] = x->vo + '0';
		x->j++;
		x->prom -= d;
		x->delimoe -= x->prom;
		x->prom = d;
		x->vo = 0;
	}
}
