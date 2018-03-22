/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:38:43 by ydeineha          #+#    #+#             */
/*   Updated: 2018/01/31 17:38:58 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_size	parse_modifiers(char *fmt, int b_type)
{
	t_size	mod;
	int		tmp;

	mod.s = specifier(fmt) == '0' ? (char)b_type : specifier(fmt);//переписать
	tmp = count_char(fmt, 'h');
	mod.hh = (tmp > 0 && tmp % 2 == 0) ? 1 : 0;
	mod.h = (tmp > 0 && tmp % 2 != 0) ? 1 : 0;
	tmp = count_char(fmt, 'l');
	mod.l = (tmp > 0 && tmp % 2 != 0) ? 1 : 0;
	mod.ll = (tmp > 0 && tmp % 2 == 0) ? 1 : 0;
	mod.j = ft_strchr(fmt, 'j') ? 1 : 0;
	mod.z = ft_strchr(fmt, 'z') ? 1 : 0;
	return (mod);
}

t_flags	parse_flags(char *fmt, va_list ap, va_list cp, int n)
{
	t_flags	flag;

	flag.dol = dollar_arg(fmt);
	flag.hash = ft_strchr(fmt, '#') ? 1 : 0;
	flag.zero = zero_flag(fmt);
	flag.minus = ft_strchr(fmt, '-') ? 1 : 0;
	flag.sp = ft_strchr(fmt, ' ') ? 1 : 0;
	flag.plus = ft_strchr(fmt, '+') ? 1 : 0;
	flag.ap = ft_strchr(fmt, '\'') ? 1 : 0;
	flag.width = width_value(fmt);
	flag.prc = prc_value(fmt);
	// flag.star_w = star_width(fmt);
	// flag.star_prc = star_precision(fmt);
	flag.dol_w = dollar_width(fmt);
	flag.dol_prc = dollar_precision(fmt);
	star(fmt, &flag, ap, cp);
	// if (flag.star_w)
	// 	flag.width = star_value_width(flag.dol_w, &flag.minus, ap, cp);
	// if (flag.star_prc)
	// 	flag.prc = star_value_precision(flag.dol_prc, ap, cp);
	//printf("width = %d\n", flag.width);//DEl
	//printf("prc = %d\n", flag.prc);//DEL
	flag.n = n;
	return (flag);
}

int		count_char(char *str, char c)
{
	int i;
	int n;

	i = 0;
	n = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			n++;
		i++;
	}
	return (n);
}

char	specifier(char *fmt)//переписать
{
	if (ft_strchr(fmt, 'd') || ft_strchr(fmt, 'i'))
		return ('d');
	else if (ft_strchr(fmt, 'o'))
		return ('o');
	else if (ft_strchr(fmt, 'u'))
		return ('u');
	else if (ft_strchr(fmt, 'x'))
		return ('x');
	else if (ft_strchr(fmt, 'X'))
		return ('X');
	else if (ft_strchr(fmt, 'D'))
		return ('D');
	else if (ft_strchr(fmt, 'O'))
		return ('O');
	else if (ft_strchr(fmt, 'U'))
		return ('U');
	else if (ft_strchr(fmt, 'p'))
		return ('p');
	else if (ft_strchr(fmt, 'S'))
		return ('S');
	else if (ft_strchr(fmt, 's'))
		return ('s');
	else
		return (specifier_rest(fmt));
}

char	specifier_rest(char *fmt)
{
	if (ft_strchr(fmt, 'n'))
		return ('n');
	else if (ft_strchr(fmt, 'C'))
		return ('C');
	else if (ft_strchr(fmt, 'c'))
		return ('c');
	else if (ft_strchr(fmt, 'A'))
		return ('A');
	else if (ft_strchr(fmt, 'a'))
		return ('a');
	else if (ft_strchr(fmt, 'E'))
		return ('E');
	else if (ft_strchr(fmt, 'e'))
		return ('e');
	else if (ft_strchr(fmt, 'F'))
		return ('F');
	else if (ft_strchr(fmt, 'f'))
		return ('f');
	else if (ft_strchr(fmt, 'G'))
		return ('G');
	else if (ft_strchr(fmt, 'g'))
		return ('g');
	else
		return ('0');
}
