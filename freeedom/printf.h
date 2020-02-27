/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:43:12 by mlarraq           #+#    #+#             */
/*   Updated: 2020/02/27 15:51:47 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct					s_tab
{
	int							i;
	char						*str;
	int							ar;
	char						*gotov;
	char						*result;
	char						*allargs[256];
	char						*form;
	char						*allforms[256];
	int							dollarcount[256];
	int							lenform;
	int							cf;
	unsigned long long int		value1;
	unsigned long long int		value2;
	char						*str_ostatok;
	int							tochnost;
	int							chast_x;
	int							nk;
	long double					prom;
	int							j;
	int							flag;
	long double					delimoe;
	int							vo;
	int							count;
	char						*gotov_e;
	char						*exp_e;
	char 						*celoe;
	char 						*gotov_f;
	char 						*c_and_exp;
	int 						e;
	char 						*okrug_ostatok;
}								t_tab;

typedef union					s_double
{
	double						d;
	struct
	{
		unsigned long long int	m:52;
		unsigned int			e:11;
		unsigned int			z:1;
	}							di;
}								t_double;
int								ft_printf(const char *format, ...);
void							ft_gotov(va_list factor, t_tab *x);
int								ft_precision(t_tab *x);
int								ft_width(t_tab *x);
void							*ft_memal(size_t size, int c);
int								ft_flags(t_tab *x);
int								find_minus(char *str);
int								find_zero(char *str);
int								find_plus(char *str);
int								find_space(char *str);
int								find_octotorp(char *str);
int								find_width(char *str);
int								find_dot(char *str);
int								one_nine(char a);
int								nu_ne_one_nine(char a);
int								ne_ze_ni(char a);
int								ze_ni(char a);
int								lf_diouxx(char a);
void							ft_str_number(va_list factor, t_tab *x);
int								form_hh(char *form);
int								form_ll(char *form);
char							*ft_itoa_b(long int v, int b, t_tab *x, char f);
int								sub_zero(t_tab *x, long int v, char f, int b);
int								ft_nbrlen(t_tab *x, int long value, int base);
void							ft_float(va_list factor, t_tab *x);
char							*ft_celoe(t_double *d1, t_tab *x);
int								ft_tochnost(char *str);
long double						find_big_l(char *form, va_list factor);
char							*ft_okruglenie(t_tab *x);
void							ft_posle_tochki(t_double *d1, t_tab *x);
void							ft_stolbik(long double nbr, const long double d, t_tab *x);
void							ft_save(t_tab *x, int *count);
void							save_result(t_tab *x, int *count);
int								exception(t_tab *x, int co);
void							print_exep(t_tab *x, int wdt, int how, int co);
void							add_zero(t_tab *x);
void							add_numbers(const long double d, t_tab *x);
int								compare_fsn(char c, char c2);
int								compare_symbols(char c);
char							*ft_strrejoin(char *s1, char *s2, int how);
char							*ft_strresub(char *s, int start, size_t len, int how);
char 							*ft_exp_forma(t_tab *x);
char							*ft_e_or_f(t_tab *x);
int								ft_tochnost_g(t_tab *x);

#endif
