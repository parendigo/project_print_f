/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 07:41:34 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/27 15:43:21 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strrejoin(char *s1, char *s2, int how)
{
	char	*src;
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(src = (char*)malloc(sizeof(char)
					* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (a < ft_strlen(s1))
	{
		src[a] = s1[a];
		a++;
	}
	while (a < ft_strlen(s1) + ft_strlen(s2))
		src[a++] = s2[b++];
	src[a] = '\0';
	if (how == 1)
		ft_strdel(&s1);
	if (how == 2)
		ft_strdel(&s2);
	return (src);
}
