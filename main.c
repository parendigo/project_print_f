/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:48:57 by mlarraq           #+#    #+#             */
/*   Updated: 2019/12/10 18:02:34 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int		main()
{ 
	char *tab = "WABADABA";
	int i = 9934858;
	char c = 'A';
	printf("bla bla %  s yo yo %s\n", tab, tab);
	ft_printf("bla bla %  s yo yo %s", tab, tab);
	return 0;
}
