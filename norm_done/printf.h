/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlarraq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:43:12 by mlarraq           #+#    #+#             */
/*   Updated: 2020/03/08 16:34:33 by mlarraq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct					s_tab
{
	int							lengovna;
	int							i;
	int							co;
	char						*str;
	int							ar;
	char						*result;
	char						*allargs[256];
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
	char						*celoe;
	char						*gotov_f;
	char						*c_and_exp;
	int							e;
	char						*okrug_ostatok;
	int							i1;
	char						*c;
}								t_tab;

typedef union
{
	double						d;
	struct
	{
		unsigned long long int	m:52;
		unsigned long long int	e:11;
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
void							ft_stolbik(long double nbr, const long double d,
		t_tab *x);
void							save_result(t_tab *x);
int								exception(t_tab *x, int co);
void							print_exep(t_tab *x, int wdt, int how, int co);
void							add_zero(t_tab *x);
void							add_numbers(const long double d, t_tab *x);
int								compare_fsn(char c, char c2);
int								compare_symbols(char c);
char							*ft_strrejoin(char *s1, char *s2, int how);
void							ft_exp_forma(t_tab *x);
void							ft_e_or_f(t_tab *x);
int								ft_tochnost_g(t_tab *x);
char							*ft_strdup(const char *str);
void							podrezal_g_e_f(t_tab *x);
void							podrezal_esche_raz(t_tab *x);
void							double_sub_zero_exp(t_tab *x,
		long double stepen_dva, int exp, t_double *d1);
void							okruglenie_sokr(t_tab *x, int len);
void							ukrotil_tochku_g(t_tab *x);
int								check_five(t_tab *x, int len);
void							okruglenie_sokr_one(t_tab *x, int *len);
int								change_to_ten(t_tab *x, int *len);
void							p_chan_x(t_tab *x);
void							prec_put_sign(t_tab *x, int prec, int *lenprec);
void							scp_convertion(t_tab *x, int *prec);
void							swaperino(char *a, char *b);
void							make_everything_null(t_tab *x);
int								dollar_numbers(t_tab *x, int co, int flag);
void							clean_tabs(t_tab *x);
int								ft_atoi(const char *str);
void							ft_putchar(char c);
size_t							ft_strlen(const char *str);
int								ft_putstr(char const *s);
void							ft_strdel(char **as);
void							*ft_memset(void *destination, int c, size_t n);
char							*ft_strnew(size_t size);
char							*ft_strsub(char const *s,
		unsigned int start, size_t len);
char							*ft_strjoin(char const *s1, char const *s2);
void							*ft_memalloc(size_t size);
char							*ft_itoa(int n);

#endif
