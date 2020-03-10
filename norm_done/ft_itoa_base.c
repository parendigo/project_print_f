/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:26:00 by mlarraq           #+#    #+#             */
/*   Updated: 2020/03/08 14:33:14 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_itoa_b(long int value, int base, t_tab *x, char f)
{
	char	*ch;
	int		len;
	int		k;
	int		check;

	x->value2 = value;
	x->value1 = value;
	x->ar = value;
	k = sub_zero(x, value, f, base);
	len = ft_nbrlen(x, value, base);
	len += k;
	if (!(ch = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	ch[len] = '\0';
	if (k > 0 && base == 10)
		ch[0] = '-';
	len--;
	while ((len) >= k)
	{
		check = x->cf == 'X' ? 55 : 87;
		ch[len] = x->value1 % base + ((x->value1 % base > 9) ? check : '0');
		x->value1 = x->value1 / base;
		len--;
	}
	return (ch);
}

int		sub_zero(t_tab *x, long int value, char f, int base)
{
	int k;

	k = 0;
	if (value < 0)
	{
		if (base == 10 && x->cf != 'u')
			k++;
		x->value1 *= -1;
		if (base == 16 || base == 8 || x->cf == 'u')
		{
			if (f == 'n')
				x->value2 = 4294967295 + value + 1;
			if (f == 's')
				x->value2 = 65535 + value + 1;
			if (f == 'h')
				x->value2 = 255 + value + 1;
			x->value1 = x->value2;
		}
		return (k);
	}
	return (k);
}

int		ft_nbrlen(t_tab *x, int long value, int base)
{
	int	len;

	len = 1;
	if (x->cf == 'i' || x->cf == 'd')
		while (value / base)
		{
			value = value / base;
			len++;
		}
	else
		while (x->value2 / base)
		{
			x->value2 = x->value2 / base;
			len++;
		}
	return (len);
}
