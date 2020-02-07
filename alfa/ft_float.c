/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:13:46 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/01 15:58:22 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

union						s_vizov
{
	float					fl;
	char					ch[4];
	unsigned long long int	m:23;
}							t_vizov;

union					s_float
{
	unsigned long int	m_vot;
	float				f_vot;
}						t_float;

char	*mantisa(t_tab *x, union s_vizov wrd)
{
	char	oct;
	char	*str;
	int		j;
	int		k;
	int		z;
	int		b;

	str = (char *)malloc(sizeof(char *) * 33);
	str[32] = '\0';
	k = 0;
	b = 3;
	while (k != 32)
	{
		z = 128;
		j = 0;
		oct = wrd.ch[b--];
		while (z > 0)
		{
			if (oct & z)
			{
				str[k + j] = '1';
				j++;
			}
			else
			{
				str[k + j] = '0';
				j++;
			}
			z >>=1;
		}
		k = k + 8;
	}
	return (str);
}

void	ft_float(double flo, t_tab *x)
{
	int		j;
	char	*str;
	union s_vizov wrd;
	union s_float w;
	unsigned int e;

	e = flo;
	j = 1;
	while (j < e)
		j = j * 2;
	j = j / 2;
	wrd.fl = flo;
	ft_putchar('\n');
	str = mantisa(x, wrd);
	ft_putendl(str);
	printf("%llu\n", wrd.m);
	x->gotov = ft_strdup("\nWassap?:)");
}
