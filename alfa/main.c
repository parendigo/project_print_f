/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:48:57 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/19 16:29:09 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"
int		main()
{ 
	char *tab = "abcde";
	char *test;
	int	ti = 1;
	unsigned long long int i = -1309458029485;
	char c = 'A';
	float f = 132.516;
	test = ft_strdup("yolo");
/*	   printf("s = %s\nd = %d\ni = %i\nx = %x\nX = %X\nu = %u\no = %o\nf = %f\np = %020p\n\n", tab, i, i, i, i, i, i, f, &i);
	ft_printf("s = %s\nd = %d\ni = %i\nx = %x\nX = %X\nu = %u\no = %o\nf = %f\np = %020p\n\n", tab, i, i, i, i, i, i, f, &i);
*/	   printf("   printf = % .16f\n", 0.00000000);
	ft_printf("ft_printf = % .16f\n", 0.00000000); //mantisa = 1.5643615625
/*	   printf("   printf: % -+ko-+%s\n", tab);
	ft_printf("ft_printf: % -+ko-+%s\n", tab);
	   printf("   printf: % -+%s\n", tab);
	ft_printf("ft_printf: % -+%s\n", tab);
	   printf("   printf: % -+ko-+%%s\n", tab);
	ft_printf("ft_printf: % -+ko-+%%s\n", tab);
	   printf("   printf: % -+%%s\n", tab);
	ft_printf("ft_printf: % -+%%s\n", tab);
*/	return 0;
}
