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

void	what_to_free(char **s1, char **s2, int how)
{
	if (how == 1)
		free(*s1);
	if (how == 2)
		free(*s2);
}

char	*ft_strrejoin(char *s1, char *s2, int how)
{
	char	*src;
	size_t	a;
	size_t	b;
	size_t	len1;
	size_t	len2;

	a = 0;
	b = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	if (!(src = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	while (a < len1)
	{
		src[a] = s1[a];
		a++;
	}
	while (a < len1 + len2)
		src[a++] = s2[b++];
	src[a] = '\0';
	what_to_free(&s1, &s2, how);
	return (src);
}
