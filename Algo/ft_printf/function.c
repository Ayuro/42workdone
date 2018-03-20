/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 20:17:42 by flemaist          #+#    #+#             */
/*   Updated: 2014/10/26 20:17:43 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

fn_spc				pf_spc_fn(int i)
{
	fn_spc			tab[11];

	tab[0] = pf_spc_nop;
	tab[1] = pf_spc_int;
	tab[2] = pf_spc_int;
	tab[3] = pf_spc_uint;
	tab[4] = pf_spc_uint_bin;
	tab[5] = pf_spc_uint_oct;
	tab[6] = pf_spc_uint_hex;
	tab[7] = pf_spc_uint_hxx;
	tab[8] = pf_spc_char;
	tab[9] = pf_spc_str;
	tab[10] = pf_spc_ptr;
	return (tab[i]);
}

int					pf_spc_nop(va_list list, t_opt opt)
{
	char			c;
	int				ret;

	(void)list;
	c = opt.ch;
	ret = 0;
	if (!(opt.flg & FLAG_MIN))
		ret += ft_putnchar(' ', opt.wdt - 1);
	ret += write(1, &c, 1);
	if (opt.flg & FLAG_MIN)
		ret += ft_putnchar(' ', opt.wdt - 1);
	else
		ret += ft_putnchar(' ', (-opt.wdt) - 1);
	return (ret);
}

int					pf_spc_int(va_list list, t_opt opt)
{
	long long		i;
	char			*str;
	int				ret;

	if (opt.len < 3)
		i = va_arg(list, int);
	else
		i = va_arg(list, long long);
	ret = 0;
	str = ft_int_to_base(i, "0123456789", opt);
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

int					ft_total_len(long long int n, int baselen, t_opt opt)
{
	int				i;

	if (n == 0 && opt.prc == 0)
		return (0);
	i = ft_nbrlen_base(n, baselen);
	if (i <= opt.prc)
		i = (n < 0 ? opt.prc + 1 : opt.prc);
	if (opt.flg & 6 && n >= 0)
		i++;
	if (opt.flg & FLAG_DSH && n != 0)
		i += 2;
	if (opt.prc == 0 && !(opt.flg & FLAG_MIN) && i < opt.wdt
			&& opt.flg & FLAG_ZRO)
		i = opt.wdt;
	return (i);
}

char				*ft_int_to_base(long long int n, char *base, t_opt opt)
{
	int				i;
	int				sign;
	char			*str;
	int				baselen;

	sign = ((n < 0) ? -1 : 1);
	baselen = ft_strlen(base);
	i = ft_total_len(n, baselen, opt);
	if (!(str = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	str[i] = 0;
	while (n != 0 && i > 0)
	{
		str[--i] = base[(n % (baselen * sign)) * sign];
		n /= baselen;
	}
	while (i > 0)
		str[--i] = base[0];
	if (sign > 0 && opt.flg & 6)
		str[i++] = (opt.flg & FLAG_PLU ? '+' : ' ');
	else if (sign < 0)
		str[i++] = '-';
	if ((opt.flg & FLAG_DSH) && n != 0 && baselen == 16)
		str[i] = 'x';
	return (str);
}
