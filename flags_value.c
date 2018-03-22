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

//new
int		star(char *fmt, t_flags *flag, va_list ap, va_list cp)
{
	int		i;
	int		tmp;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '*' && (i == 0 || (i > 0 && fmt[i - 1] != '.')))
		{
			tmp = star_value_width(flag->dol_w, &flag->minus, ap, cp);
			if (!width_value(&fmt[i]))
				flag->width = tmp;
		}
		if (fmt[i] == '*' && i > 0 && fmt[i - 1] == '.')
		{
			tmp = star_value_precision(flag->dol_prc, ap, cp);
			if (prc_value(&fmt[i]) == -1)
				flag->prc = tmp;
		}
		i++;
	}
	//printf("width = %d\n", flag->width);//DEl
	//printf("prc = %d\n", flag->prc);//DEL
	return (0);
}

/*
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
*/
