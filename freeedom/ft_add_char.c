/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:29:52 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/25 17:37:15 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_add_char(char *s, char c)
{
	char	*src;
	int		a;

	a = 0;
	if (!(src = (char*)malloc(sizeof(char) * (ft_strlen(s) + 2))))
		return (NULL);
	while (a < (int)ft_strlen(s))
	{
		src[a] = s[a];
		a++;
	}
	src[a++] = c;
	src[a] = '\0';
	return (src);
}
