/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:54:50 by mmahasim          #+#    #+#             */
/*   Updated: 2020/02/25 13:55:05 by mmahasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_exp_forma(t_tab *x)
{
	int i;
	char *c;
	char *bt;

	i = 0;
	c = ft_strnew(1);
	while (x->gotov_e[i] != '.')
	{
		i++;
	}
	if (i == 1)
	{
		i++;
		while (x->gotov_e[i] == '0')
			i++;
		if (i - 1 < 10)
			x->exp_e = ft_strjoin("e-0", ft_itoa(i - 1));
		else
			x->exp_e = ft_strjoin("e-", ft_itoa(i - 1));
		c[0] = x->gotov_e[i];
		x->gotov_e = ft_strjoin(c, ft_strjoin(".", x->gotov_e + i + 1));
	}
	else
	{
		if (i - 1 < 10)
			x->exp_e = ft_strjoin("e+0", ft_itoa(i - 1));
		else
			x->exp_e = ft_strjoin("e+", ft_itoa(i - 1));
		bt = ft_strjoin(ft_strsub(x->gotov_e, 0, i), ft_strdup(x->gotov_e + i + 1));
		while (i != 0)
			i--;
		c[0] = x->gotov_e[i];
		x->gotov_e = ft_strjoin(c, ft_strjoin(".", bt + i + 1));
	}
	//printf("%s\n", x->gotov_e);
	return (x->gotov_e);
}

char	*ft_e_or_f(t_tab *x)
{
	int len;

	if (((x->tochnost + x->j) > ft_atoi(x->exp_e + 2) && x->exp_e[1] == '+') ||
	(x->exp_e[1] == '-' && x->celoe[0] > '0') ||  (ft_atoi(x->exp_e + 2) < 5 && x->celoe[0] == '0'))
	{
		if (find_octotorp(x->allforms[x->co]) == 0)
		{
			len = ft_strlen(x->gotov_f) - 1;
			while (x->gotov_f[len] == '0' && len >= 0)
			{
				x->gotov_f[len] = '\0';
				len--;
			}
			if (x->gotov_f[len] == '.')
				x->gotov_f[len] = '\0';
			if (len < 0)
				return (x->celoe);
			return (x->gotov_f);
		}
		return (x->gotov_f);
	}
	if (x->tochnost + x->j <= ft_atoi(x->exp_e + 2) || (ft_atoi(x->exp_e + 2) >= 5 && x->celoe[0] == '0'))
	{
		if (find_octotorp(x->allforms[x->co]) != 0)
			return (x->gotov_e);
		else
		{
			len = ft_strlen(x->gotov_e) - 5;
			if (x->gotov_e[len] != '0')
				return (x->gotov_e);
			while (x->gotov_e[len] == '0')
			{
				x->gotov_e[len] = '\0';
				len--;
			}
			if (x->gotov_e[len] == '.')
				return (ft_strjoin(x->c_and_exp, x->exp_e));
			else
				return (ft_strjoin(x->gotov_e, x->exp_e));
		}
	}
//	printf("%d\n", x->tochnost);
//	printf("%s", x->exp_e);
	return (NULL);
}

//void	ft_invisible(t_tab *x)
//{
//	int i = 0;
//	char *tmp;
//
//	tmp = ft_strnew(0);
//	while (x->gotov[i]) {
//		if (x->gotov[i] == '\t')
//			x->gotov = ft_strdup("\\t");
//		if (x->gotov[i] == '\n')
//			x->gotov = ft_strdup("\\n");
//		if (x->gotov[i] == '\v')
//			x->gotov = ft_strdup("\\v");
//		if (x->gotov[i] == '\f')
//			x->gotov = ft_strdup("\\f");
//		if (x->gotov[i] == '\r')
//			x->gotov = ft_strdup("\\r");
//		if (x->gotov[i] == ' ')
//			x->gotov = ft_strdup(" ");
//		if (x->gotov[i] == '\0')
//			tmp = ft_strjoin(tmp, "\\0");
//		else if (x->gotov[i] == 1)
//			ft_putstr("^A");
//		else
//			ft_putchar(x->gotov[i]);
//		i++;
//	}
//}