/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:48:57 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/05 18:23:37 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int		main()
{ 
	char *tab = "abcde";
	unsigned long long int i = -1309458029485;
	char c = 'A';
	float f = 56.3280;
/*	   printf("s = %s\nd = %d\ni = %i\nx = %x\nX = %X\nu = %u\no = %o\nf = %f\np = %020p\n\n",
	   		tab, i, i, i, i, i, i, f, &i);
	ft_printf("s = %s\nd = %d\ni = %i\nx = %x\nX = %X\nu = %u\no = %o\nf = %f\np = %020p\n\n",
			tab, i, i, i, i, i, i, f, &i);
	   printf("   printf: % -+ko-+%s\n", tab);
	ft_printf("ft_printf: % -+ko-+%s\n", tab);
	   printf("   printf: % -+%s\n", tab);
	ft_printf("ft_printf: % -+%s\n", tab);
	   printf("   printf: % -+ko-+%%s\n", tab);
	ft_printf("ft_printf: % -+ko-+%%s\n", tab);
	   printf("   printf: % -+%%s\n", tab);
	ft_printf("ft_printf: % -+%%s\n", tab);
*/	return 0;
	   printf("   %%    \n");
	ft_printf("   %%    \n");
}
