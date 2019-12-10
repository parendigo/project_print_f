/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 07:24:53 by mlarraq           #+#    #+#             */
/*   Updated: 2019/06/14 17:40:29 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	char	*src;

	a = 0;
	if (!s || len + 1 < len)
		return (NULL);
	if (!(src = (char*)malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	while (a < len && s[a + start] != '\0')
	{
		src[a] = s[a + start];
		a++;
	}
	src[a] = '\0';
	return (src);
}
