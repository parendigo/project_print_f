/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:41:33 by mlarraq           #+#    #+#             */
/*   Updated: 2019/12/10 19:22:39 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

#define SYMBOLS1 str[i] == 'c' || str[i] == 'C' || str[i] == 'd' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X' || str[i] == 'e'
#define SYMBOLS2 str[i] == 'E' || str[i] == 'f' || str[i] == 'F' || str[i] == 'g' || str[i] == 'G' || str[i] == 'a' || str[i] == 'A' || str[i] == 'n' || str[i] == 'p'
#define SYMBOLS3 str[i] == 's' || str[i] == 'S' || str[i] == 'Z'
#define FLAGS str[i] ==  '-' || str[i] == '+' || str[i] == ' ' || str[i] == '#' || str[i] == '0' || str[i] == '.' 
#define SPECS str[i] == 'l' || str[i] == 'h'
#define NUMBER (str[i] >= 0 && str[i] <= 9)

int		return_arg(char *str, char *form)
{
	ft_putstr(str);
	return (0);
}

char	*get_form(const char **format, char *str, int i)
{
	char	*form;

	form = ft_strsub(str, 0, i + 1);
	*format += i + 1;
	return (form);
}

char	*find_operator(const char **format)
{
	char	*str;
	char	*form;
	int		i;

	i = 1;
	str = ft_strdup(*format);
	while (str[i])
	{
		if (FLAGS || SPECS || NUMBER)
			i = i;
		else if  (SYMBOLS1 || SYMBOLS2 || SYMBOLS3)
		{
			form = ft_strsub(str, 0, i + 1);
			*format += i + 1;
			return (form);
		}
		else
			break;
		i++;
	}
	return NULL;
}
int		ft_printf(const char *format, ...)
{
	int		i;
	char	*str;
	char	*form;
	va_list factor;

	i = 0;
	va_start(factor, format);
	while (*format)
	{
		if (*format == '%')
		{
			if ((form = find_operator(&format)) != NULL)
				return_arg(str = va_arg(factor, char *), form);
		}
		ft_putchar(*format++);
	}
	va_end(factor);
	return 0;
}

