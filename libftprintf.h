/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:25:25 by ydeineha          #+#    #+#             */
/*   Updated: 2018/01/18 15:25:30 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <locale.h>
# include <wchar.h>
# include "./libft/libft.h"
# define FLAGS "0123456789#+- '.$*hljzL"
# define TYPE_INT "diouxXDOUp"
# define TYPE_PTR "n"
# define TYPE_CHR "cCsS"
# define TYPE_DBL "aAeEfFgG"

typedef struct		s_m
{
	char	s;
	int		hh;
	int		h;
	int		ll;
	int		l;
	int		j;
	int		z;
}					t_size;

typedef struct		s_f
{
	int		dol;
	int		hash;
	int		zero;
	int		minus;
	int		sp;
	int		plus;
	int		ap;
	int		width;
	int		prc;
	int		star_w;//
	int		star_prc;//
	int		dol_w;
	int		dol_prc;
	int		n;
}					t_flags;

int					ft_printf(const char *format, ...);
int					print_format(const char *format, int n, va_list ap,
					va_list cp);
int					parsing(char **str, int n, va_list ap, va_list cp);
int					extract_fmt(char **str, char **fmt);
int					basic_type(char c);
int					arg_num(t_size mod, t_flags flag, va_list ap, va_list cp);
t_size				parse_modifiers(char *fmt, int b_type);
t_flags				parse_flags(char *fmt, va_list ap, va_list cp, int n);
int					count_char(char *str, char c);
int					dollar_arg(char *fmt);
int					dollar_width(char *fmt);
int					dollar_precision(char *fmt);
int					dollar_value(char *str);
int					zero_flag(char *fmt);
int					width_value(char *fmt);
int					prc_value(char *fmt);
int					star_width(char *fmt);//del
int					star_precision(char *fmt);//del
int					star_value(int dollar, va_list ap, va_list cp);//del
int					star_value_width(int dollar, int *minus, va_list ap,
					va_list cp);
int					star_value_precision(int dollar, va_list ap, va_list cp);
char				specifier(char *fmt);
char				specifier_rest(char *fmt);
int					arg_num(t_size mod, t_flags flag, va_list ap, va_list cp);
long long			arg_sg(t_size mod, int	dollar, va_list ap, va_list cp);
long long			conv_sg_dol(t_size mod, int dollar, va_list cp);
long long			conv_sg(t_size mod, va_list ap);
unsigned long long	arg_un(t_size mod, int dollar, va_list ap, va_list cp);
unsigned long long	conv_un(t_size mod, va_list ap);
unsigned long long	conv_un_dol(t_size mod, int dollar, va_list cp);
char				*make_str_num(t_size mod, t_flags flag, long long num);
char				*make_str_unum(t_size mod, t_flags flag,
					unsigned long long num);
char				*itoa_base(unsigned long long num, unsigned long long base);
int					count_digits(unsigned long long num,
					unsigned long long base);
char				make_char(unsigned long long num);
void				apostrophe(char **str, int n);
int					count_sep(unsigned long long num);
char				*str_ap(char *s, char sep, int n);
unsigned long long	u_num(long long num);
void				precision_num(char **str, int prc, unsigned long long num);
void				sign_num(char **str, int sign, t_flags flag);
void				width_num(char **str, t_flags flag, t_size mod);
char				*minus_zero_num(char *str, int len, t_flags flag,
					t_size mod);
void				minus_num(char **str, t_flags flag);
void				sp_num(char **str, t_flags flag);
void				plus_num(char **str, t_flags flag);
void				hash_num(char **str, t_size mod, t_flags flag);
void				make_toupper(char **str);
void				arg_ptr(t_size mod, t_flags flag, va_list ap, va_list cp);
long long			*arg_n(t_size mod, int dollar, va_list ap, va_list cp);
long long			*conv_n_dol(t_size mod, int dollar, va_list cp);
long long			*conv_n(t_size mod, va_list ap);
int					arg_char(t_size mod, t_flags flag, va_list ap, va_list cp);
char				*conv_char(t_size mod, int dollar, va_list ap, va_list cp);
char				*conv_chr_dol(t_size mod, int dollar, va_list cp);
char				*conv_chr(t_size mod, va_list ap);
char				*make_str_wchr(wchar_t *w, t_size mod);
char				*ft_unicode(wchar_t c, char **str);
void				precision_chr(char **str, int prc);
char				*ft_strjoin_leaks(char **s1, char **s2);
int					nonvalid(t_flags flag, t_size mod, int c);
int					star(char *fmt, t_flags *flag, va_list ap, va_list cp);
char				*conv_chr_c(t_size mod, va_list ap);
char				*conv_chr_s(t_size mod, va_list ap);

#endif
