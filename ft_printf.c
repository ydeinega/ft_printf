/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:22:41 by ydeineha          #+#    #+#             */
/*   Updated: 2018/01/18 15:22:44 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h> //DEL

int		ft_printf(const char *format, ...)
{
	va_list ap;
	va_list cp;
	int		n;

	n = 0;
	va_start(ap, format);
	va_copy(cp, ap);
	n = print_format(format, n, ap, cp);
	va_end(ap);
	va_end(cp);
	return (n);
}

int		print_format(const char *format, int n, va_list ap, va_list cp)
{
	int		i;
	char	*s;
	char	*tmp;

	i = 0;
	s = ft_strdup(format);
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchar(s[i]);
			n++;
			i++;
		}
		else
		{
			tmp = s;
			s = &s[i];
			n = n + parsing(&s, n, ap, cp);
			i = 0;
			ft_strdel(&tmp);
		}
	}
	ft_strdel(&s);
	return (n);
}

/*
int		print_format(const char *format, int n, va_list ap, va_list cp)
{
	int		i;
	char	*s;
	char	*tmp;

	i = 0;
	s = ft_strdup(format);
	while (s[i])
	{
		if (s[i] != '%' || (s[i] == '%' && s[i + 1] == '%'))
		{
			ft_putchar(s[i]);
			n++;
			i = (s[i] == '%') ? i + 2 : i + 1;
		}
		else
		{
			tmp = s;
			s = &s[i];
			n = n + parsing(&s, n, ap, cp);
			i = 0;
			ft_strdel(&tmp);
		}
	}
	ft_strdel(&s);
	return (n);
}
*/

int		parsing(char **str, int n, va_list ap, va_list cp)
{
	char	*fmt;
	int		b_type;
	int		ret;
	t_size	mod;
	t_flags flag;

	ret = 0;
	fmt = NULL;
	b_type = extract_fmt(str, &fmt);
	//printf("%s\n", fmt);//DEL
	if (fmt)
	{
		mod = parse_modifiers(fmt);
		flag = parse_flags(fmt, ap, cp, n);
		ft_strdel(&fmt);
	}
	if (b_type == 1)
		ret = arg_num(mod, flag, ap, cp);
	if (b_type == 2)
		arg_ptr(mod, flag, ap, cp);
	if (b_type == 3)
		ret = arg_char(mod, flag, ap, cp);
	if (b_type == 4)
		ret = arg_per_cent(flag, mod);
	return (ret);
}

int		extract_fmt(char **str, char **fmt)
{
	int		i;
	int		ret;
	char	*s;

	i = 1;
	ret = 0;
	if (!str || !fmt)
		return (-1);
	s = *str;
	while (s[i] && (ret = basic_type(s[i])) == 0)
		i++;
	if (ret == -1)
		*str = ft_strdup(&s[i]);
	else
	{
		*fmt = ft_strsub(s, 1, i);
		*str = ft_strdup(&s[i + 1]);
	}
	return (ret);
}

int		basic_type(char c)
{
	if (ft_strchr(FLAGS, c))
		return (0);
	else if (ft_strchr(TYPE_INT, c))
		return (1);
	else if (ft_strchr(TYPE_PTR, c))
		return (2);
	else if (ft_strchr(TYPE_CHR, c))
		return (3);
	else if (ft_strchr(TYPE_PER_CENT, c))
		return (4);
	else if (ft_strchr(TYPE_DBL, c))
		return (5);
	else
		return (-1);
}
