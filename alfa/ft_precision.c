/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:14:43 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/19 15:32:09 by mlarraq          ###   ########.fr       */
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
		if (str[i] == '.')
			n = i;
		i++;
	}
	return (n == 0 ? 0 : n + 1);
}

void	swaperino(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	zero_prec(t_tab *x, int prec)
{
	char	*res;
	int		lenprec;

	if (x->gotov[0] == '-' || x->gotov[0] == '+' || x->gotov[0] == ' ')
	{
		if ((lenprec = prec - (int)ft_strlen(x->gotov) + 1) > 0)
		{
			res = ft_memal(lenprec, '0');
			res = ft_strjoin(res, x->gotov);
			swaperino(&res[0], &res[lenprec]);
			x->gotov = ft_strdup(res);
		}
	}
	else
		if ((lenprec = prec - (int)ft_strlen(x->gotov)) > 0)
		{
			if (find_octotorp(x->form) == 1 && x->cf == 'o' && x->ar != 0)
				res = ft_memal(lenprec - 1, '0');
			else
				res = ft_memal(lenprec, '0');
			res = ft_strjoin(res, x->gotov);
			x->gotov = ft_strdup(res);
		}
}

int		ft_precision(t_tab *x)
{
	int		dot;
	int		prec;
	char	*res;

	if ((dot = find_dot(x->form)) == 0)
		return (0);
	/*Исправление нуля при точности ноль*/
	if (((prec = ft_atoi(x->form + dot)) == 0) && x->ar == 0)
		if(SYMBOLS1(x->cf))
		{
			if (x->cf == 'o' && find_octotorp(x->form) == 1)
				zero_prec(x, prec);
			else
				x->gotov = ft_strnew(1);
			return 0;
		}
	if (SYMBOLS1(x->form[x->lenform - 1]))
		zero_prec(x, prec);
	if (SYMBOLS3(x->form[x->lenform - 1]))
		if ((int)ft_strlen(x->gotov) > prec)
		{
			res = ft_strsub(x->gotov, 0, prec);
			x->gotov = ft_strdup(res);
		}
	return (1);
}
