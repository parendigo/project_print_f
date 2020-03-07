/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 21:48:28 by mlarraq           #+#    #+#             */
/*   Updated: 2020/03/03 13:53:38 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	char	*dest;

	if (n == 0)
		return (destination);
	dest = (char *)destination;
	while (n--)
		*dest++ = (char)c;
	return (destination);
}
