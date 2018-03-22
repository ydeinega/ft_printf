/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_per_cent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 18:19:49 by ydeineha          #+#    #+#             */
/*   Updated: 2018/03/17 18:19:52 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		arg_per_cent(t_flags flag, t_size mod, int c)//переименовать ф-ию и файл
{
	char	*str;
	int		n;

	str = ft_strnew(1);
	n = 0;
	if (!str)
		return (0);
	str[0] = (char)c;
	if (flag.width)
		width_num(&str, flag, mod);
	if (!str)
		return (0);
	n = ft_strlen(str);
	write(1, str, n);
	ft_strdel(&str);
	return (n);
}

/*
int		arg_per_cent(t_flags flag, t_size mod)
{
	char	*str;
	int		n;

	str = ft_strdup("%");
	n = 0;
	if (!str)
		return (0);
	if (flag.width)
		width_num(&str, flag, mod);
	if (!str)
		return (0);
	n = ft_strlen(str);
	write(1, str, n);
	ft_strdel(&str);
	return (n);
}
*/
