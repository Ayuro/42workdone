/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flemaist <flemaist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 20:39:35 by flemaist          #+#    #+#             */
/*   Updated: 2014/10/26 20:39:39 by flemaist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_putnchar(char c, int n)
{
	int		ret;

	ret = 0;
	while (ret < n)
	{
		ret += write(1, &c, 1);
	}
	return (ret);
}

int			ft_strlen(char *str)
{
	char	*s;

	s = str;
	while (*s)
	{
		s++;
	}
	return (s - str);
}

int			ft_nbrlen_base(long long int n, int baselen)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		n /= baselen;
		i++;
	}
	return (i);
}

int			ft_atoi(const char *str)
{
	int		res;
	int		neg;

	res = 0;
	neg = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		neg = (*str++ == '-' ? -neg : neg);
	while ('0' <= *str && *str <= '9')
		res = res * 10 + ((*str++ - '0') * neg);
	return (res);
}
