/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 20:18:47 by flemaist          #+#    #+#             */
/*   Updated: 2014/10/26 20:18:48 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				pf_flag(char *fmt, int i, t_opt *opt)
{
	int			ret;
	char		*flags;
	int			j;

	ret = i;
	flags = "-+ #0";
	opt->flg = 0;
	while (fmt[i] != 0)
	{
		j = 0;
		while (flags[j] && fmt[i] != flags[j])
			j++;
		if (flags[j] == 0)
			return (i - ret);
		else
			opt->flg |= 1 << j;
		i++;
	}
	return (i - ret);
}

int				pf_width(char *fmt, int i, t_opt *opt, va_list ap)
{
	int			ret;

	ret = i;
	opt->wdt = 0;
	if ('1' <= fmt[i] && fmt[i] <= '9')
	{
		opt->wdt = ft_atoi(fmt + i);
		i += ft_nbrlen_base(opt->wdt, 10);
	}
	if (fmt[i] == '*')
	{
		opt->wdt = va_arg(ap, int);
		i++;
		return (i - ret);
	}
	return (i - ret);
}

int				pf_precision(char *fmt, int i, t_opt *opt, va_list ap)
{
	int			ret;

	ret = i;
	opt->prc = -1337;
	if (fmt[i] == '.')
	{
		i++;
		opt->prc = 0;
		if ('0' <= fmt[i] && fmt[i] <= '9')
		{
			opt->prc = ft_atoi(fmt + i);
			i += ft_nbrlen_base(opt->prc, 10);
		}
		if (fmt[i] == '*')
		{
			opt->prc = va_arg(ap, int);
			i++;
			return (i - ret);
		}
	}
	return (i - ret);
}

int				pf_length(char *fmt, int i, t_opt *opt)
{
	int			ret;
	char		*lenghts;
	int			j;

	ret = i;
	lenghts = " hljztL";
	j = 1;
	while (lenghts[j])
	{
		if (fmt[i] == lenghts[j])
		{
			if (j <= 2 && fmt[i + 1] == lenghts[j])
				i++;
			i++;
			opt->len = j;
			return (i - ret);
		}
		j++;
	}
	opt->len = 0;
	return (i - ret);
}

int				pf_specifier(char *fmt, int i, t_opt *opt)
{
	int			ret;
	char		*specifiers;
	int			j;

	ret = i;
	specifiers = " diuboxXcsp";
	j = 1;
	while (specifiers[j])
	{
		if (fmt[i] == specifiers[j])
		{
			opt->spc = pf_spc_fn(j);
			i++;
			return (i - ret);
		}
		j++;
	}
	opt->spc = pf_spc_fn(0);
	opt->ch = fmt[i];
	i++;
	return (i - ret);
}
