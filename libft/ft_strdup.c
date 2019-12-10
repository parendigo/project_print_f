/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 02:08:58 by mlarraq           #+#    #+#             */
/*   Updated: 2019/04/23 07:26:19 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	a;
	size_t	len;
	char	*src;

	len = 0;
	a = 0;
	while (str[len])
		len++;
	if (!(src = (char*)malloc(sizeof(*src) * (len + 1))))
		return (NULL);
	while (a < len)
	{
		src[a] = str[a];
		a++;
	}
	src[a] = '\0';
	return (src);
}
