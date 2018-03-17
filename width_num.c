/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 21:01:02 by ydeineha          #+#    #+#             */
/*   Updated: 2018/03/16 21:01:04 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	width_num(char **str, t_flags flag, t_size mod)
{
	char	*s;
	int		len;

	s = *str;
	len = ft_strlen(s);
	if (flag.width > len)
	{
		*str = minus_zero_num(s, len, flag, mod);
		ft_strdel(&s);
	}
}

char	*minus_zero_num(char *str, int len, t_flags flag, t_size mod)
{
	char	*s_new;

	s_new = ft_strnew(flag.width);
	if (!s_new)
		return (NULL);
	if (flag.minus)
	{
		s_new = ft_strcpy(s_new, str);
		while (len < flag.width)
		{
			s_new[len] = ' ';
			len++;
		}
	}
	else
	{
		if ((flag.zero && flag.prc == -1 && ft_strchr(TYPE_INT, mod.s)) ||
			(flag.zero && ft_strchr(TYPE_CHR, mod.s)))
			s_new = ft_memset(s_new, '0', flag.width - len);
		else
			s_new = ft_memset(s_new, ' ', flag.width - len);
		ft_strcpy(&s_new[flag.width - len], str);
	}
	return (s_new);
}
