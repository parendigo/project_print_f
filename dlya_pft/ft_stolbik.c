/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stolbik.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:36:06 by mmahasim          #+#    #+#             */
/*   Updated: 2020/02/22 15:36:09 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_stolbik(long double nbr, long double d)
{
	int i;
	int vo;
	char *str;
	long long prom;
	int j;
	int flag;
	int zero;
	int desatki;

	i = 0;
	j = 0;
	vo = 0;
	flag = 0;
	zero = 0;
	prom = d;
	str = (char *) malloc(sizeof(char) * 60);
	desatki = d/nbr;
//	if(desatki >= 10)
//	{
//		while ()
//
//	}
	while (i <= 50)
	{
		while (prom > nbr && j <= 50)
		{
			if (j == 1)
			{
				str[j] = '.';
				j++;
			}
			if (prom > (nbr*10))
			{
				str[j] = '0';
				j++;
			}
			else if (flag == 0 && j != 0)
				flag++;
			else
			{
				str[j] = '0';
				j++;
			}
			zero++;
			nbr *= 10;
		}
		flag = 0;
		while (prom <= nbr)
		{
			vo++;
			prom = prom + d;
		}
		if (prom > nbr && j <= 50)
		{
			if (j == 1)
			{
				str[j] = '.';
				j++;
			}
			str[j] = vo + '0';
			j++;
			prom -= d;
			nbr -= prom;
			prom = d;
			vo = 0;
		}
		if (nbr == 0)
		{
			str[j] = '\0';
			ft_strjoin(str, ft_memset(str + j, '0', 30 - j));
			break ;
		}
		i++;
	}
	if (nbr != 0)
		str[j] = '\0';
	return (str);
}