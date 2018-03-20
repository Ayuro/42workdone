/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/16 18:04:13 by flemaist          #+#    #+#             */
/*   Updated: 2015/05/16 18:04:15 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static t_iny	ft_printf_fill_tab_fl(char ***tab_fl)
{
	if ((*tab_fl = (char **)malloc(sizeof(char **) * 20)) == NULL)
		return (RET_FAIL);
	(*tab_fl)[0] = "%c";
	(*tab_fl)[1] = "%s";
	(*tab_fl)[2] = "%d";
	(*tab_fl)[3] = "%i";
	(*tab_fl)[4] = "%u";
	(*tab_fl)[5] = "%b";
	(*tab_fl)[6] = "%B";
	(*tab_fl)[7] = "%o";
	(*tab_fl)[8] = "%x";
	(*tab_fl)[9] = "%X";
	(*tab_fl)[10] = "%p";
	(*tab_fl)[11] = "%P";
	(*tab_fl)[12] = "%ld";
	(*tab_fl)[13] = "%li";
	(*tab_fl)[14] = "%lu";
	(*tab_fl)[15] = "%lb";
	(*tab_fl)[16] = "%lB";
	(*tab_fl)[17] = "%lo";
	(*tab_fl)[18] = "%lx";
	(*tab_fl)[19] = "%lX";
	return (RET_OK);
}

static t_iny	ft_printf_fill_tab_fn(int (***tab_fn)(void *))
{
	(void)tab_fn;
	if ((*tab_fn = (int (**)(void *))malloc(sizeof(**tab_fn) * 20)) == NULL)
		return (RET_FAIL);
	(*tab_fn)[0] = &ft_printf_c;
	(*tab_fn)[1] = &ft_printf_s;
	(*tab_fn)[2] = &ft_printf_i;
	(*tab_fn)[3] = &ft_printf_i;
	(*tab_fn)[4] = &ft_printf_u;
	(*tab_fn)[5] = &ft_printf_b;
	(*tab_fn)[6] = &ft_printf_bu;
	(*tab_fn)[7] = &ft_printf_o;
	(*tab_fn)[8] = &ft_printf_x;
	(*tab_fn)[9] = &ft_printf_xu;
	(*tab_fn)[10] = &ft_printf_p;
	(*tab_fn)[11] = &ft_printf_pu;
	(*tab_fn)[12] = &ft_printf_li;
	(*tab_fn)[13] = &ft_printf_li;
	(*tab_fn)[14] = &ft_printf_lu;
	(*tab_fn)[15] = &ft_printf_lb;
	(*tab_fn)[16] = &ft_printf_lbu;
	(*tab_fn)[17] = &ft_printf_lo;
	(*tab_fn)[18] = &ft_printf_lx;
	(*tab_fn)[19] = &ft_printf_lxu;
	return (RET_OK);
}

static t_iny	ft_printf_flag(char *str, int *pos, int *ret, va_list *ap)
{
	static char		**tab_fl = NULL;
	static int		(**tab_fn)(void *) = NULL;
	int				i;

	if (tab_fl == NULL && ft_printf_fill_tab_fl(&tab_fl) == RET_FAIL)
		return (RET_FAIL);
	if (tab_fn == NULL && ft_printf_fill_tab_fn(&tab_fn) == RET_FAIL)
		return (RET_FAIL);
	if (strncmp(str + *pos, "%%", 2) == 0)
	{
		ft_putchar('%');
		*ret += 1;
		*pos += 2;
		return (RET_OK);
	}
	i = 0;
	while (!(strncmp(tab_fl[i], str + *pos, 2) == 0) && i < 12)
		i++;
	while (i >= 12 && !(strncmp(tab_fl[i], str + *pos, 3) == 0) && i < 20)
		i++;
	if (i >= 20)
		return (RET_FAIL);
	*ret += (*tab_fn[i])(va_arg(*ap, void *));
	*pos += (i < 12 ? 2 : 3);
	return (RET_OK);
}

static void		ft_printf_pure_str(char *str, int *pos, int *ret)
{
	int		len;
	char	*cstr;

	cstr = str + *pos;
	if (cstr[0] == '%')
		return ;
	len = ft_strchr(cstr, '%') - cstr;
	write(1, cstr, len);
	*pos += len;
	*ret += len;
}

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	int			pos;
	int			ret;

	pos = 0;
	ret = 0;
	va_start(ap, str);
	while (ft_strchr(str + pos, '%') != NULL)
	{
		ft_printf_pure_str((char *)str, &pos, &ret);
		if (ft_printf_flag((char *)str, &pos, &ret, &ap) == RET_FAIL)
			return (-1);
	}
	ft_putstr(str + pos);
	ret += ft_strlen(str) - pos;
	va_end(ap);
	return (ret);
}
