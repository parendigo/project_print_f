/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:43:12 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/19 16:29:11 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"
# define SYMBOLS1(a) a == 'd' || a == 'i' || a == 'o' || a == 'u' || a == 'x' || a == 'X'
# define SYMBOLS2(a) a == 'f' || a == '%'
# define SYMBOLS3(a) a == 's' || a == 'c' || a == 'p'
# define FLAGS(a) a ==  '-' || a == '+' || a == ' ' || a == '#' || a == '0' || a == '.'
# define SPECS(a) a == 'l' || a == 'h' || a == 'L'
# define NUMBER(a) (a >= '0' && a <= '9')
# define NOTNB(a) (a != '0' && a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6' && a != '7' && a != '8' && a != '9')
# define NU19(a) (a >= '1' && a <= '9')
# define NUNE19(a) (a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6' && a != '7' && a != '8' && a != '9')


typedef struct	s_tab
{
	int						i;
	char					*str;
	char					*arg;
	int						ar;
	char					*gotov;
	char					*result;
	char					*form;
	int						lenform;
	int						cf;
	unsigned long long int	value1;
	unsigned long long int 	value2;
	char                    *binary_m;
	char                    *binary_ost;
	double                  test;
	char                    *str_ostatok;
	int 					tochnost;
	int 					chast_x;

}				t_tab;

typedef union s_double
{
	double d;
	struct
	{
		unsigned long long int      m:52;
		unsigned int                e:11;
		unsigned int                z:1;
	}       di;
}               t_double;

int     		ft_printf(const char *format, ...);
void			ft_gotov(va_list factor, t_tab *x);
int				ft_precision(t_tab *x);
int				ft_width(t_tab *x);
void			*ft_memal(size_t size, int c);
int				ft_flags(t_tab *x);
int				find_minus(char *str);
int				find_zero(char *str);
int				find_plus(char *str);
int				find_space(char *str);
int				find_octotorp(char *str);
void			ft_print_bits(unsigned char octet);
int				find_dot(char *str);

void			ft_str_number(va_list factor, t_tab *x);
int				form_hh(char *form);
int 			form_ll(char *form);
char			*ft_itoa_base(long int value, int base, t_tab *x, char f);
int 			ft_sub_zero(t_tab *x, long int value, char f, int base);
int 			ft_nbrlen(t_tab *x, int long value, int base);
void                            ft_float(va_list factor, t_tab *x);
double                          atoi_base(char *str, int base);
unsigned long long int          ft_ostatok(t_tab *x);
char                            *ft_celoe(t_double *d1, t_tab *x);
int								ft_tochnost(char *str);
long double						find_L(char *form, va_list factor);
char							*ft_okruglenie(t_tab *x, t_double *d);
char							*ft_posle_tochki(t_tab *x, t_double *d1);

#endif
