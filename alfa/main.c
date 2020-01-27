/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:48:57 by mlarraq           #+#    #+#             */
/*   Updated: 2020/01/27 15:37:10 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int		main()
{ 
	char *tab = "abcde";
	unsigned long long int i = -1309458029485;
	char c = 'A';
	   printf("s = %s\nd = %d\ni = %i\nx = %x\nX = %X\nu = %u\no = %o\np = %020p\n\n",
	   		tab, i, i, i, i, i, i, &i);
	ft_printf("s = %s\nd = %d\ni = %i\nx = %x\nX = %X\nu = %u\no = %o\np = %020p\n\n",
			tab, i, i, i, i, i, i, &i);
	   printf("   printf: % -+ko-+%s\n", tab);
	ft_printf("ft_printf: % -+ko-+%s\n", tab);
	   printf("   printf: % -+%s\n", tab);
	ft_printf("ft_printf: % -+%s\n", tab);
	   printf("   printf: % -+ko-+%%s\n", tab);
	ft_printf("ft_printf: % -+ko-+%%s\n", tab);
	   printf("   printf: % -+%%s\n", tab);
	ft_printf("ft_printf: % -+%%s\n", tab);
	return 0;
}
