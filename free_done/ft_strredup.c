/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 02:08:58 by mlarraq           #+#    #+#             */
/*   Updated: 2020/03/04 16:47:01 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strredup(char *str)
{
	size_t	a;
	size_t	len;
	char	*src;

	len = 0;
	a = 0;
	if (!str)
		return (NULL);
	while (str[len])
		len++;
	if (!(src = (char*)malloc(sizeof(*src) * (len + 1))))
		return (NULL);
	while (a < len)
	{
		src[a] = str[a];
		a++;
	}
	free(str);
	src[a] = '\0';
	return (src);
}
