/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:41:05 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/05 19:42:59 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		find_minus(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int		find_zero(char *str)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (str[i] == '0' && NUNE19(str[i - 1]) && str[i - 1] != '.')
			return (1);
		i++;
	}
	return (0);
}

int		find_plus(char *str)
{
	int		i;

	i = 1;
	while (str[i])
		if (str[i++] == '+')
			return (1);
	return (0);
}

int		find_space(char *str)
{
	int		i;

	i = 1;
	while (str[i])
		if (str[i++] == ' ')
			return (1);
	return (0);
}

int		find_octotorp(char *str)
{
	int		i;

	i = 1;
	while (str[i])
		if (str[i++] == '#')
			return (1);
	return (0);
}
