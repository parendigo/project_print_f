/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 23:43:21 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/20 17:16:57 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_atoi(const char *str)
{
	int				i;
	unsigned long	b;
	int				sign;

	b = 0;
	sign = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if (b > 9223372036854775807 && sign == 1)
			return (0);
		else if (b > 9223372036854775807 && sign == 0)
			return (-1);
		b = b * 10 + (unsigned long)(str[i++] - '0');
	}
	if (sign == 1)
		return (-b);
	return (b);
}
