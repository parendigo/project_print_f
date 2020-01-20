/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:48:57 by mlarraq           #+#    #+#             */
/*   Updated: 2020/01/20 16:23:16 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int		main()
{ 
	char *tab = "abcde";
	unsigned long long int i = -1309458029485;
	char c = 'A';
	   printf("s = %s\nd = %d\ni = %i\nx = %x\nX = %X\nu = %u\no = %o\np = %p\n\n",
	   		tab, i, i, i, i, i, i, &i);
	ft_printf("s = %s\nd = %d\ni = %i\nx = %x\nX = %X\nu = %u\no = %o\np = %p\n",
			tab, i, i, i, i, i, i, &i);
	return 0;
}
