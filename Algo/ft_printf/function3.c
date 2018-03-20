/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 20:18:00 by flemaist          #+#    #+#             */
/*   Updated: 2014/10/26 20:18:01 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_utotal_len(unsigned long long int n, int baselen, t_opt opt)
{
	int		i;

	if (n == 0 && opt.prc == 0)
		return (0);
	i = ft_nbrlen_base(n, baselen);
	if (i < opt.prc)
		i = opt.prc;
	if (opt.flg & FLAG_DSH && n != 0)
		i += (baselen == 8 ? 1 : 2);
	if (opt.prc == 0 && !(opt.flg & FLAG_MIN) && i < opt.wdt
			&& opt.flg & FLAG_ZRO)
		i = opt.wdt;
	return (i);
}

char		*ft_uint_to_base(unsigned long long int n, char *base, t_opt opt)
{
	int		i;
	char	*str;
	int		baselen;

	baselen = ft_strlen(base);
	i = ft_utotal_len(n, baselen, opt);
	if (!(str = (char *)malloc(sizeof(char) * i)))
		return (NULL);
	str[i] = 0;
	while (n != 0 && i > 0)
	{
		str[--i] = base[n % baselen];
		n /= baselen;
	}
	while (i > 0)
		str[--i] = base[0];
	return (str);
}

int			pf_spc_char(va_list list, t_opt opt)
{
	char	c;
	int		ret;

	c = va_arg(list, int);
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

int			pf_spc_str(va_list list, t_opt opt)
{
	char	*s;
	int		ret;
	int		i;

	s = va_arg(list, char *);
	if (s == NULL)
		s = "(null)";
	ret = 0;
	i = ((opt.prc != -1337 && opt.prc < ft_strlen(s)) ? opt.prc : ft_strlen(s));
	if (!(opt.flg & FLAG_MIN))
		ret += ft_putnchar(' ', opt.wdt - i);
	ret += write(1, s, i);
	if (opt.flg & FLAG_MIN)
		ret += ft_putnchar(' ', opt.wdt - i);
	else
		ret += ft_putnchar(' ', (-opt.wdt) - i);
	return (ret);
}

int			pf_spc_ptr(va_list list, t_opt opt)
{
	void	*p;
	char	*str;
	int		ret;

	p = va_arg(list, void *);
	ret = 0;
	opt.flg |= FLAG_DSH;
	str = ft_uint_to_base((unsigned long long)p, "0123456789abcdef", opt);
	if (!(opt.flg & FLAG_MIN))
		ret += ft_putnchar(' ', opt.wdt - (ft_strlen(str)));
	ret += write(1, str, ft_strlen(str));
	if (opt.flg & FLAG_MIN)
		ret += ft_putnchar(' ', opt.wdt - (ft_strlen(str)));
	else
		ret += ft_putnchar(' ', (-opt.wdt) - (ft_strlen(str)));
	free(str);
	return (ret);
}
