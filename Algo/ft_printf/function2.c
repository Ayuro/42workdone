/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 20:17:54 by flemaist          #+#    #+#             */
/*   Updated: 2014/10/26 20:17:55 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int							pf_spc_uint(va_list list, t_opt opt)
{
	unsigned long long		u;
	char					*str;
	int						ret;

	u = va_arg(list, unsigned long long);
	ret = 0;
	str = ft_uint_to_base(u, "0123456789", opt);
	if (!(opt.flg & FLAG_MIN))
		ret += ft_putnchar(' ', opt.wdt - ft_strlen(str));
	ret += write(1, str, ft_strlen(str));
	if (opt.flg & FLAG_MIN)
		ret += ft_putnchar(' ', opt.wdt - ft_strlen(str));
	else
		ret += ft_putnchar(' ', (-opt.wdt) - ft_strlen(str));
	free(str);
	return (ret);
}

int							pf_spc_uint_bin(va_list list, t_opt opt)
{
	unsigned long long		b;
	char					*str;
	int						ret;

	b = va_arg(list, unsigned long long);
	ret = 0;
	str = ft_uint_to_base(b, "01", opt);
	if (!(opt.flg & FLAG_MIN))
		ret += ft_putnchar(' ', opt.wdt - ft_strlen(str));
	ret += write(1, str, ft_strlen(str));
	if (opt.flg & FLAG_MIN)
		ret += ft_putnchar(' ', opt.wdt - ft_strlen(str));
	else
		ret += ft_putnchar(' ', (-opt.wdt) - ft_strlen(str));
	free(str);
	return (ret);
}

int							pf_spc_uint_oct(va_list list, t_opt opt)
{
	unsigned long long		o;
	char					*str;
	int						ret;

	o = va_arg(list, unsigned long long);
	ret = 0;
	str = ft_uint_to_base(o, "01234567", opt);
	if (!(opt.flg & FLAG_MIN))
		ret += ft_putnchar(' ', opt.wdt - ft_strlen(str));
	ret += write(1, str, ft_strlen(str));
	if (opt.flg & FLAG_MIN)
		ret += ft_putnchar(' ', opt.wdt - ft_strlen(str));
	else
		ret += ft_putnchar(' ', (-opt.wdt) - ft_strlen(str));
	free(str);
	return (ret);
}

int							pf_spc_uint_hex(va_list list, t_opt opt)
{
	unsigned long long		x;
	char					*str;
	int						ret;

	x = va_arg(list, unsigned long long);
	ret = 0;
	str = ft_uint_to_base(x, "0123456789abcdef", opt);
	if (!(opt.flg & FLAG_MIN))
		ret += ft_putnchar(' ', opt.wdt - ft_strlen(str));
	ret += write(1, str, ft_strlen(str));
	if (opt.flg & FLAG_MIN)
		ret += ft_putnchar(' ', opt.wdt - ft_strlen(str));
	else
		ret += ft_putnchar(' ', (-opt.wdt) - ft_strlen(str));
	free(str);
	return (ret);
}

int							pf_spc_uint_hxx(va_list list, t_opt opt)
{
	unsigned long long		x;
	char					*str;
	int						ret;

	x = va_arg(list, unsigned long long);
	ret = 0;
	str = ft_uint_to_base(x, "0123456789ABCDEF", opt);
	if (!(opt.flg & FLAG_MIN))
		ret += ft_putnchar(' ', opt.wdt - ft_strlen(str));
	ret += write(1, str, ft_strlen(str));
	if (opt.flg & FLAG_MIN)
		ret += ft_putnchar(' ', opt.wdt - ft_strlen(str));
	else
		ret += ft_putnchar(' ', (-opt.wdt) - ft_strlen(str));
	free(str);
	return (ret);
}
