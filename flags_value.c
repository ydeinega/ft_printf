/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydeineha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 21:09:51 by ydeineha          #+#    #+#             */
/*   Updated: 2018/02/02 21:10:08 by ydeineha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		zero_flag(char *fmt)
{
	int i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '0')
		{
			if (i == 0 || (i > 0 && !ft_isdigit(fmt[i - 1])))
				return (1);
		}
		i++;
	}
	return (0);
}


int		width_value(char *fmt)
{
	int i;
	int	start;
	int	ret;

	i = 0;
	ret = 0;
	while (fmt[i])
	{
		if (fmt[i] == '.')
		{
			i++;
			while (ft_isdigit(fmt[i]))
				i++;
		}
		if (ft_isdigit(fmt[i]) && fmt[i] != '0')
		{
			start = i;
			while (ft_isdigit(fmt[i]))
				i++;
			ret = (fmt[i] != '$') ? ft_atoi(&fmt[start]) : ret;
		}
		else
			i = fmt[i] == '.' ? i : i + 1;
	}
	return (ret);
}

int		prc_value(char *fmt)
{
	int i;
	int	start;
	int ret;

	i = 0;
	ret = -1;
	while (fmt[i])
	{
		if (fmt[i] == '.')
		{
			i++;
			if (ft_isdigit(fmt[i]))
			{
				start = i;
				while (ft_isdigit(fmt[i]))
					i++;
				ret = fmt[i] != '$' ? ft_atoi(&fmt[start]) : 0;
			}
			else
				ret = 0;
		}
		else
			i++;
	}
	return (ret);
}

int		star_width(char *fmt)
{
	int i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '*' && (i == 0 || (i > 0 && fmt[i - 1] != '.')))
			return (1);
		i++;
	}
	return (0);
}

int		star_precision(char *fmt)
{
	int i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '*' && i > 0 && fmt[i - 1] == '.')
			return (1);
		i++;
	}
	return (0);
}
