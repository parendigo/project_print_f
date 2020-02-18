/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 06:11:46 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/01 16:30:13 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strnew(size_t size)
{
	char	*src;

	if (size + 1 < size)
		return (NULL);
	if (!(src = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(src, '\0', size + 1);
	return (src);
}
