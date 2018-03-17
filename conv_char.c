/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:30:32 by ydeineha          #+#    #+#             */
/*   Updated: 2018/03/16 18:30:35 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*conv_char(t_size mod, int dollar, va_list ap, va_list cp)
{
	char	*s;

	s = NULL;
	if (dollar)
		s = conv_chr_dol(mod, dollar, cp);
	else
		s = conv_chr(mod, ap);
	return (s);
}

char	*conv_chr_dol(t_size mod, int dollar, va_list cp)
{
	char	*s;
	int		i;
	va_list	tmp;

	s = NULL;
	i = 0;
	va_copy(tmp, cp);
	while (i < dollar)
	{
		s = conv_chr(mod, tmp);
		i++;
	}
	va_end(tmp);
	return (s);
}

char	*conv_chr(t_size mod, va_list ap)
{
	char	*s;
	wchar_t	*w;
	wchar_t	c;

	s = NULL;
	w = NULL;
	if (mod.s == 'C' || (mod.s == 'c' && mod.l))
	{
		c = (wchar_t)va_arg(ap, wint_t);
		w = &c;
	}
	else if (mod.s == 'c')
	{
		s = ft_strnew(1);
		s[0] = (char)va_arg(ap, int);
	}
	if (mod.s == 'S' || (mod.s == 's' && mod.l))
		w = va_arg(ap, wchar_t *);
	else if (mod.s == 's')
		s = ft_strdup(va_arg(ap, char *));
	if (w && !s)
		s = make_str_wchr(w, mod);
	return (s);
}

char	*make_str_wchr(wchar_t *w, t_size mod)
{
	char	*str;
	char	*tmp;
	int		i;

	str = NULL;
	i = 0;
	if (mod.s == 'C' || mod.s == 'c')
		str = ft_unicode(*w);
	else
	{
		while (w[i])
		{
			if (!str)
				str = ft_unicode(w[i]);
			else
			{
				tmp = ft_unicode(w[i]);
				str = ft_strjoin_leaks(&str, &tmp);
			}
			i++;
		}
	}
	return (str);
}

char	*ft_unicode(wchar_t c)
{
	char	*s;

	s = ft_strnew(5);
	if (c < (1 << 7))
		s[0] = (char)c;
	else if (c < (1 << 11))
	{
		s[0] = (char)(192 | (c >> 6));
		s[1] = (char)(128 | (c & 63));
	}
	else if (c < (1 << 16))
	{
		s[0] = (char)(224 | (c >> 12));
		s[1] = (char)(128 | ((c >> 6) & 63));
		s[2] = (char)(128 | ((c & 63)));
	}
	else
	{
		s[0] = (char)(240 | (c >> 18));
		s[1] = (char)(128 | ((c >> 12) & 63));
		s[2] = (char)(128 | ((c >> 6) & 63));
		s[3] = (char)(128 | (c & 63));
	}
	return (s);
}