/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_razrez.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:20:54 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/25 17:48:18 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_razrez(char *s1, char *s2, int	a, int b, int greh)
{
	char	*src;
	int		len;

	len = ft_strlen(s2);
	src = ft_strsub(s1, 0, a + greh);
	src = ft_strjoin(src, s2);
	b = b + 0;
//	src = ft_strjoin(src, s1 + b);
	return (src);
}
