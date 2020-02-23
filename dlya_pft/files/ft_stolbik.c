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

	i = 0;
	j = 0;
	vo = 0;
	flag = 0;
	zero = 0;
	prom = d;
	str = (char *) malloc(sizeof(char) * 20);
	while (1)
	{
		while (prom > nbr)
		{
			if (j == 0)
				zero++;
			if (j == 1)
			{
				str[j] = '.';
				j++;
				if (zero != 0)
				{
					str[j] = '0';
					j++;
					nbr /= 10;
				}
			}
			else if (flag == 0 && j != 0)
				flag++;
			else
			{
				str[j] = '0';
				j++;
			}
			nbr *= 10;
		}
		flag = 0;
		while (prom <= nbr)
		{
			vo++;
			prom = prom + d;
		}
		if (prom > nbr)
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
			break ;
	}
	str[j] = '\0';
	printf("%s\n", str);
	printf("%lu\n", ft_strlen(str));
	return (str);
}