/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 20:01:13 by ydeineha          #+#    #+#             */
/*   Updated: 2018/02/04 20:01:16 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		star_value(int dollar, va_list ap, va_list cp)
{
	va_list tmp;
	int		i;
	int		value;

	va_copy(tmp, cp);
	i = 0;
	value = 0;
	if (dollar > 0)
	{
		while (i < dollar)
		{
			value = va_arg(tmp, int);
			i++;
		}
	}
	else
		value = va_arg(ap, int);
	va_end(tmp);
	return (value);
}

int		star_value_width(int dollar, int *minus, va_list ap, va_list cp)
{
	int width;

	width = star_value(dollar, ap, cp);
	if (width < 0)
	{
		*minus = 1;
		width = -width;
	}
	return (width);
}

int		star_value_precision(int dollar, va_list ap, va_list cp)
{
	int prc;

	prc = star_value(dollar, ap, cp);
	if (prc < 0)
		prc = -1;
	return (prc);
}
