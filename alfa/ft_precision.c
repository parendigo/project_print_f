/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:14:43 by mlarraq           #+#    #+#             */
/*   Updated: 2020/01/19 18:28:13 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memal(size_t size, int c)
{
	char	*mem;

	if (!(mem = (char *)malloc(size + 1)))
		return (NULL);
	ft_memset(mem, c, size);
	mem[size] = '\0';
	return (mem);
}

int		find_dot(char *str)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == '.' && NUMBER(str[i + 1]))
			n = i;
		i++;
	}
	return (n == 0 ? 0 : n + 1);
}

int		ft_precision(t_tab *x)
{
	int		dot;
	int		prec;
	int		lenprec;
	char	*res;

	if ((dot = find_dot(x->form)) == 0)
		return (0);
	prec = ft_atoi(x->form + dot);
	if (SYMBOLS1(x->form[x->lenform - 1]))
		if ((lenprec = prec - ft_strlen(x->gotov)) > 0)
		{
			res = ft_memal(lenprec, '0');
			res = ft_strjoin(res, x->gotov);
			x->gotov = ft_strdup(res);
		}
	if (SYMBOLS3(x->form[x->lenform - 1]))
		if (ft_strlen(x->gotov) > prec)
		{
			res = ft_strsub(x->gotov, 0, prec);
			x->gotov = ft_strdup(res);
		}
	return (1);
}
