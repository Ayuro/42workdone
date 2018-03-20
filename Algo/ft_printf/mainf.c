/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 20:38:55 by flemaist          #+#    #+#             */
/*   Updated: 2014/10/26 20:39:00 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		pf_parser(char **ptr, va_list ap)
{
	char	*fmt;
	t_opt	opt;
	int		i;

	fmt = *ptr;
	i = 1;
	i += pf_flag(fmt, i, &opt);
	i += pf_width(fmt, i, &opt, ap);
	i += pf_precision(fmt, i, &opt, ap);
	i += pf_length(fmt, i, &opt);
	i += pf_specifier(fmt, i, &opt);
	*ptr = fmt + i - 1;
	i = opt.spc(ap, opt);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	char	*fmt;

	fmt = (char *)format;
	va_start(ap, format);
	i = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			i += pf_parser(&fmt, ap);
		else
			i += write(1, fmt, 1);
		fmt++;
	}
	va_end(ap);
	return (i);
}
